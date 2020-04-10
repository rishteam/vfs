#include "icejj.h"
#include "vfs.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace icejj;

int main(){

	// setvbuf(stdout, nullptr, _IONBF, 0);
	// setvbuf(stderr, nullptr, _IONBF, 0);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "vfs test");

	VFS::Init();

	VFS::Get()->Mount("data", "data");
	VFS::Get()->Mount("data", "test/data");

	sf::Texture texture_1;
	std::string physicalPath_1;
	VFS::Get()->ResovlePhysicalPath("/data/1.jpg", physicalPath_1);

	// std::cout << physicalPath_1 << std::endl;

	if(!texture_1.loadFromFile(physicalPath_1))
	{
		printf("load failed\n");
		return 0;
	}
	sf::Sprite sprite_1(texture_1);
	sprite_1.setScale(0.5, 0.5);

	sf::Texture texture_2;
	std::string physicalPath_2;
	VFS::Get()->ResovlePhysicalPath("/data/2.png", physicalPath_2);

	if(!texture_2.loadFromFile(physicalPath_2))
	{
		printf("load failed\n");
		return 0;
	}
	
	sf::Sprite sprite_2(texture_2);

	bool run = true;
	while(run)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite_1);
		window.draw(sprite_2);
		window.display();
	}

	// system("pause");
	return 0;
}
