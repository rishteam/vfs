#include "pch.h"
#include "vfs.h"
#include "fileSystem.h"

using namespace icejj;

struct Foo
{
	int a = 0;
	float b = 8.7;
	char c[10] = "123";
};

int main(){

	setvbuf(stdout, nullptr, _IONBF, 0);
	setvbuf(stderr, nullptr, _IONBF, 0);
	//
	sf::RenderWindow window(sf::VideoMode(1280, 720), "vfs test");
	
	// Change the Current Working Directory (CWD)
	FileSystem::SetCurrentDirectoryPath(FileSystem::GetCurrentDirectoryPath().parent_path().parent_path() / "vfs_root");
	printf("cwd= %s\n", FileSystem::GetCurrentDirectory().c_str());

	// Initialize the VFS
	VFS::Init();
	// /data  +-> $cwd/data
	//        +-> $cwd/test/data
	VFS::Get()->Mount("data", "data");
	VFS::Get()->Mount("data", "test/data");
	//
	// /test +-> $cwd/test/test2
	//       +-> $cwd/test/test3
	VFS::Get()->Mount("test", "test/test2");
	VFS::Get()->Mount("test", "test/test3");

	// Test load 1.jpg
	// /data/1.jpg -> ./data/1.jpg
	sf::Texture texture_1;
	std::string physicalPath_1;
	VFS::Get()->ResolvePhysicalPath("/data/1.jpg", physicalPath_1);
	if(!texture_1.loadFromFile(physicalPath_1))
		printf("Failed to load texture_1\n");
	sf::Sprite sprite_1(texture_1);
	sprite_1.setScale(0.1, 0.1);
	sprite_1.setPosition(0, 0);

	// Test load 2.png
	// /data/2.png -> ./test/data/2.png
	sf::Texture texture_2;
	std::string physicalPath_2;
	VFS::Get()->ResolvePhysicalPath("/data/2.png", physicalPath_2);
	if(!texture_2.loadFromFile(physicalPath_2))
		printf("Failed to load texture_2\n");
	sf::Sprite sprite_2(texture_2);
	sprite_2.setScale(0.5, 0.5);
	sprite_2.setPosition(500, 0);

	// Test ReadTextFile()
	std::string charString = VFS::Get()->ReadTextFile("/test/test2.txt");
	std::cout << charString << "\n";

	// Test WriteTextFile()

	
	Foo foo;
	VFS::Get()->WriteFile("/test/WriteFile1.bin", (char*)&foo, sizeof(foo));

	// std::string text = "icejj";
	// size_t size = text.size();
	// printf("size: %d\n", size);
	// VFS::Get()->WriteTextFile("/test/test3.txt", text, size);

	bool run = true;
	while(run)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
				// printf("test\n");
		}

		window.clear();
		window.draw(sprite_1);
		window.draw(sprite_2);
		window.display();
	}

	VFS::ShutDown();
	system("pause");
}