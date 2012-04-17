#include "Map.h"
#include "maths.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

// Ctors
Map::Map(void)
	: myNbTiles(0),
	myNbTilesX(0),
	myNbTilesY(0),
	myOffsetX(0),
	myOffsetY(0),
	myVertexArray(sf::Quads),
	myHasTileset(false),
	myHasMusic(false),
	myTilesetPath("none"),
	myMusicBckgPath("none"),
	myAllMapIsInVertexArray(false)
{
	myRenderStates.Texture = new sf::Texture;
}
Map::Map(const std::string& pathOfTileset)
	: myNbTiles(0),
	myNbTilesX(0),
	myNbTilesY(0),
	myOffsetX(0),
	myOffsetY(0),
	myVertexArray(sf::Quads),
	myHasTileset(false),
	myHasMusic(true),
	myTilesetPath("none"),
	myMusicBckgPath("none"),
	myAllMapIsInVertexArray(false)
{
	SetTileset(pathOfTileset);
}

// Dtor
Map::~Map(void)
{
}

bool Map::SetTileset(const std::string& path)
{
	myHasTileset = false;

	// Charge l'image
	if (!myTileset.LoadFromFile(path))
		return true;
	myTilesetPath = path;
	myNbTiles = (myTileset.GetWidth() / TILE_WIDTH) * (myTileset.GetHeight() / TILE_HEIGHT);

	// Crée l'index des tiles
	unsigned int x = 0, y = 0;
	for (unsigned int i = 0; i < myNbTiles; ++i)
	{
		myTiles.push_back(Tile(x, y, 0, -1));

		x += TILE_WIDTH;
		if (x > myTileset.GetWidth() - TILE_WIDTH)
		{
			x = 0;
			y += TILE_HEIGHT;
		}
	}

	// Change le RenderStates
	myRenderStates.Texture = &myTileset;

	myHasTileset = true;
	return false;
}

bool Map::SetMusicBckg(const std::string& path)
{
	myHasMusic = false;

	// Charge la musique
	if (!myMusicBckg.OpenFromFile(path))
		return true;
	myMusicBckgPath = path;

	myHasMusic = true;
	return false;
}

bool Map::Randomize(unsigned int nbTilesX, unsigned int nbTilesY)
{
	// Vérifie si le tileset est chargé
	if (!myHasTileset)
		return true;

	// Réinitialise les infos relatives à la map
	myNbTilesX = nbTilesX;
	myNbTilesY = nbTilesY;

	// Charge la map 1 aléatoirement
	myLayer1.resize(myNbTilesX);
	for (unsigned int x = 0; x < myNbTilesX; ++x)
		for (unsigned int y = 0; y < myNbTilesY; ++y)
			myLayer1[x].push_back(Maths::randMinMax(0, myNbTiles-1));

	// Charge la map 2 aléatoirement
	myLayer2.resize(myNbTilesX);
	for (unsigned int x = 0; x < myNbTilesX; ++x)
		for (unsigned int y = 0; y < myNbTilesY; ++y)
			myLayer2[x].push_back(-1);

	// Charge la map 3 aléatoirement
	myLayer3.resize(myNbTilesX);
	for (unsigned int x = 0; x < myNbTilesX; ++x)
		for (unsigned int y = 0; y < myNbTilesY; ++y)
			myLayer3[x].push_back(-1);

	// La map a été changée
	myAllMapIsInVertexArray = false;

	return false;
}

bool Map::RebuildVertexArrayFromView(const sf::View& view)
{
	// Si la map est invalide
	if (myNbTilesX == 0 || myNbTilesY == 0 || !myHasTileset)
		return true;

	// Ce n'est plus vrai
	myAllMapIsInVertexArray = false;

	// Affiche chaque tile dans la vue
	myVertexArray.Clear();
	for (int x = (view.GetCenter().x - view.GetSize().x/2) / TILE_WIDTH; x < ((view.GetCenter().x - view.GetSize().x/2) + view.GetSize().x) / TILE_WIDTH + 1; ++x)
		for (int y = (view.GetCenter().y - view.GetSize().y/2) / TILE_HEIGHT; y < ((view.GetCenter().y - view.GetSize().y/2) + view.GetSize().y) / TILE_HEIGHT + 1; ++y)
			if (x >= 0 && x < myNbTilesX && y >= 0 && y < myNbTilesY)
			{
				// Calque 1
				if (myLayer1[x][y] >= 0)
					this->AddTile(sf::Vector2i(x, y), myTiles[myLayer1[x][y]]);
				
				// Calque 2
				if (myLayer2[x][y] >= 0)
					this->AddTile(sf::Vector2i(x, y), myTiles[myLayer2[x][y]]);
				
				// Calque 3
				if (myLayer3[x][y] >= 0)
					this->AddTile(sf::Vector2i(x, y), myTiles[myLayer3[x][y]]);
			}

	return false;
}

