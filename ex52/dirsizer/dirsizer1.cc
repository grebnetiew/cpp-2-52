#include "dirsizer.ih"
#include <unistd.h>     // pathconf

/*
    Note that pathconf is unsafe by design: this request returns the maximum
    filename length we can create, but there is no way to find out the maximum
    length of existing files' names. Good luck. 
*/
DirSizer::DirSizer(string const &directory, size_t nThreads)
:
    d_wh(nThreads),
    d_directory(directory),
    d_maxNameLen(pathconf(directory.c_str(), _PC_NAME_MAX))
{
    dispatch(d_directory);
}
