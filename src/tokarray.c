/*
** @file_name: tokarray.c
** @directory: ./src
**
** @project_name: my_tokarray
** @author: Fohz67
**
** @description: This project allows you to transform a string
** into an array of strings, based on specified separators.
** This project is written entirely in C.
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void free_array(char **);

static int count_tokens(const char *buffer, const char *separators)
{
    char *buffer_cpy = NULL;
    char *token = NULL;
    size_t size = 0;

    buffer_cpy = strdup(buffer);
    if (!buffer_cpy) {
        return -1;
    }
    token = strtok(buffer_cpy, separators);
    while (token) {
        size++;
        token = strtok(NULL, separators);
    }
    free(buffer_cpy);
    return size;
}

static char **tokenize_buffer(char *buffer, char **array, const char *separators)
{
    size_t i = 0;
    char *token = NULL;

    token = strtok(buffer, separators);
    while (token) {
        array[i] = strdup(token);
        if (!array[i]) {
            free_array(array);
            free(token);
            return NULL;
        }
        token = strtok(NULL, separators);
        i++;
    }
    array[i] = NULL;
    free(token);
    return array;
}

void free_array(char **array)
{
    if (!array) {
        return;
    }
    for (size_t i = 0; array[i]; i++) {
        free(array[i]);
    }
    free(array);
}

char **my_tokarray(char *buffer, const char *separators)
{
    char **array = NULL;
    int size;

    if (!buffer) {
        return NULL;
    }
    size = count_tokens(buffer, separators);
    if (!size) {
        return NULL;
    }
    array = malloc(sizeof(char *) * (size + 1));
    if (!array) {
        return NULL;
    }
    array = tokenize_buffer(buffer, array, separators);
    return array;
}
