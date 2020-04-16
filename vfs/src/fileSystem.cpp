#include "fileSystem.h"
#include <sys/stat.h>
#include <iterator>
#include <fstream>

namespace fs = std::filesystem;

namespace icejj{

std::string FileSystem::GetCurrentDirectory()
{
	return fs::current_path().string();
}

fs::path FileSystem::GetCurrentDirectoryPath()
{
	return fs::current_path();
}

void FileSystem::SetCurrentDirectory(const std::string &path)
{
	fs::path p = fs::path(path);
	if(fs::is_directory(p))
		fs::current_path(path);
	else
		printf("FileSystemError: Failed to set current directory %s\n", path.c_str());
}

void FileSystem::SetCurrentDirectoryPath(const std::filesystem::path &path)
{
	if (fs::is_directory(path))
		fs::current_path(path);
	else
		printf("FileSystemError: Failed to set current directory %s\n", path.c_str());
}

void FileSystem::CreateFile(const std::string& path)
{
	std::ofstream file
	{
		path
	};
	printf("FileSystem: File create in (%s)\n", path.c_str());
}

bool FileSystem::FileExists(const std::string& path)
{
	return fs::exists(path);
}

int64 FileSystem::GetFileSize(const std::string& path)
{
	if(IsFile(path))
	{
		return fs::file_size(path);
	}
	else
	{
		printf("is not a regular file\n");
		return 0;
	}
}

bool FileSystem::IsDirectory(const std::string& path)
{
	return (FileExists(path) ? fs::is_directory(path) : false);
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
	// printf("[FileSystem::ReadFile] size = %d\n", size);
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

bool FileSystem::WriteFile(const std::string& path, char* buffer, size_t size)
{
	// printf("%s\n", buffer);
	
	std::ofstream fs;
	bool success;
	fs.open(path, std::ios::binary);

	if(fs)
	{
		fs.write(buffer, size);
		success = true;
		fs.close();
	}
	else
	{
		printf("error opening file\n");
		success = false;
	}
	
	printf("FileSystem: Success to write content to file\n");
	return success;
}

bool FileSystem::WriteTextFile(const std::string& path, const std::string& text, size_t size)
{
	return WriteFile(path, (char*)&text[0], size);
}

}