/*
** @file_name: main.c
** @directory: root
**
** @project_name: my_tokarray
** @author: Fohz67
*/

#include <string.h>
#include <stdio.h>
#include "../include/my_tokarray.h"

static void print_size( const char *name, int size)
{
    printf("Size of %s: %d\n", name, size);
}

static void print(char **array) {
    for (size_t i = 0; array[i]; i++) {
        printf("Array [%d]: %s\n", (int)i, array[i]);
    }
}

int main(void)
{
    char buffer[] = "- Hello;- How are you today ?;- I'm okay, what about you ?";
    const char *separators = ";";
    char **array = NULL;

    print_size("buffer", sizeof buffer);
    array = my_tokarray(buffer, separators);
    print_size("array", sizeof array);
    if (!array) {
        return 84;
    }
    print(array);
    free_array(array);
    return 0;
}
