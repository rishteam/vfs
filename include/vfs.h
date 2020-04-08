#pragma once

#include "icejj.h"

namespace icejj{

	class VFS{

	private:
		static VFS* vfs_Instance;

	private:
		std::unordered_map<std::string, std::vector<std::string> > m_MountPoints;

	public:

		void Mount(const std::string& virtualPath, const std::string& physicalPath);
		void Unmount(const std::string& path);

		bool ResovlePhysicalPath(const std::string& path, std::string& physicalPath);

		char* ReadFile(const std::string& path);
		std::string ReadTextFile(const std::string& path);

		bool WriteFile(const std::string& path, char* buffer);
		bool WriteTextFile(const std::string& path, const std::string& text);

	public:

		static void Init();
		static void ShutDown();

		inline static VFS* Get() { return vfs_Instance; }
	};
}