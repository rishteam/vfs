/**
 * @file fileSystem.h
 * @author icejj (icejj@rish.com.tw), roy4801 (roy@rish.com.tw)
 * @brief File System
 * @version 0.1
 * @date 2020-05-03
 *
 * @copyright Copyright (c) 2020
 *
 */
#pragma once

#include "pch.h"
#include <filesystem>

namespace icejj {

/**
 * @brief File System class
 * @details The class that handles the filesystem and provide various convenient utilities.
 */
class FileSystem
{
public:
    /**
     * @brief Get the Current Directory
     * @return std::string Path
     */
    static std::string GetCurrentDirectory();

    /**
     * @brief Get the Current Directory Path object
     * @return std::filesystem::path Path
     */
    static std::filesystem::path GetCurrentDirectoryPath();

    /**
     * @brief Set the Current Directory by std::string
     * @param path Path
     */
    static void SetCurrentDirectory(const std::string &path);

    /**
     * @brief Set the Current Directory by Path object
     * @param path Path Object
     */
    static void SetCurrentDirectoryPath(const std::filesystem::path &path);

    /**
     * @brief Create a File
     * @param path Path of the new file
     */
    static void CreateFile(const std::string& path);

    /**
     * @brief Is the file exist
     *
     * @param path Path to the file
     * @return true Exist
     * @return false Not exist
     */
    static bool FileExists(const std::string& path);

    /**
     * @brief Get the file size
     *
     * @param path Path to the file
     * @return int Size of the file
     */
    static int GetFileSize(const std::string &path);

    /**
     * @brief Is the path a directory
     *
     * @param path Path to the directory
     * @return true It's a directory
     * @return false It's not a directory
     */
    static bool IsDirectory(const std::string& path);

    /**
     * @brief Is the path a file
     *
     * @param path  Path to the file
     * @return true It's a file
     * @return false It's not a file
     */
    static bool IsFile(const std::string& path);

    /**
     * @brief Read the file in binary mode and returns a new array
     * @warning This will return a new allocated `char*` \n
     *          Remeber to *DELETE* on your own
     * @param path Path to the file in FileSystem
     * @return char* File content
     */
    static char* ReadFile(const std::string& path);
    // TODO: size???

    /**
     * @brief Read the file in binary mode into a specified buffer
     * @warning buffer cannot be `nullptr`
     * @param path Path to the file in FileSystem
     * @return true Success
     * @return false Failed
     */
    static bool ReadFile(const std::string& path, void* buffer, int size=0);
    // TODO: change the `void* buffer` to `char *buffer`?

    /**
     * @brief Read the file in text mode
     *
     * @param path Path to the file in FileSystem
     * @return std::string Content
     */
    static std::string ReadTextFile(const std::string& path);

    /**
     * @brief Write the file in binary mode
     *
     * @param path Path to the file in FileSystem
     * @param buffer The buffer contains bytes will be written into file
     * @param size The length of data
     * @return true Succeed to write the file
     * @return false Failed to write the file
     */
    static bool WriteFile(const std::string &path, const char *buffer, int size);

    /**
     * @brief Write the file in text mode
     *
     * @note If the file is not exist, the it won’t generate a file.\n
     *       You should create the file before you access
     *
     * @param path Path to the file in VFS
     * @param text The buffer contains bytes will be written into file
     * @param size The length of data
     * @return true Succeed to write the file
     * @return false Failed to write the file
     */
    static bool WriteTextFile(const std::string &path, const std::string &text, const int size);
};

}
