# HKOI 16/17 samples

## Usage
The makefile is designed to compile all `.cpp` files into `.out` files, using the same name. To execute, simply type
```
make
```

To get rid of the existing `.out` files, use *clean*
```
make clean
```

## File & Git Structure
- `.cpp` files should be placed in root
- `.out` files are ignored in git
- In addition, if you make a directory named `backup`, its contents will be ignored from git as well, feel free to move your files in `/backup` to avoid commiting and pushing your backup copies