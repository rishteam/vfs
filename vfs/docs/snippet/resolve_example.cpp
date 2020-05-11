VFS::Init();
VFS::Get()->Mount("picture", "data/map/picture");
VFS::Get()->Mount("picture", "data/enemy/picture");
// mount those path to /picture

std::string outPhysicalPath; // store the physical path

// remember to put a '/' before the virtual path (Root path)
if (VFS::Get()->ResolvePhysicalPath("/picture/r0y.txt", outPhysicalPath))
{
    // the physical path will store here
    std::cout << outPhysicalPath << "\n";
}