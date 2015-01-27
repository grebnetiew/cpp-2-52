#include "workhouse.ih"

Workhouse::~Workhouse()
{
    d_active = false;
    d_workers.notify_all();
    for (thread &t : d_threads)
        t.join();
}
