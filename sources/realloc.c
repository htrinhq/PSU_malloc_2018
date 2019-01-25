/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** realloc.c,
*/

#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
        block_t header;
        void *tmp;

        if (!ptr && !size)
                return NULL;
        if ((!size || size == 0) && ptr)
                free(ptr);
        if (!ptr && size)
                return malloc(size);
        header = get_block_ptr(ptr);
        if (header->size >= size)
                return ptr;
        tmp = malloc(size);
        if (tmp != NULL) {
                memcpy(tmp, ptr, header->size);
                free(ptr);
        }
        return tmp;
}