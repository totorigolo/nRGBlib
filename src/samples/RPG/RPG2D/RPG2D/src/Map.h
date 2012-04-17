#pragma once
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

unsigned int const TILE_WIDTH = 32;
unsigned int const TILE_HEIGHT = 32;

class Map
{
public:
	Map(void);
	Map(const std::string& pathOfTileset);
	virtual ~Map(void);

	// Getters
	unsigned int GetNbTilesX() const { return myNbTilesX; }
	unsigned int GetNbTilesY() const { return myNbTilesY; }
	unsigned int GetOffsetX() const { return myOffsetX; }
	unsigned int GetOffsetY() const { return myOffsetY; }
	const sf::Texture& GetTileset() const { return myTileset; }
	unsigned int GetWidth() const { return myNbTilesX * TILE_WIDTH; }
	unsigned int GetHeight() const { return myNbTilesY * TILE_HEIGHT; }
	int GetTileLayer1(unsigned int x, unsigned int y) const { return (x >= 0 && x < myNbTilesX && y >= 0 && y < myNbTilesY) ? myLayer1[x][y] : 0; }
	int GetTileLayer2(unsigned int x, unsigned int y) const { return (x >= 0 && x < myNbTilesX && y >= 0 && y < myNbTilesY) ? myLayer2[x][y] : 0; }
	int GetTileLayer3(unsigned int x, unsigned int y) const { return (x >= 0 && x < myNbTilesX && y >= 0 && y < myNbTilesY) ? myLayer3[x][y] : 0; }
	const std::vector<Tile>& GetTiles() const { return myTiles; }

	// Setters
	void SetOffsetX(unsigned int ox) { myOffsetX = ox; }
	void SetOffsetY(unsigned int oy) { myOffsetY = oy; }
	void SetTilesetSmooth(bool smooth) { myTileset.SetSmooth(smooth); }
	void SetTileLayer1(unsigned x, unsigned int y, int tile) { if (x >= 0 && x < myNbTilesX && y >= 0 && y < myNbTilesY) myLayer1[x][y] = tile; myAllMapIsInVertexArray = false; }
	void SetTileLayer2(unsigned x, unsigned int y, int tile) { if (x >= 0 && x < myNbTilesX && y >= 0 && y < myNbTilesY) myLayer2[x][y] = tile; myAllMapIsInVertexArray = false; }
	void SetTileLayer3(unsigned x, unsigned int y, int tile) { if (x >= 0 && x < myNbTilesX && y >= 0 && y < myNbTilesY) myLayer3[x][y] = tile; myAllMapIsInVertexArray = false; }
	
	// Change le tileset
	bool SetTileset(const std::string& path);

	// Change la musique de fond
	bool SetMusicBckg(const std::string& path);

	// Crée une map aléatoire (retourne false si pas d'erreur)
	bool Randomize(unsigned int nbTilesX, unsigned int nbTilesY);

	// Redessine toute la RenderTexture (retourne false si pas d'erreur)
	bool RebuildAllVertexArray();

	// Dessine les tiles qui sont dans la vue dans le VertexArray 
	bool RebuildVertexArrayFromView(const sf::View& view);
	
	// Affiche la map ENTIERE dans un RenderTarget
	bool DrawIn(sf::RenderTarget* target);

	// Affiche la map dans un RenderTarget, mais uniquement les tiles dans la vue
	bool DrawIn(sf::RenderTarget* target, const sf::View& view);

	// Sauvegarde la map dans un fichier
	bool SaveInFile(const std::string& filename) const;

	// Charge la map à partir d'un fichier
	void LoadFromFile(const std::string& filename);

protected:
	// Ajoute une tile au VertexArray
	void Map::AddTile(const sf::Vector2i& indexPos, const Tile& tile);

private:
	/* VertexArray -> Affichage */
	sf::VertexArray myVertexArray;
	sf::RenderStates myRenderStates;
	bool myAllMapIsInVertexArray;
	// TODO: Tileset myTileset;

	/* Tileset */
	unsigned int myNbTiles; // nb de tiles dont est composé la carte
	std::vector<Tile> myTiles; // Tableau des tiles
	sf::Texture myTileset; // Texture du tileset (pointeur non-constant vers une texture constante)
	std::string myTilesetPath;
	bool myHasTileset;

	/* Carte */
	unsigned int myNbTilesX; // nb de tiles horyzontalement
	unsigned int myNbTilesY; // nb de tiles verticalement
	unsigned int myOffsetX;
	unsigned int myOffsetY;
	std::vector< std::vector<int> > myLayer1; // Tableau des tiles, calque 1 (dessous)
	std::vector< std::vector<int> > myLayer2; // Tableau des tiles, calque 2 (milieu)
	std::vector< std::vector<int> > myLayer3; // Tableau des tiles, calque 3 (dessus)

	/* Musique */
	sf::Music myMusicBckg; // pointeur vers la musique de fond jouée pendant cette carte
	std::string myMusicBckgPath;
	bool myHasMusic;
};

