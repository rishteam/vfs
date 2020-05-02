#include "pch.h"
#include "vfs.h"
#include "fileSystem.h"

using namespace icejj;

struct Foo
{
	int a = 4;
	float b = 8.7f;
	char c[15] = "struct foo";
};

int main(){

	setvbuf(stdout, nullptr, _IONBF, 0);
	setvbuf(stderr, nullptr, _IONBF, 0);
	//
	sf::RenderWindow window(sf::VideoMode(1280, 720), "vfs test");
	window.setFramerateLimit(60);
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
	sprite_1.setScale(0.1f, 0.1f);
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
	printf("%d\n", sizeof(foo));
	if(VFS::Get()->WriteFile("/test/WriteFile1.bin", reinterpret_cast<char*>(&foo), sizeof(foo)))
	{
	}
	else
	{
		FileSystem::CreateFile("test/test2/WriteFile1.bin");
		VFS::Get()->WriteFile("/test/WriteFile1.bin", reinterpret_cast<char*>(&foo), sizeof(foo));
	}

	Foo *foo2;
	foo2 = reinterpret_cast<Foo*>(VFS::Get()->ReadFile("/test/WriteFile1.bin"));
	foo2->a = 87;


	VFS::Get()->WriteFile("/test/WriteFile1.bin", reinterpret_cast<char*>(foo2), sizeof(Foo));
	foo2 = reinterpret_cast<Foo*>(VFS::Get()->ReadFile("/test/WriteFile1.bin"));

	std::cout << foo2->a << std::endl;
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
		}

		window.clear();
		window.draw(sprite_1);
		window.draw(sprite_2);
		window.display();
	}

	VFS::ShutDown();
	system("pause");
}