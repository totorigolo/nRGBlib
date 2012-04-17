#include "MapEditor.h"
#include <iostream>

// Ctor
MapEditor::MapEditor(void)
	: myMapIsMine(false),
	myWindowIsMine(false)
{
	myMap = nullptr;
	myWindow = nullptr;
}
MapEditor::MapEditor(Map* map)
	: myMapIsMine(false),
	myWindowIsMine(false)
{
	myMap = nullptr;
	myWindow = nullptr;
	LoadMapFromMemory(map);
}
MapEditor::MapEditor(const std::string& path)
	: myMapIsMine(false),
	myWindowIsMine(false)
{
	myMap = nullptr;
	myWindow = nullptr;
	LoadMapFromFile(path);
}

// Dtor
MapEditor::~MapEditor(void)
{
	if (myMap && myMapIsMine) delete myMap;
	if (myWindow && myWindowIsMine) delete myWindow;
}

void MapEditor::Run(sf::RenderWindow* window)
{
	// Vérifie si une carte a été donné, et en crée une le cas échéant
	if (!myMap)
	{
		myMap = new Map;
		myMapIsMine = true;
	}

	// Crée la fenêtre
	bool windowCreated = false;
	if (!myWindow && !window)
	{
		myWindow = new sf::RenderWindow(sf::VideoMode(1024, 768), "RPG2D - Map Editor");
		myWindow->SetFramerateLimit(60);
		windowCreated = true;
		myWindowIsMine = true;
	}
	// Si une fenêtre a été donné, on change l'actuelle
	else if (window != myWindow)
	{
		SetWindow(window);
		myWindowIsMine = false;
	}

	// Sauvegardes des variables de la fenêtre
	sf::View lastView = myWindow->GetView();

	// Crée une vue pour la fenêtre
	sf::View windowView(myWindow->GetDefaultView());

	// Crée la vue de la map
	sf::View mapView(myWindow->GetDefaultView());
	mapView.SetViewport(sf::FloatRect(static_cast<float>(myMap->GetTileset().GetWidth() + 5.f /* Bordure */) / static_cast<float>(myWindow->GetWidth()), 0.f
		, 1 - (static_cast<float>(myMap->GetTileset().GetWidth()) / static_cast<float>(myWindow->GetWidth())), 1.f));
	mapView.SetSize(myWindow->GetWidth() * mapView.GetViewport().Width, myWindow->GetHeight() * mapView.GetViewport().Height);
	mapView.Move(myMap->GetOffsetX() * TILE_WIDTH, myMap->GetOffsetX() * TILE_HEIGHT);
	float currentSpeed = 300.f;
	float currentMapZoom = 1.f;

	// Variables pour le déplacement à la souris
	sf::Vector2i lastMousePos;

	// Crée un sprite pour le tileset
	sf::Sprite spriteTileset;
	spriteTileset.SetTexture(myMap->GetTileset());

	// Crée une vue pour le tileset
	sf::View tilesetView(myWindow->GetDefaultView());
	tilesetView.SetViewport(sf::FloatRect(0.f, 0.f, static_cast<float>(myMap->GetTileset().GetWidth()) / static_cast<float>(myWindow->GetWidth()), 1.f));
	tilesetView.SetSize(myWindow->GetWidth() * tilesetView.GetViewport().Width, myWindow->GetHeight() * tilesetView.GetViewport().Height);
	tilesetView.SetCenter(0 + tilesetView.GetSize().x / 2, 0 + tilesetView.GetSize().y / 2);

	// Crée la sélection
	/* Une tile pour le curseur */
	sf::Sprite cursor(myMap->GetTileset());
	cursor.SetTextureRect(sf::IntRect(0, 0, TILE_WIDTH, TILE_HEIGHT));
	/* Un rectangle translucide pour la sélection */
	sf::RectangleShape selection(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
	selection.SetFillColor(sf::Color(203, 57, 31, 150));
	/* Un rectangle translucide pour le tile survolé */
	sf::RectangleShape overflew(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
	overflew.SetFillColor(sf::Color(0, 0, 255, 150));
	/* L'index du tile selectionné */
	sf::Vector2i selectionIndex(0, 0);
	selection.SetPosition(selectionIndex.x * TILE_WIDTH, selectionIndex.y * TILE_HEIGHT);
	bool isCtrlPressed = false;
	bool isShiftPressed = false;
	bool justPressed = false;
	/* Le tile actuel */
	unsigned int currentSelectedTile = 0;
	/* Vérou pour le dessin sur la map */
	bool onMap = false;
	
	// Un horloge pour la vitesse
	sf::Clock clock;

	// Variables rapides pour la position de la souris (Mouse Position ****)
	sf::Vector2i mpW; // Relative à la fenêtre
	sf::Vector2i mpM; // Relative à la map
	sf::Vector2i mpT; // Relative au tileset
	bool overFlyingTileset = false;
	bool overFlyingMap = false;

	// Bouble principale
	bool stop = false;
	bool paused = false;
	while (myWindow->IsOpen() && !stop)
	{
		// Sauvegarde la position de la souris
		mpW = sf::Vector2i(sf::Mouse::GetPosition(*myWindow).x, sf::Mouse::GetPosition(*myWindow).y);
		mpM.x = myWindow->ConvertCoords(sf::Mouse::GetPosition(*myWindow).x, sf::Mouse::GetPosition(*myWindow).y, mapView).x;
		mpM.y = myWindow->ConvertCoords(sf::Mouse::GetPosition(*myWindow).x, sf::Mouse::GetPosition(*myWindow).y, mapView).y;
		mpT.x = myWindow->ConvertCoords(sf::Mouse::GetPosition(*myWindow).x, sf::Mouse::GetPosition(*myWindow).y, tilesetView).x;
		mpT.y = myWindow->ConvertCoords(sf::Mouse::GetPosition(*myWindow).x, sf::Mouse::GetPosition(*myWindow).y, tilesetView).y;
		overFlyingMap = false;
		overFlyingTileset = false;
		// Le tile survole le tileset
		if (mpT.x >= 0 && mpT.y >= 0 && mpT.x < myMap->GetTileset().GetWidth() && mpT.y < myMap->GetTileset().GetHeight())
		{
			overFlyingMap = false;
			overFlyingTileset = true;
		}
		// Le tile survole la map
		else if (mpM.x >= 0 && mpM.y >= 0 && mpM.x < myMap->GetWidth() && mpM.y < myMap->GetHeight())
		{
			overFlyingMap = true;
			overFlyingTileset = false;
		}

		// Gestion des évènements
		sf::Event event;
		while (myWindow->PollEvent(event))
		{
			// Fenêtre fermée, on ferme l'éditeur
			if (event.Type == sf::Event::Closed)
				stop = true;

			// On gère le redimentionnement
			if (event.Type == sf::Event::Resized)
			{
				windowView.Reset(sf::FloatRect(0.f, 0.f, myWindow->GetWidth(), myWindow->GetHeight()));

				mapView.SetViewport(sf::FloatRect(static_cast<float>(myMap->GetTileset().GetWidth() + 5.f /* Bordure */) / static_cast<float>(myWindow->GetWidth()), 0.f
					, 1 - (static_cast<float>(myMap->GetTileset().GetWidth()) / static_cast<float>(myWindow->GetWidth())), 1.f));
				mapView.SetSize(myWindow->GetWidth() * mapView.GetViewport().Width, myWindow->GetHeight() * mapView.GetViewport().Height);
				
				tilesetView.SetViewport(sf::FloatRect(0.f, 0.f, static_cast<float>(myMap->GetTileset().GetWidth()) / static_cast<float>(myWindow->GetWidth()), 1.f));
				tilesetView.SetSize(myWindow->GetWidth() * tilesetView.GetViewport().Width, myWindow->GetHeight() * tilesetView.GetViewport().Height);
			}

			// Gère le verrou de la souris sur la map
			if (event.Type == sf::Event::MouseButtonPressed)
				if (overFlyingMap)
					onMap = true;
			if (event.Type == sf::Event::MouseButtonReleased)
				onMap = false;

			// Gère le focus
			if (event.Type == sf::Event::LostFocus)
				paused = true;
			else if (event.Type == sf::Event::GainedFocus)
				paused = false;
			if (event.Type == sf::Event::MouseLeft)// && !onMap) <- Pour peindre en dehors de la fenêtre
				paused = true;
			else if (event.Type == sf::Event::MouseEntered)
				paused = false;

			if (!paused)
			{
				// Echap, on ferme l'éditeur
				if (event.Type == sf::Event::KeyReleased && event.Key.Code == sf::Keyboard::Escape)
					stop = true;

				// On gère la molette
				if (event.Type == sf::Event::MouseWheelMoved)
				{
					tilesetView.Move(0, event.MouseWheel.Delta * -10);
				}
			
				// L, on charge une map
				if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::L)
				{
					std::string path;
					std::cout << "What is the map name (relative to /map, without extension)? ";
					std::cin >> path;
					path = "map/" + path + ".map";
					this->LoadMapFromFile(path);
					cursor.SetTexture(myMap->GetTileset());
					spriteTileset.SetTexture(myMap->GetTileset());
					std::cout << "Map loaded!" << std::endl;
				}

				// S, on sauvegarde la map
				if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::S)
				{
					std::string path;
					std::cout << "What is this map name (relative to /map, without extension)? ";
					std::cin >> path;
					path = "map/" + path + ".map";
					this->SaveMapInFile(path);
					std::cout << "Map saved!" << std::endl;
				}

				// + ou - ou Numpad0, on change le zoom
				if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::Add)
				{
					currentMapZoom -= 0.2f;
					mapView.Zoom(0.8f);
				}
				if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::Subtract)
				{
					currentMapZoom += 0.2f;
					mapView.Zoom(1.2f);
				}
				if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::Numpad0)
				{
					currentMapZoom = 1.f;
					mapView.SetSize(myWindow->GetWidth() * mapView.GetViewport().Width, myWindow->GetHeight() * mapView.GetViewport().Height);
				}

				// Ctrl ou Shift, on retient qu'elles sont ou non appuyées
				if (event.Key.Code == sf::Keyboard::LControl || event.Key.Code == sf::Keyboard::RControl)
				{
					if (event.Type == sf::Event::KeyPressed)
						isCtrlPressed = true;
					else if (event.Type == sf::Event::KeyReleased)
						isCtrlPressed = false;
					justPressed = true;
				}
				if (event.Key.Code == sf::Keyboard::LShift || event.Key.Code == sf::Keyboard::RShift)
				{
					if (event.Type == sf::Event::KeyPressed)
						isShiftPressed = true;
					else if (event.Type == sf::Event::KeyReleased)
						isShiftPressed = false;
					justPressed = true;
				}

				// Gère le tile survolé
				if (event.Type == sf::Event::MouseMoved || justPressed)
				{
					justPressed = false;
					// Le tile survole le tileset
					if (overFlyingTileset)
					{
						overflew.SetPosition(static_cast<int>(mpT.x / TILE_WIDTH) * TILE_WIDTH, static_cast<int>(mpT.y / TILE_WIDTH) * TILE_WIDTH);
						overflew.SetSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
					}
					// Le tile survole la map
					else if (overFlyingMap)
					{
						// Touche Ctrl préssée, la selection occupe 3*3 tiles
						if (isCtrlPressed)
						{
							overflew.SetPosition(int((static_cast<int>(mpM.x / TILE_WIDTH) -1) * TILE_WIDTH), int((static_cast<int>(mpM.y / TILE_WIDTH) -1) * TILE_WIDTH));
							overflew.SetSize(sf::Vector2f(TILE_WIDTH * 3, TILE_HEIGHT * 3));
						}
						// Touche Shift préssée, la selection occupe 5*5 tiles
						if (isShiftPressed)
						{
							overflew.SetPosition(int((static_cast<int>(mpM.x / TILE_WIDTH) -2) * TILE_WIDTH), int((static_cast<int>(mpM.y / TILE_WIDTH) -2) * TILE_WIDTH));
							overflew.SetSize(sf::Vector2f(TILE_WIDTH * 5, TILE_HEIGHT * 5));
						}
						// Sinon, le selection occupe seulement le tile survollé
						if (!isCtrlPressed && !isShiftPressed)
						{
							overflew.SetPosition(int(static_cast<int>(mpM.x / TILE_WIDTH) * TILE_WIDTH), int(static_cast<int>(mpM.y / TILE_WIDTH) * TILE_WIDTH));
							overflew.SetSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
						}
					}
				}
			} // Fin de if (!paused)
		} // Fin du PollEvent()

		if (!paused)
		{
			// On gère le clic gauche
			if (sf::Mouse::IsButtonPressed(sf::Mouse::Left) || sf::Mouse::IsButtonPressed(sf::Mouse::Right))
			{
				// Sur la map
				if (!sf::Mouse::IsButtonPressed(sf::Mouse::Right) && overFlyingMap)
				{
					myMap->SetTileLayer1(mpM.x / TILE_WIDTH, mpM.y / TILE_HEIGHT, currentSelectedTile);
					
					// Touche Ctrl ou Alt préssée, on change les 8 tiles autour du tile actuel
					if (isCtrlPressed || isShiftPressed)
					{
						// En haut
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 1, (mpM.y / TILE_HEIGHT) + 1, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH), (mpM.y / TILE_HEIGHT) + 1, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 1, (mpM.y / TILE_HEIGHT) + 1, currentSelectedTile);
						// Côtés
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 1, (mpM.y / TILE_HEIGHT), currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 1, (mpM.y / TILE_HEIGHT), currentSelectedTile);
						// En bas
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 1, (mpM.y / TILE_HEIGHT) - 1, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH), (mpM.y / TILE_HEIGHT) - 1, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 1, (mpM.y / TILE_HEIGHT) - 1, currentSelectedTile);
					}
					// Touche Alt préssée, on change les 18 tiles autour du tile actuel
					if (isShiftPressed)
					{
						// En haut haut
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 2, (mpM.y / TILE_HEIGHT) + 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 1, (mpM.y / TILE_HEIGHT) + 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH), (mpM.y / TILE_HEIGHT) + 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 1, (mpM.y / TILE_HEIGHT) + 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 2, (mpM.y / TILE_HEIGHT) + 2, currentSelectedTile);
						// En haut milieu
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 2, (mpM.y / TILE_HEIGHT) + 1, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 2, (mpM.y / TILE_HEIGHT) + 1, currentSelectedTile);
						// Côtés
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 2, (mpM.y / TILE_HEIGHT), currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 2, (mpM.y / TILE_HEIGHT), currentSelectedTile);
						// En bas milieu
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 2, (mpM.y / TILE_HEIGHT) - 1, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 2, (mpM.y / TILE_HEIGHT) - 1, currentSelectedTile);
						// En bas bas
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 2, (mpM.y / TILE_HEIGHT) - 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) - 1, (mpM.y / TILE_HEIGHT) - 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH), (mpM.y / TILE_HEIGHT) - 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 1, (mpM.y / TILE_HEIGHT) - 2, currentSelectedTile);
						myMap->SetTileLayer1((mpM.x / TILE_WIDTH) + 2, (mpM.y / TILE_HEIGHT) - 2, currentSelectedTile);
					}
				}

				// Sur le tileset
				if (!onMap)
					if (overFlyingTileset)
					{
						selectionIndex.x = mpT.x / TILE_WIDTH;
						selectionIndex.y = mpT.y / TILE_HEIGHT;

						selection.SetPosition(selectionIndex.x * TILE_WIDTH, selectionIndex.y * TILE_HEIGHT);
						currentSelectedTile = (selectionIndex.y * myMap->GetTileset().GetWidth() / TILE_WIDTH) + selectionIndex.x;
						cursor.SetTextureRect(sf::IntRect(selectionIndex.x * TILE_WIDTH, selectionIndex.y * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT));
					}
			}
		
			// Gère la pipette (clic droit sur la map)
			if (sf::Mouse::IsButtonPressed(sf::Mouse::Right))
			{
				// On vérifie qu'on est bien sur la map
				if (overFlyingMap)
				{
					unsigned int x = mpM.x / TILE_WIDTH;
					unsigned int y = mpM.y / TILE_HEIGHT;
					if (x >= 0 && x < myMap->GetNbTilesX() && y >= 0 && y < myMap->GetNbTilesX())
						currentSelectedTile = myMap->GetTileLayer1(x, y);
				
					selectionIndex.x = myMap->GetTiles()[currentSelectedTile].x / TILE_WIDTH;
					selectionIndex.y = myMap->GetTiles()[currentSelectedTile].y / TILE_HEIGHT;
					selection.SetPosition(selectionIndex.x * TILE_WIDTH, selectionIndex.y * TILE_HEIGHT);
					cursor.SetTextureRect(sf::IntRect(selectionIndex.x * TILE_WIDTH, selectionIndex.y * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT));
				}
			}

			// Gère le déplacement à la souris (clic molette)
			if (sf::Mouse::IsButtonPressed(sf::Mouse::Middle))
			{
				// On vérifie qu'on est bien sur la map
				if (overFlyingMap)
					mapView.Move(- static_cast<float>(sf::Mouse::GetPosition().x - lastMousePos.x), - static_cast<float>(sf::Mouse::GetPosition().y - lastMousePos.y));
				// Sinon on vérifie si on est sur le tileset
				else if (!onMap)
					if (overFlyingTileset)
						tilesetView.Move(0, - static_cast<float>(sf::Mouse::GetPosition().y - lastMousePos.y));
			}

			// Sauvegarde la dernière position de la souris
			lastMousePos = sf::Mouse::GetPosition();

			// Déplace le curseur
			cursor.SetPosition(sf::Mouse::GetPosition(*myWindow).x + 5, sf::Mouse::GetPosition(*myWindow).y + 5);

			// Gère le déplacement avec les flèches
			if (sf::Keyboard::IsKeyPressed(sf::Keyboard::Up))
				mapView.Move(0.f, -currentSpeed * clock.GetElapsedTime().AsSeconds());
			if (sf::Keyboard::IsKeyPressed(sf::Keyboard::Down))
				mapView.Move(0.f, currentSpeed * clock.GetElapsedTime().AsSeconds());
			if (sf::Keyboard::IsKeyPressed(sf::Keyboard::Right))
				mapView.Move(currentSpeed * clock.GetElapsedTime().AsSeconds(), 0.f);
			if (sf::Keyboard::IsKeyPressed(sf::Keyboard::Left))
				mapView.Move(-currentSpeed * clock.GetElapsedTime().AsSeconds(), 0.f);
		} // Fin de if (!paused)

		// Réinitialise l'horloge
		clock.Restart();

		// Efface l'écran
		myWindow->Clear(sf::Color::Black);

		// Affiche la map
		myWindow->SetView(mapView);
		myMap->DrawIn(myWindow, mapView);
		if (overFlyingMap) window->Draw(overflew);

		// Affiche le tileset
		myWindow->SetView(tilesetView);
		myWindow->Draw(spriteTileset);
		myWindow->Draw(selection);
		if (overFlyingTileset) window->Draw(overflew);

		// Affiche le curseur
		myWindow->SetView(windowView);
		myWindow->Draw(cursor);

		// Met à jour la fenêtre
		myWindow->Display();
	}

	// Restore la vue initiale à la fenêtre
	if (windowCreated && myWindowIsMine)
	{
		delete myWindow;
		myWindow = nullptr;
	}
	else
		myWindow->SetView(lastView);
}

bool MapEditor::SetWindow(sf::RenderWindow* window)
{
	if (!window) return true;
	if (window) delete myWindow;
	myWindow = window;
	myWindowIsMine = true;
	return false;
}

bool MapEditor::SaveMapInFile(const std::string& path)
{
	// Demande l'offset de la map
	unsigned int tmp = 0;
	std::cout << "Entrez l'offset en X de la carte (0 si inconnue) : ";
	std::cin >> tmp;
	myMap->SetOffsetX(tmp);
	std::cout << "Entrez l'offset en Y de la carte (0 si inconnue) : ";
	std::cin >> tmp;
	myMap->SetOffsetY(tmp);

	return myMap->SaveInFile(path);
}

bool MapEditor::LoadMapFromMemory(Map* map)
{
	if (!map) return true;
	if (map) delete myMap;
	myMap = map;
	myMapIsMine = false;
	return false;
}
void MapEditor::LoadMapFromFile(const std::string& path)
{
	myMap = new Map;
	myMap->LoadFromFile(path);
	myMapIsMine = true;
}
