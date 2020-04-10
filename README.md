## Document

### function

#### static void VFS::Init()
:::info
new a virtual file system
:::

```cpp=
VFS::Init();
```


#### static void VFS::ShutDown()
:::info
Delete the instance of vfs
:::

```cpp=
VFS::ShutDown();
```

##### inline statuc VFS* VFS::Get()
:::info
Get the instance of vfs
:::


```cpp=
VFS::Get();
```


#### void VFS::Mount(const std::string& virtualPath, const std::string& physicalPath)

:::info
Mount physical path to virtual path, so that you can access the file via virtual path without passing the physical path
:::

:::danger
After the mount, every time you want to access the file via virtual path should put a '/' front of the virtual path
:::

```cpp=

VFS::Get()->Mount("picture", "data/map/picture");
VFS::Get()->Mount("picture", "data/enemy/picture");
//mount those path to /picture
//after mount, you can access the file via "/picture"
```

:::warning
remeber to Get() the instance before using the function
:::


#### void VFS::UnMount(const std::string& path)

:::info
Unmount the virtual path, this will clear all the physical path that mount to the virtual path
:::


```cpp=
VFS::Get()->UnMount("picture");
//clear all the path
```

#### bool VFS::ResovlePhysicalPath(const std::string& path, std::string& outphysicalPath)

:::info
Get the physical path of the virtual path, and return a bool value to check if success to find the path.
Physical path will be store in outphysicalPath
You can also pass the physical path to the function 
:::

:::danger
If you get 'null' constanly, please check two things

1. your physical path that mount to the virtual path is correct

2. check if you have place a '/' when you try to access the virtual path
    * correct: VFS::Get()->ResolvePhysicalPath("/xxxx/xxx.txt", str)  
        * this is virtual path
    * wrong: VFS::Get()->ResolvePhysicalPath("xxxx/xxx.txt", str)  
        * this is physical path
:::

```cpp=
#include "vfs.h"

using namespace icejj;

int main(){

    VFS::Init();
    VFS::Get()->Mount("picture", "data/map/picture");
    VFS::Get()->Mount("picture", "data/enemy/picture");
    //mount those path to /picture
    
    std::string outPhysicalPath;//store the physical path
    
    //remember to put a '/' before the virtual path
    if(VFS::Get()->ResolvePhysicalPath("/picture/r0y.txt", outPhysicalPath)
    {
    
        //the physical path will store here
        std::cout << outPhysicalPath << "\n";   
    }
    
    
    return 0;
}
```

#### char* VFS::RealFile(const std::string& path)
:::info
return file content with char* type
:::

```cpp=
#include "vfs.h"

using namespace icejj;

int main(){

    VFS::Init();
    VFS::Get()->Mount("picture", "data/map/picture");
    VFS::Get()->Mount("picture", "data/enemy/picture");
    //mount those path to /picture
    
    std::string outPhysicalPath;//store the physical path
    
    //remember to put a '/' before the virtual path
    char* buffer;
    buffer = VFS::Get()->ReadFile("/picture/aa.txt");
    
    printf("%s", buffer);
   
    
    return 0;
}

```


#### std::string VFS::ReadTextFile(const std::string& path)
:::info
return file content with std::string type
:::
```cpp=
#include "vfs.h"

using namespace icejj;

int main(){

    VFS::Init();
    VFS::Get()->Mount("picture", "data/map/picture");
    VFS::Get()->Mount("picture", "data/enemy/picture");
    //mount those path to /picture
    
    std::string outPhysicalPath;//store the physical path
    
    //remember to put a '/' before the virtual path
    std::string buffer;
    buffer = VFS::Get()->ReadFile("/picture/aa.txt");
    
    std::cout << buffer << "\n";
    
    return 0;
}
```

#### bool VFS::WriteFile(const std::string& path, char* buffer)

:::info
Write char* to file, and return a bool
:::
:::danger
if the file is not exist, the filesystem won't generate a file
:::

```cpp=
char* buffer = "aaaaaa";
VFS::Get()->WriteFile("/picture/aa.txt", buffer);
```


#### VFS::WriteTextFile(const std::string& path, const std::string& text)
:::info
Write std::string to file, and return a bool
:::
:::danger
if the file is not exist, the filesystem won't generate a file
:::


```cpp=
std::string text = "icejj";
VFS::Get()->WriteTextFile("/picture/aa.txt", text);
```
