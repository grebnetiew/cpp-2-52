#include "workhouse.ih"

void workLoop(Workhouse &wh)
{
    unique_lock<mutex> ul(wh.d_mutex);
    while (wh.awaitWork(ul))
    {
        Workhouse::Task task = move(wh.d_work.front());
        wh.d_work.pop_front();
        ul.unlock();

        task();

        ul.lock();
    }
}
