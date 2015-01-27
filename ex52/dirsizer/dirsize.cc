#include "dirsizer.ih"

// Recursively computes file size of a directory
off_t DirSizer::dirsize(string const dir)
{
    DIR *currentDir = opendir(dir.c_str());
    if (!currentDir)
        return 0;

    off_t total = 0;
    struct dirent *entry(allocateEntry()), *res(nullptr);

    try
    {
        while (readdir_r(currentDir, entry, &res) == 0 && res)
            total += treatEntry(dir, res);
        closedir(currentDir);
        operator delete(entry);
    }
    catch (...)
    {
        closedir(currentDir);
        operator delete(entry);
        throw;
    }

    return total;
}
