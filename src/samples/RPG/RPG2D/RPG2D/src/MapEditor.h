#pragma once
#include "Map.h"
#include <string>

class MapEditor
{
public:
	// Ctor
	MapEditor(void);
	MapEditor(Map* map);
	MapEditor(const std::string& path);

	// Dtor
	virtual ~MapEditor(void);

	// Lance l'éditeur de map
	//   - dans la fenêtre donnée, ou dans une nouvelle fenêtre si rien n'a été défini.
	//   - édite la carte donnée, ou une nouvelle si rien n'a été donné
	void Run(sf::RenderWindow* window = nullptr);

	// Définit la fenêtre
	bool SetWindow(sf::RenderWindow* window);

	// Sauvegarde la map dans un fichier
	bool SaveMapInFile(const std::string& path);

	// Change la map
	bool LoadMapFromMemory(Map* map);

	// Charge la map à partir d'un fichier
	void LoadMapFromFile(const std::string& path);

private:
	Map* myMap;
	bool myMapIsMine;
	sf::RenderWindow* myWindow;
	bool myWindowIsMine;
};

