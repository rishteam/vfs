#include "icejj.h"
#include "vfs.h"

#include "fileSystem.h"

namespace icejj{

	VFS* VFS::vfs_Instance = nullptr;

	void VFS::Init()
	{
		vfs_Instance = new VFS();
	}

	void VFS::ShutDown()
	{
		delete vfs_Instance;
	}

	void VFS::Mount(const std::string& virtualPath, const std::string& physicalPath)
	{
		m_MountPoints[virtualPath].push_back(physicalPath);
	}

	void VFS::Unmount(const std::string& path)
	{
		m_MountPoints[path].clear();
	}

	bool VFS::ResovlePhysicalPath(const std::string& path, std::string& outphysicalPath)
	{
		if(path[0] != '/')
		{
			outphysicalPath = path;
			return FileSystem::FileExists(path);
		}

		std::vector<std::string> dirs;

		//split path
		//example: aaa/bbb/ccc to [aaa, bbb, ccc]
		size_t start = 0;
		size_t end = path.find_first_of('/');

		while(end <= std::string::npos)
		{
			std::string token = path.substr(start, end-start);
			if(!token.empty())
				dirs.push_back(token);

			if(end == std::string::npos)
				break;

			start = end + 1;
			end = path.find_first_of('/', start);
		}
		//end split path

		const std::string& virtualDir = dirs.front();
		
		if(m_MountPoints.find(virtualDir) == m_MountPoints.end() || m_MountPoints[virtualDir].empty())
		{
			printf("VFSError: File is not mounted\n");
			return false;
		}
		
		//example: Mount("res", "fuck/res") v: res/test.txt p:fuck/res/test.txt
		//remainder = test.txt
		std::string remainder = path.substr(virtualDir.size()+1, path.size() - virtualDir.size());

		for(const std::string& physicalPath: m_MountPoints[virtualDir])
		{
			std::string path_ = physicalPath + remainder;
			if(FileSystem::FileExists(path_))
			{
				outphysicalPath = path_;
				return true;
			}
		}

		printf("VFSError: File is not mounted\n");
		return false;
	}

	char* VFS::ReadFile(const std::string& path)
	{
		std::string physicalPath;
		return ResovlePhysicalPath(path, physicalPath)? FileSystem::ReadFile(physicalPath): nullptr;
	}

	std::string VFS::ReadTextFile(const std::string& path)
	{
		std::string physicalPath;
		return ResovlePhysicalPath(path, physicalPath)? FileSystem::ReadTextFile(physicalPath): nullptr;
	}

	bool VFS::WriteFile(const std::string& path, char* buffer)
	{
		std::string physicalPath;
		return ResovlePhysicalPath(path, physicalPath)? FileSystem::WriteFile(physicalPath, buffer): false;
	}

	bool VFS::WriteTextFile(const std::string& path, const std::string& text)
	{
		std::string physicalPath;
		return ResovlePhysicalPath(path, physicalPath)? FileSystem::WriteTextFile(physicalPath, text): false;
	}
}


