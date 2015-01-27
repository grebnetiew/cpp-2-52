#include "dirsizer.ih"

// Resolves all the futures. Meaningless (returns 0) before calling run()
off_t DirSizer::result()
{
    off_t result = 0;
    while (d_fq.size() != 0)
    {
        result += d_fq.front().get();
        d_fq.pop_front();
    }
    return result;
}
