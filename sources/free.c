/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** free.c,
*/

#include "malloc.h"

block_t fusion_block(block_t block)
{
    if (block->next && block->next->free) {
        block->size += BLOCK_SIZE + block->next->size;
        block->next = block->next->next;
    }
    return (block);
}

block_t split_block(block_t block, size_t size)
{
    void *new = sbrk(BLOCK_SIZE + (block->size - size));
    block_t split = new;

    split->size -= (size + BLOCK_SIZE);
    split->free = true;
    split->next = block->next;
    block->size = size;
    block->next = split;
    return (block);
}

block_t get_block_ptr(void *ptr)
{
    return (block_t)ptr - 1;
}

int valid_ptr(void *ptr)
{
    if (head)
        if (ptr > head && ptr < sbrk(0))
            return 1;
    return 0;
}

void free(void *ptr)
{
    block_t block;

    if (!valid_ptr(ptr))
        return;
    block = get_block_ptr(ptr);
    block->free = true;
    if (block->next)
        fusion_block(block);
    else {
        block = NULL;
        brk(block);
    }
}