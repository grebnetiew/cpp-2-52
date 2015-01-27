#include "dirsizer.ih"

off_t DirSizer::treatEntry(string const &dir, struct dirent *entry)
{
    if (entry->d_name[0] == '.' && (entry->d_name[1] == 0
       || (entry->d_name[1] == '.' && entry->d_name[2] == 0)))
        return 0;                           // this is either . or ..

    if (entry->d_type != DT_DIR)            // Size of files is counted
        return filesize(dir + '/' + entry->d_name);

    dispatch(dir + '/' + entry->d_name);    // Directories are done separately
    return 0;
}
