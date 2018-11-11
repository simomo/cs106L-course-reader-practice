# Compiling and linking are seperated two steps

That's why the error is raised by the linker(`ld`), because from compiler's perspective, the file `link_error.cpp` is totally OK.

# Compiling multiple files

`g++ link_error.cpp factorial.cpp`.