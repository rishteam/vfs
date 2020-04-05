#include "icejj.h"
#include "fileSystem.h"
// #include <bits/stdc++.h>


#include <fstream>
bool fexists(const std::string &filename)
{
	std::ifstream ifile(filename.c_str());
	return (bool)ifile;
}
using namespace icejj;

int main(){

	std::string filename = "test/test3/test3.txt";

	if (icejj::FileSystem::FileExists(filename))
	{
		printf("file/directory exists\n");
		// printf("%llu\n", icejj::FileSystem::GetFileSize(filename));
		size_t fileSize = FileSystem::GetFileSize(filename);
		char* buf = new char[fileSize];
		if(icejj::FileSystem::ReadFile(filename, buf))
		{
			for(int i = 0; i < fileSize; i++)
			{
				if(i && i % 16 == 0) puts("");
				printf("%02X ", buf[i]);
			}
			delete buf;
			buf = nullptr;
		}

	}
	else{

		printf("file not found\n");
	}

	return 0;
}