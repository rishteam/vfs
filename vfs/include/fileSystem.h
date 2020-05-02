#pragma once

#include "pch.h"
#include <filesystem>

namespace icejj {

class FileSystem
{
public:
	static std::string GetCurrentDirectory();
	static std::filesystem::path GetCurrentDirectoryPath();
	static void SetCurrentDirectory(const std::string &path);
	static void SetCurrentDirectoryPath(const std::filesystem::path &path);
	static void CreateFile(const std::string& path);

	static bool FileExists(const std::string& path);
	static int GetFileSize(const std::string &path);

	static bool IsDirectory(const std::string& path);
	static bool IsFile(const std::string& path);

	static char* ReadFile(const std::string& path);
	static bool ReadFile(const std::string& path, void* buffer, int size=0);
	static std::string ReadTextFile(const std::string& path);

	static bool WriteFile(const std::string &path, const char *buffer, int size);
	static bool WriteTextFile(const std::string &path, const std::string &text, const int size);
};

}
