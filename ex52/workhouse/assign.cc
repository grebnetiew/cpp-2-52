#include "workhouse.ih"

void Workhouse::assign(Task &&t)
{
    unique_lock<mutex> ul(d_mutex);
    d_work.push_back(move(t));
    ul.unlock();
    d_workers.notify_one();
}
