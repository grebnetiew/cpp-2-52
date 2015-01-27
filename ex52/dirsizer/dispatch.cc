#include "dirsizer.ih"

void DirSizer::dispatch(string const &newDir)
{
    Workhouse::Task task([=](){ return dirsize(newDir); });
    d_fq.push_back(task.get_future());
    d_wh.assign(move(task));
}
