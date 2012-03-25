#include <iostream>
#include <string>
#include <fstream>
#include <SFML\Graphics.hpp>

// See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer
#define RGB(r, g, b) (unsigned short) (((((unsigned char)(r)) / 8) << 11) | ((((unsigned char)(g)) / 4) << 5) | (((unsigned char)(b)) / 8))

int main()
{
	// Ask for the image path
	std::string path = "";
	std::cout << "Enter your image path : ";
	std::cin >> path;

	// Load the image
	sf::Image img;
	if (!img.LoadFromFile(path))
	{
		std::cerr << "Can't open the image!" << std::endl;
		return EXIT_FAILURE;
	}
	
	// Ask for the tileset path
	path = "";
	std::cout << std::endl << "Enter your converted image path : ";
	std::cin >> path;
	
	// Tell that we are converting
	std::cout << "Converting..." << std::endl;

	// Open the file
	FILE *f;
	fopen_s(&f, path.c_str(), "wb");
	if (!f) return EXIT_FAILURE;

	// Save image size
	int i = img.GetWidth();
	fwrite(&i, 1, sizeof(unsigned int), f);
	i = img.GetHeight();
	fwrite(&i, 1, sizeof(unsigned int), f);

	// Save pixels
	unsigned short c;
	unsigned short *image = (unsigned short*) calloc(img.GetWidth() * img.GetHeight(), sizeof(unsigned short));
	for (unsigned int i = 0; i < img.GetWidth(); ++i)
	{
		for (unsigned int j = 0; j < img.GetHeight(); ++j)
		{
			c = RGB(img.GetPixel(i, j).r, img.GetPixel(i, j).g, img.GetPixel(i, j).b);
			image[j + i * img.GetHeight()] = c;
			//fwrite(&c, sizeof(unsigned short), 1, f);
		}
	}
	fwrite(image, sizeof(unsigned short), img.GetWidth() * img.GetHeight(), f);
	fclose(f);

	// Done
	std::cout << "Done!" << std::endl;
	system("PAUSE");

	return 0;
}
