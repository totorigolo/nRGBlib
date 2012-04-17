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

	// Lance l'�diteur de map
	//   - dans la fen�tre donn�e, ou dans une nouvelle fen�tre si rien n'a �t� d�fini.
	//   - �dite la carte donn�e, ou une nouvelle si rien n'a �t� donn�
	void Run(sf::RenderWindow* window = nullptr);

	// D�finit la fen�tre
	bool SetWindow(sf::RenderWindow* window);

	// Sauvegarde la map dans un fichier
	bool SaveMapInFile(const std::string& path);

	// Change la map
	bool LoadMapFromMemory(Map* map);

	// Charge la map � partir d'un fichier
	void LoadMapFromFile(const std::string& path);

private:
	Map* myMap;
	bool myMapIsMine;
	sf::RenderWindow* myWindow;
	bool myWindowIsMine;
};

