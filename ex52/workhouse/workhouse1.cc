#include "workhouse.ih"

Workhouse::Workhouse(size_t nWorkers)
{
    unique_lock<mutex> ul(d_mutex);
    for (size_t idx = 0; idx != nWorkers; ++idx)
        d_threads.push_back(thread(workLoop, ref(*this)));
}
