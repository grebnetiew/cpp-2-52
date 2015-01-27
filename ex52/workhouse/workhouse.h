#ifndef INCLUDED_WORKHOUSE_
#define INCLUDED_WORKHOUSE_

#include <deque>
#include <mutex>
#include <thread>
#include <future>
#include <condition_variable>

class Workhouse
{
    public:
        typedef std::packaged_task<off_t()> Task;

    private:
        std::deque<std::thread> d_threads;
        std::condition_variable d_workers;
        std::deque<Task> d_work;
        std::mutex d_mutex;
        bool d_active = true;

    public:
        explicit Workhouse(size_t nWorkers);
        ~Workhouse();
        void assign(Task &&t);

    private:
        void workLoop();
        bool awaitWork(std::unique_lock<std::mutex> &ul);
};

#endif