bool Map::RebuildAllVertexArray()
{
	// Si la map est invalide
	if (myNbTilesX == 0 || myNbTilesY == 0 || !myHasTileset)
		return true;

	// Il ne faut pas recontruire le VertexArray avec toutes les tiles si c'est déjà fait
	if (!myAllMapIsInVertexArray)
	{
		// Affiche chaque tile
		myVertexArray.Clear();
		for (unsigned int x = 0; x < myNbTilesX; ++x)
			for (unsigned int y = 0; y < myNbTilesY; ++y)
			{
				// Calque 1
				if (myLayer1[x][y] >= 0)
					this->AddTile(sf::Vector2i(x, y), myTiles[myLayer1[x][y]]);
				
				// Calque 2
				if (myLayer2[x][y] >= 0)
					this->AddTile(sf::Vector2i(x, y), myTiles[myLayer2[x][y]]);
				
				// Calque 3
				if (myLayer3[x][y] >= 0)
					this->AddTile(sf::Vector2i(x, y), myTiles[myLayer3[x][y]]);
			}
	}

	return false;
}

bool Map::DrawIn(sf::RenderTarget* target)
{
	// Vérifie que le tileset soit bon
	if (!myHasTileset)
	{
		//std::cerr << "Failed to draw the map: no tileset found!" << std::endl;
		return true;
	}

	// Si le VertexArray n'est plus à jour
	if (!myAllMapIsInVertexArray)
		RebuildAllVertexArray();

	// Affiche la map
	target->Draw(myVertexArray, myRenderStates);

	return false;
}
bool Map::DrawIn(sf::RenderTarget* target, const sf::View& view)
{
	// Vérifie que le tileset soit bon
	if (!myHasTileset)
	{
		//std::cerr << "Failed to draw the map: no tileset found!" << std::endl;
		return true;
	}

	// Remplie le VertexArray avec les tiles dans la vue
	this->RebuildVertexArrayFromView(view);

	// Affiche la map
	target->Draw(myVertexArray, myRenderStates);
	return false;
}

