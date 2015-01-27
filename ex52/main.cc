#include "main.ih"

/*
    This program computes the size of files in the given directory.
    You must compile with -D_FILE_OFFSET_BITS=64.
    Returns 2 for agument errors, 1 for OS errors, and 0 on success.
*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Usage: "<< *argv << " dirname [#threads]\n";
        return 2;
    }
    try
    {                                               // May throw if OOM
        DirSizer ds(argv[1], argc == 2 ? 10 : stoi(argv[2]));
        auto result(ds.result());                   // May throw from future
        cout << "Total size: " << result << '\n';
    }
    catch (exception &e)
    {
        cout << "An error occurred: " << e.what() << '\n';
        return 1;
    }
}