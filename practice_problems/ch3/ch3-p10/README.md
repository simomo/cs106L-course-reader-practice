# Not sure if the reference is used rightly

`ifstream& OpenFile(ifstream&);` It's a little wired...

# It seems that `f.clear()` is not necessariy

Each time `f.open` a new file name, its status will be reset
Source code of `open`
```c++
      void
      open(const std::string& __s, ios_base::openmode __mode = ios_base::in)
      {
	if (!_M_filebuf.open(__s, __mode | ios_base::in))
	  this->setstate(ios_base::failbit);
	else
	  // _GLIBCXX_RESOLVE_LIB_DEFECTS
	  // 409. Closing an fstream should clear error state
	  this->clear();
      }
```