bool Map::SaveInFile(const std::string& filename) const
{
	int choix = 0;
	std::cout << "Voullez-vous enregistrer avec :\n\t1. FILE - C en binaire ?\n\t2. fstream - C++ en non-binaire ?" << std::endl;
	std::cin >> choix;
	
	// Vérifie la map
	if (!myHasTileset)
		std::cerr << "Can't save in file because of bad tileset!" << std::endl;
	if (myNbTilesX == 0 || myNbTilesY == 0)
		std::cerr << "Can't save in file because of empty map!" << std::endl;
	if (!myHasMusic)
		std::cerr << "This map will be saved without music because of invalid or inexisting music!" << std::endl;

	if (!myHasTileset || myNbTilesX == 0 || myNbTilesY == 0)
		return true;

	if (choix == 1)
	{
		FILE *f;
		char buffer[256];

		fopen_s(&f, filename.c_str(), "wb");
		if (!f) return true;

		memset(&buffer, 0, sizeof(buffer));
		strcpy_s(buffer, "/documents/Examples/rpg/imgTileset.tns");//myTilesetPath.c_str());
		fwrite(&buffer, sizeof(char), 255, f);

		fwrite(&myNbTiles, sizeof(unsigned int), 1, f);
		fwrite(&myNbTilesX, sizeof(unsigned int), 1, f);
		fwrite(&myNbTilesY, sizeof(unsigned int), 1, f);
		fwrite(&myOffsetX, sizeof(unsigned int), 1, f);
		fwrite(&myOffsetY, sizeof(unsigned int), 1, f);

		for(unsigned int i = 0; i < myNbTiles; i++)
		{
			fwrite(&myTiles[i].x, sizeof(unsigned int), 1, f);
			fwrite(&myTiles[i].y, sizeof(unsigned int), 1, f);
			fwrite(&myTiles[i].collision, sizeof(unsigned char), 1, f);
			fwrite(&myTiles[i].nextTile, sizeof(int), 1, f);
		}

		for(unsigned int y = 0; y < myNbTilesY; y++)
			for(unsigned int x = 0; x < myNbTilesX; x++)
				fwrite(&myLayer1[x][y], sizeof(int), 1, f);
		fclose(f);
	}
	else
	{
		// Ouvre le fichier (et vide le fichier si il existe)
		std::ofstream file(filename, std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
		assert(file && "Map::SaveInFile(): Can't open file");

		// Enregistre les chemin de la musique et du tileset
		file << myMusicBckgPath << ' ' << myTilesetPath << ' ';

		// Enregistre les infos sur la map et le tileset
		file << myNbTiles << ' ' << myNbTilesX << ' ' << myNbTilesY << std::endl;

		// Enregistre les infos sur le tileset
		for(unsigned int i = 0; i < myTiles.size() ; ++i)
			file << myTiles[i].x << ' ' << myTiles[i].y << ' ' << myTiles[i].collision << ' ' << myTiles[i].nextTile << ' ';
		file << std::endl;

		// Enregistre la map (x et y sont inversés pour que la sauvegarde soit cohérente pour une édition manuelle)
		for (unsigned int y = 0; y < myNbTilesY; ++y)
		{
			for (unsigned int x = 0; x < myNbTilesX; ++x)
				file << myLayer1[x][y] << ' ';
			file << std::endl;
		}
	
		// Ferme le fichier
		file.close();
	}

	return false;
}

void Map::LoadFromFile(const std::string& filename)
{
	int choix = 0;
	std::cout << "Voullez-vous ouvrir avec :\n\t1. FILE - C en binaire ?\n\t2. fstream - C++ en non-binaire ?" << std::endl;
	std::cin >> choix;

	if (choix == 1)
	{
		FILE *f;
		char buffer[256];

		fopen_s(&f, filename.c_str(), "rb");
		if(!f) return;

		/* CHIPSET */
		memset(&buffer, 0, sizeof(buffer));
		fread(&buffer, sizeof(char), 255, f);
		myTilesetPath = "tiles/tileset.png";//buffer;
		SetTileset(myTilesetPath);

		fread(&myNbTiles, sizeof(unsigned int), 1, f);
		fread(&myNbTilesX, sizeof(unsigned int), 1, f);
		fread(&myNbTilesY, sizeof(unsigned int), 1, f);
		fread(&myOffsetX, sizeof(unsigned int), 1, f);
		fread(&myOffsetY, sizeof(unsigned int), 1, f);

		// Lit les infos sur le tileset
		myTiles.resize(myNbTiles);
		for(unsigned int i = 0; i < myNbTiles; ++i)
		{
			fread(&myTiles[i].x, sizeof(unsigned int), 1, f);
			fread(&myTiles[i].y, sizeof(unsigned int), 1, f);
			fread(&myTiles[i].collision, sizeof(unsigned char), 1, f);
			fread(&myTiles[i].nextTile, sizeof(int), 1, f);
		}

		// Lit et charge la map (x et y sont inversés pour que la sauvegarde soit cohérente pour une édition manuelle)
		/* Redimmentionne */
		myLayer1.resize(myNbTilesX);
		for (unsigned int x = 0; x < myNbTilesX; ++x)
			myLayer1[x].resize(myNbTilesY);
		myLayer2.resize(myNbTilesX);
		for (unsigned int x = 0; x < myNbTilesX; ++x)
			for (unsigned int y = 0; y < myNbTilesY; ++y)
				myLayer2[x].push_back(-1);
		myLayer3.resize(myNbTilesX);
		for (unsigned int x = 0; x < myNbTilesX; ++x)
			for (unsigned int y = 0; y < myNbTilesY; ++y)
				myLayer3[x].push_back(-1);

		/* Charge */
		for (unsigned int y = 0; y < myNbTilesY; ++y)
			for (unsigned int x = 0; x < myNbTilesX; ++x)
				fread(&myLayer1[x][y], sizeof(unsigned int), 1, f);

		fclose(f);
	}
	else
	{
		// Ouvre le fichier
		std::ifstream file(filename, std::ios::in);
		if (!file)
			std::cerr << "Invalid path! (\"" << filename << "\")" << std::endl;
		assert("Map::LoadFromFile() Can't open file" && file);

		// Lit les chemin de la musique et du tileset
		file >> myMusicBckgPath;
		file >> myTilesetPath;

		// Charge le tileset et la musique
		SetTileset(myTilesetPath);
		if (myMusicBckgPath != "none")
			SetMusicBckg(myMusicBckgPath);

		// Lit les infos sur la map et le tileset
		file >> myNbTiles >> myNbTilesX >> myNbTilesY;

		// Lit les infos sur le tileset
		myTiles.resize(myNbTiles);
		for(unsigned int i = 0; i < myNbTiles; ++i)
			file >> myTiles[i].x >> myTiles[i].y >> myTiles[i].collision >> myTiles[i].nextTile;

		// Lit et charge la map (x et y sont inversés pour que la sauvegarde soit cohérente pour une édition manuelle)
		/* Redimmentionne */
		myLayer1.resize(myNbTilesX);
		for (unsigned int x = 0; x < myNbTilesX; ++x)
			myLayer1[x].resize(myNbTilesY);
		myLayer2.resize(myNbTilesX);
		for (unsigned int x = 0; x < myNbTilesX; ++x)
			for (unsigned int y = 0; y < myNbTilesY; ++y)
				myLayer2[x].push_back(-1);
		myLayer3.resize(myNbTilesX);
		for (unsigned int x = 0; x < myNbTilesX; ++x)
			for (unsigned int y = 0; y < myNbTilesY; ++y)
				myLayer3[x].push_back(-1);
		/* Charge */
		for (unsigned int y = 0; y < myNbTilesY; ++y)
			for (unsigned int x = 0; x < myNbTilesX; ++x)
				file >> myLayer1[x][y];

		// Ferme le fichier
		file.close();
	}
	
	// Le VertexArray entier n'est plus à jour
	myAllMapIsInVertexArray = false;
}

void Map::AddTile(const sf::Vector2i& indexPos, const Tile& tile)
{
	// Le VertexArray entier n'est plus à jour
	//myAllMapIsInVertexArray = false; <- Pour optimiser la vitesse d'execution, c'est pas la peine

	/* Ajouter un tile revient à rajouter un sf::Quad dans le VertexArray */

	// Point en haut à gauche
	myVertexArray.Append(sf::Vertex(sf::Vector2f(static_cast<float>(indexPos.x * TILE_WIDTH), static_cast<float>(indexPos.y * TILE_HEIGHT)), 
		sf::Vector2f(static_cast<float>(tile.x), static_cast<float>(tile.y))));

	// Point en haut à droite
	myVertexArray.Append(sf::Vertex(sf::Vector2f(static_cast<float>(indexPos.x * TILE_WIDTH) + TILE_WIDTH, static_cast<float>(indexPos.y * TILE_HEIGHT)), 
		sf::Vector2f(static_cast<float>(tile.x + TILE_WIDTH), static_cast<float>(tile.y))));

	// Point en bas à droite
	myVertexArray.Append(sf::Vertex(sf::Vector2f(static_cast<float>(indexPos.x * TILE_WIDTH) + TILE_WIDTH, static_cast<float>(indexPos.y * TILE_HEIGHT) + TILE_HEIGHT), 
		sf::Vector2f(static_cast<float>(tile.x + TILE_WIDTH), static_cast<float>(tile.y + TILE_HEIGHT))));

	// Point en bas à gauche
	myVertexArray.Append(sf::Vertex(sf::Vector2f(static_cast<float>(indexPos.x * TILE_WIDTH), static_cast<float>(indexPos.y * TILE_HEIGHT) + TILE_HEIGHT), 
		sf::Vector2f(static_cast<float>(tile.x), static_cast<float>(tile.y + TILE_HEIGHT))));
}