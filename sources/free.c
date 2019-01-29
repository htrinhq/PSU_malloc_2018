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
    block_t split = NULL;
    block_t tmp = block;

    split = (block_t)((char*)block + BLOCK_SIZE + size);
    split->size = block->size / 2 - BLOCK_SIZE;
    split->free = true;
    split->next = tmp->next;
    block->next = split;
    return (block);
}

block_t get_block_ptr(void *ptr)
{
    block_t tmp = get_head(1);

    while (tmp->next) {
        if (tmp == ptr)
            return tmp;
        tmp = tmp->next;
    }
    return (block_t)ptr - 1;
}

int valid_ptr(void *ptr)
{
    block_t tmp = get_head(0);

    if (tmp)
        if (ptr > (void *)tmp && ptr < sbrk(0))
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