#include "dirsizer.ih"
#include <unistd.h>     // lstat
#include <sys/stat.h>   // lstat

// Returns the size of a regular file, and 0 for anything else
off_t DirSizer::filesize(std::string const &name) const
{
    struct stat sb;
    return (lstat(name.c_str(), &sb) != -1 && S_ISREG(sb.st_mode)) ? sb.st_size : 0;
}