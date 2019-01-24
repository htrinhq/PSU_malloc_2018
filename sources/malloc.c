/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc.c,
*/

#include "malloc.h"

t_block new_block(t_block  last, size_t size)
{
    t_block new = sbrk(0);
    if (sbrk(BLOCK_SIZE + size) == (void *) -1)
        return NULL;
    new->size = size;
    new->free = false;
    new->next = NULL;
    if (last)
        last->next = new;
    return new;
}

t_block find_block(t_block  last, size_t size)
{
    t_block current = head;

    while (current) {
        if (current->free && current->size >= size)
            return current;
        current =  current->next;
    }
    return NULL;
}

void *malloc(size_t size)
{
    size_t total_size;
    t_block block;
    static t_block last;
    
    if (head) {
        if (!size)
            return NULL;
        last = head;
        block = find_block(last, size);
        if (block) {
            block->free = false;
        }
    } else {
        block = new_block(last, size);
        if (!block)
            return NULL;
        head = block;
    }
    return (void *)(block + 1);
}
