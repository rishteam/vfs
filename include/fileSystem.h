#include "icejj.h"

namespace icejj{

	class FileSystem
	{
	public:

		static bool FileExists(const std::string& path);
		static int64 GetFileSize(const std::string& path);

		static bool IsDirectory(const std::string& path);
		static bool IsFile(const std::string& path);

		static char* ReadFile(const std::string& path);//TODO implement
		static bool ReadFile(const std::string& path, void* buffer, int64 size = -1);//TODO implement
		static std::string ReadTextFile(const std::string& path);

		static bool WriteFile(const std::string& path, char* buffer);//TODO implement
		static bool WriteTextFile(const std::string& path, const std::string& text);
	};

}
