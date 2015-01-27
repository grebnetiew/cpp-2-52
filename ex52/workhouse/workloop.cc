#include "workhouse.ih"

void Workhouse::workLoop()
{
    unique_lock<mutex> ul(d_mutex);
    while (awaitWork(ul))
    {
        Workhouse::Task task = move(d_work.front());
        d_work.pop_front();
        ul.unlock();

        task();

        ul.lock();
    }
}
