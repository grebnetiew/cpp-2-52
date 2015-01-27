#ifndef INCLUDED_DIRSIZER_
#define INCLUDED_DIRSIZER_

#include <deque>
#include <future>
#include <sys/types.h>  // off_t
#include "../workhouse/workhouse.h"

class DirSizer
{
    typedef std::deque<std::future<off_t>> FutureQueue;

    Workhouse d_wh;
    FutureQueue d_fq;
    std::string d_directory;
    size_t d_maxNameLen;

    public:
        DirSizer(std::string const &directory, size_t nThreads);
        off_t result();

    private:
        off_t dirsize(std::string const dir);
        off_t filesize(std::string const &name) const;
        struct dirent *allocateEntry() const;
        void dispatch(std::string const &dir);
        off_t treatEntry(std::string const &dir, struct dirent *entry);
};

#endif
