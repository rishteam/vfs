#pragma once

#include "pch.h"

namespace icejj
{

class VFS
{
private:
	static VFS* vfs_Instance;
	std::unordered_map<std::string, std::vector<std::string> > m_MountPoints;
	// TODO: not unmount whole virtual path: change std::vector to std::list
public:
	static void Init();
	static void ShutDown();
	inline static VFS *Get() { return vfs_Instance; }

	void Mount(const std::string& virtualPath, const std::string& physicalPath);
	void Unmount(const std::string& path);

	bool ResolvePhysicalPath(const std::string& path, std::string& outphysicalPath);

	char* ReadFile(const std::string& path);
	std::string ReadTextFile(const std::string& path);

	bool WriteFile(const std::string& path, char* buffer);
	bool WriteTextFile(const std::string& path, const std::string& text);
};

}