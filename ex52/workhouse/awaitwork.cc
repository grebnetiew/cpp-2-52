#include "workhouse.ih"

bool Workhouse::awaitWork(unique_lock<mutex> &ul)
{
    while (d_active && d_work.size() == 0)
        d_workers.wait(ul);
    return d_active;
}
