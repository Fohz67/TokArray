
# my_tokarray

## Overview
This project allows you to transform a string into an array of strings, based on specified separators. This project is written entirely in C.

## Features
- **String to Array Transformation**: Easily convert a single string into an array of strings using specified separators with a single function call.
- **Efficient Memory Management**: Allocates just enough memory for the array, ensuring no leaks and optimal usage.

## Compilation
Compile the project using the provided Makefile with the following commands:
- `make`: Compiles the source files.
- `make re`: Re-compiles all files.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and binary.

## Usage
Add the ```my_tokarray.c``` file to your project, include it in the Makefile, and declare the functions ```free_array()``` and ```my_tokarray``` in a header file to be imported wherever you need it.

## Definitions
**my_tokarray**:
```char **my_tokarray(char *buffer, const char *separators)```  
- **buffer**: String to transform  
- **separators**: String with all separators. ```char *separators =" ,;\n"```

**free_array**:
```void free_array(char **array)```  
- **array**: The array to free 

## License
This project is under [MIT License](https://github.com/Fohz67/my_tokarray/main/LICENSE).
