#include "fileSystem.h"
#include <filesystem>
#include <sys/stat.h>
#include <iterator>
#include <fstream>

namespace fs = std::filesystem;

namespace icejj{


		// static int64 GetFileSizeInternal(std::ifstream fs)
		// {
		// 	return fs::file_size(fs);
		// }

		//TODO use C++17 filesystem
		bool FileSystem::FileExists(const std::string& path)
		{
			return fs::exists(path);
		}

		int64 FileSystem::GetFileSize(const std::string& path)
		{
			if(IsFile(path)){

				return fs::file_size(path);
			}
			else{

				printf("is not a regular file\n");
				return 0;
			}
		}

		bool FileSystem::IsDirectory(const std::string& path)
		{
			return (FileExists(path)? fs::is_directory(path) : false);
		}

		bool FileSystem::IsFile(const std::string& path)
		{
			return (FileExists(path) ? fs::is_regular_file(path) : false);
		}

		bool FileSystem::ReadFile(const std::string& path, void* buffer, int64 size)
		{
			if(buffer == nullptr) return false;
			//
			std::ifstream fs(path, std::ios::binary);
			if(fs.is_open())
			{
				if(size < 0)
					size = GetFileSize(path);
				
				fs.read((char*)buffer, size);
				fs.close();
				return true;
			}
			return false;
		}

		char* FileSystem::ReadFile(const std::string& path)
		{
			std::ifstream fs;
			fs.open(path, std::ios::binary);
			int size = GetFileSize(path);
			printf("[FileSystem::ReadFile] size = %d\n", size);
			char* buffer = new char[size];
			fs.read(buffer, size);
			fs.close();
			
			return buffer;
		}


		std::string FileSystem::ReadTextFile(const std::string &path)
		{
			std::ifstream fs;
			std::string context;			
			fs.open(path);
			context = {std::istreambuf_iterator<char>(fs), {}};
			fs.close();

			return context;
		}

		bool FileSystem::WriteTextFile(const std::string& path, const std::string& text){

			std::ofstream fs;
			bool success;
			fs.open(path);

			if(fs.is_open())
			{
				fs << text;
				success = true;
				fs.close();
			}
			else
			{
				printf("error opening file\n");
				success = false;
			}
			
			return success;
		}
}