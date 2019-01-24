/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc.c,
*/

#include "malloc.h"

block_t new_block(block_t  last, size_t size)
{
    block_t new = sbrk(0);
    if (sbrk(BLOCK_SIZE + size) == (void *) -1)
        return NULL;
    new->size = size;
    new->free = false;
    new->next = NULL;
    if (last)
        last->next = new;
    return new;
}

block_t find_block(block_t  last, size_t size)
{
    block_t current = head;

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
    block_t block;
    static block_t last;
    
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
