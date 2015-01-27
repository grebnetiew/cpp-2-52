Goal of the program
-------------------

This program sums the size of regular files in a directory given as command line argument. It does so by using multiple threads; a maximum can be specified as argument.

How it works
------------

The Workhouse class manages the worker threads, and keeps a list of Tasks to perform. It is fairly generic on purpose (templates are implictly disallowed, but might eventually be used to vary the type of Task that can be performed).

The Dirsizer class creates a workhouse, and then walks through directories recursively. Each directory is packaged as a new task and assigned to the workhouse. Its result method is used to wait for all `future' objects to resolve, and to sum their return values.
