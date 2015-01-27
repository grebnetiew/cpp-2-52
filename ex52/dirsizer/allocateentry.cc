#include "dirsizer.ih"
#include <stddef.h>     // offsetof

struct dirent *DirSizer::allocateEntry() const
{
    return static_cast<struct dirent *>(
        operator new(offsetof(struct dirent, d_name) + d_maxNameLen + 1));
}