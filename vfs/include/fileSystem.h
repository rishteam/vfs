#include "pch.h"
#include <filesystem>

namespace icejj{

class FileSystem
{
public:
	static std::string GetCurrentDirectory();
	static std::filesystem::path GetCurrentDirectoryPath();
	static void SetCurrentDirectory(const std::string &path);
	static void SetCurrentDirectoryPath(const std::filesystem::path &path);
	static void CreateFile(const std::string& path);

	static bool FileExists(const std::string& path);
	static int64 GetFileSize(const std::string& path);

	static bool IsDirectory(const std::string& path);
	static bool IsFile(const std::string& path);

	static char* ReadFile(const std::string& path);
	static bool ReadFile(const std::string& path, void* buffer, int64 size = -1);
	static std::string ReadTextFile(const std::string& path);

	static bool WriteFile(const std::string& path, char* buffer, size_t size);
	static bool WriteTextFile(const std::string& path, const std::string& text, size_t size);
};

}
