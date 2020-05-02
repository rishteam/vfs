/**
 * @file vfs.h
 * @author icejj (icejj@rish.com.tw)
 * @brief Virtual File System
 * @version 0.1
 * @date 2020-05-02
 *
 * @copyright Copyright (c) 2020
 *
 */
#pragma once

#include "pch.h"

namespace icejj {

/**
 * @brief Virtual File System class
 */
class VFS
{
private:
    /**
     * @brief Instancce of VFS
     *
     * The instance of VFS (singleton pattern)
     */
    static VFS* vfs_Instance;
    std::unordered_map<std::string, std::vector<std::string> > m_MountPoints;
    // TODO: not unmount whole virtual path: change std::vector to std::list
public:
    /**
     * @brief Initialize the VFS
     */
    static void Init();
    /**
     * @brief Shutdown the VFS
     */
    static void ShutDown();
    /**
     * @brief Get the instance of VFS
     *
     * Retrieve the pointer to the instance of VFS
     * @return VFS* Pointer to the VFS object
     */
    inline static VFS *Get() { return vfs_Instance; }

    /**
     * @brief Mount the path
     *
     * @warning After the mount, every time you want to access the file via virtual path should put a '/' front of the virtual path
     *
     * Mount physical path to virtual path, so that you can access the file
     * via virtual path without passing the physical path
     *
     * @param virtualPath Path that will use in VFS.
     * @param physicalPath Path to the real path.
     *
     * @include{'lineno'} snippet/mount_example.cpp
     *
     * @note remeber to Get() the instance before using the function
     *
     */
    void Mount(const std::string& virtualPath, const std::string& physicalPath);

    /**
     * @brief Unmount the path
     *
     * Unmount the virtual path, this will clear all the physical path that mount to the virtual path.
     * @param path Virtual path that will be unmount
     *
     * @code{.cpp}
     * VFS::Get()->Unmount("picture");
     * // clear all the path
     * @endcode
     */
    void Unmount(const std::string& path);

    /**
     * @brief Resolve the physicalPath
     *
     * Get the physical path of the virtual path, and return a bool value to check if success to find the path.
     * Physical path will be store in outphysicalPath
     * @note You can also pass the physical path to the function
     * @warning If you get ‘null’ constanly, please check two things
     *  1. The physical path that mount to the virtual path is correct
     *  2. Check if you have place a ‘/’ when you try to access the virtual path
     *      - Correct: `VFS::Get()->ResolvePhysicalPath("/xxxx/xxx.txt", str)`
     *      - Wrong: `VFS::Get()->ResolvePhysicalPath(“xxxx/xxx.txt”, str)`
     *
     * @include{'lineno'} snippet/resolve_example.cpp
     *
     * @param[in] path Virtual Path
     * @param[out] outphysicalPath Physical Path
     * @return true Succeeded to resolve the physicalPath
     * @return false Failed to resolve the physicalPath
     */
    bool ResolvePhysicalPath(const std::string& path, std::string& outphysicalPath);

    char* ReadFile(const std::string& path);
    std::string ReadTextFile(const std::string& path);

    bool WriteFile(const std::string &path, const char *buffer, const int size);
    bool WriteTextFile(const std::string& path, const std::string& text, const int size);
};

}