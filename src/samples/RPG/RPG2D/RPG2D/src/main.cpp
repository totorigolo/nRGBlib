#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MapEditor.h"
#include "Map.h"

int main()
{
	// Initialise l'aléatoire
	srand(static_cast<unsigned int>(time(nullptr)));

	// Crée la fenêtre
	sf::RenderWindow window(sf::VideoMode(1024, 768), "RPG2D");
	window.SetFramerateLimit(60);
	
	// Crée la vue de la map
	sf::View view(window.GetView());
	window.SetView(view);

	// Crée un texte
	sf::Text text("Appuyez sur \"1\" pour ouvrir l'éditeur de carte.");
	
	// Bouble principale
	while (window.IsOpen())
	{
		// Gestion des évènements
		sf::Event event;
		while (window.PollEvent(event))
		{
			// Fenêtre fermée ou touche Echap, on quite
			if (event.Type == sf::Event::Closed || (event.Type == sf::Event::KeyReleased && event.Key.Code == sf::Keyboard::Escape))
				window.Close();
			
			// On gère le redimentionnement
			if (event.Type == sf::Event::Resized)
			{
				view.Reset(sf::FloatRect(0, 0, window.GetWidth(), window.GetHeight()));
				window.SetView(view);
			}

			// 1 pour l'éditeur de carte
			if (event.Type == sf::Event::KeyReleased && (event.Key.Code == sf::Keyboard::Num1 || event.Key.Code == sf::Keyboard::Numpad1))
			{
				/*Map m("tiles/tileset.png");
				m.Randomize(50, 50);
				m.SaveInFile("map/bin.map");*/
				std::string path = "";
				std::cout << "What is the map name (relative to /map, without extension)? ";
				std::cin >> path;
				path = "map/" + path + ".map";
				MapEditor editor(path);
				editor.Run(&window);

				view.Reset(sf::FloatRect(0, 0, window.GetWidth(), window.GetHeight()));
			}
		}

		// Efface l'écran
		window.Clear(sf::Color::Black);

		// Affiche le texte
		window.Draw(text);

		// Met à jour la fenêtre
		window.Display();
	}

	return EXIT_SUCCESS;
}