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
      
	};
}