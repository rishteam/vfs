#include "icejj.h"
// #include "fileSystem.h"
// #include <bits/stdc++.h>
#include "vfs.h"


// #include <fstream>

using namespace icejj;

int main(){

	setvbuf(stdout, nullptr, _IONBF, 0);
	setvbuf(stderr, nullptr, _IONBF, 0);
	VFS::Init();

	VFS::Get()->Mount("testA", "test/test2");
	VFS::Get()->Mount("testB", "test/test3");
	printf("hi\n");

	std::string str = VFS::Get()->ReadTextFile("testA/test2.txt");

	system("pause");
	return 0;
}




// int main(){
// 	setvbuf(stdout, nullptr, _IONBF, 0);
// 	setvbuf(stderr, nullptr, _IONBF, 0);
// 	//
// 	std::string filename = "test/test2/test2.txt";
// 	std::string filename2 = "test/test2/test2.txt";

// 	char *test = "hans0meDaLun";
// 	std::string str = "AAA BBB";

// 	if (FileSystem::FileExists(filename2))
// 	{
// 		if (FileSystem::WriteTextFile(filename2, test))
// 		{
// 			printf("success to write\n");
// 		}
// 	}
// 	else
// 	{
// 		printf("file not found\n");
// 	}

// 	printf("\n----------------------------------------\n");

// 	if (icejj::FileSystem::FileExists(filename))
// 	{
// 		printf("file/directory exists\n");
// 		size_t fileSize = FileSystem::GetFileSize(filename);
// 		char* buf = new char[fileSize];
// 		if(icejj::FileSystem::ReadFile(filename, buf))
// 		{
// 			for(int i = 0; i < fileSize; i++)
// 			{
// 				if(i && i % 16 == 0) puts("");
// 				printf("%02X ", buf[i]);
// 			}
// 			delete buf;
// 			buf = nullptr;
// 		}
// 	}
// 	else{

// 		printf("file not found\n");
// 	}

// 	system("pause");
// 	return 0;
// }