#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML\Graphics.hpp>

#ifdef __unix__
	// I don't know how to pause on Linux
	#define PAUSE() 
#elif defined _WIN32
	#define PAUSE() system("PAUSE")
#endif

// See http://en.wikipedia.org/wiki/High_color -> "16-bit high color" for the encoding of the screen buffer
#define RGB(r, g, b) (unsigned short) (((((unsigned char)(r)) / 8) << 11) | ((((unsigned char)(g)) / 4) << 5) | (((unsigned char)(b)) / 8))

int main(int argc, char *argv[])
{
	// Vector of images path
	std::vector<std::string> imagesPath;
	bool givenByArg = false;

	// Check if an image were given
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
			imagesPath.push_back(std::string(argv[i]));
		givenByArg = true;
	}
	// Or ask for the image path
	else
	{
		std::string path = "";
		std::cout << "Enter your image path : ";
		std::cin >> path;
		imagesPath.push_back(path);
	}

	// Load the image(s)
	for (unsigned int i = 0; i < imagesPath.size(); ++i)
	{
		sf::Image img;
		if (!img.loadFromFile(imagesPath[i]))
		{
			std::cerr << "Can't open the image!" << std::endl;
			PAUSE();
			return EXIT_FAILURE;
		}
	
		// Ask for the tileset path
		std::string path = "";
		if (!givenByArg)
		{
			std::cout << std::endl << "Enter your converted image relative path (\"*.nif.tns\" is recommended) : ";
			std::cin >> path;
		}
		// Or compute it
		else
		{
			path = imagesPath[i];
			path = path.substr(0, path.find_last_of('.')) + ".nif.tns";
		}
	
		// Tell that we are converting
		if (!givenByArg)
			std::cout << "Converting..." << std::endl;
		else
			std::cout << "Converting ( " << i + 1 << " / " << imagesPath.size() << " )..." << std::endl;

		// Open the file
		FILE *f;
		fopen_s(&f, path.c_str(), "wb");
		if (!f)
		{
			std::cerr << "Can't create the file!" << std::endl;
			PAUSE();
			return EXIT_FAILURE;
		}

		// Save image size
		int size = img.getSize().x;
		fwrite(&size, 1, sizeof(unsigned int), f);
		size = img.getSize().y;
		fwrite(&size, 1, sizeof(unsigned int), f);

		// Save pixels
		unsigned short c;
		unsigned short *image = (unsigned short*) calloc(img.getSize().x * img.getSize().y, sizeof(unsigned short));
		for (unsigned int x = 0; x < img.getSize().x; ++x)
		{
			for (unsigned int y = 0; y < img.getSize().y; ++y)
			{
				c = RGB(img.getPixel(x, y).r, img.getPixel(x, y).g, img.getPixel(x, y).b);
				image[x + y * img.getSize().x] = c;
			}
		}
		fwrite(image, sizeof(unsigned short), img.getSize().x * img.getSize().y, f);
		fclose(f);
	}

	// Done
	std::cout << "Done!" << std::endl;
	PAUSE();

	return 0;
}
