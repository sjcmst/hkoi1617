# HKOI 16/17 samples

## Usage

### C
The makefile is designed to compile all `.c` files into `.o` files, using the same name. 

- To compile all files, simply type:
```
make
```

- To compile a specific file:
```
make <filename> #without .c is fine
```

- To get rid of the existing `.o` files, use *clean*
```
make clean
```

### CPP
The makefile is designed to compile all `.cpp` files into `.out` files, using the same name.

- To compile all files, simply type:
```
make
```

- To compile a specific file:
```
make <filename> #without .cpp is fine
```

- To get rid of the existing `.out` files, use *clean*
```
make clean
```


## File Structure
_to be updated_

## Git Setup
- `.out` and `.o` files are ignored in git
- In addition, if you make a directory named `/backup`, its contents will be ignored from git as well, feel free to move your files into `/backup` to avoid commiting and pushing your backup copies