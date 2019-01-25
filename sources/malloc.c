/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc.c,
*/

#include "malloc.h"

void *head = NULL;

block_t new_block(size_t size)
{
    void *block = sbrk(BLOCK_SIZE + size);
    block_t new;

    if (block == (void *)-1)
        return NULL;
    new = block;
    new->size = size;
    new->free = false;
    new->next = NULL;
    if (!head)
        head = new;
    return new;
}

block_t check_size(block_t  block, size_t size)
{
    if (block->size >= ((2 * size) + BLOCK_SIZE))
        block = split_block(block, size);
    return block;
}

block_t find_block(size_t size)
{
    block_t current = head;

    while (current) {
        if (current->free && current->size >= size) {
            return check_size(current, size);
        } else if (current->free)
            current = fusion_block(current);
        current = current->next;
    }
    return NULL;
}

void *malloc(size_t size)
{
    block_t header;

    size = ALIGN(size);
    if (!size)
        return NULL;
    header = find_block(size);
    if (header) {
        header->free = false;
        return (void *)(header + 1);
    } else {
        header = new_block(size);
        if (!header)
            return NULL;
    }
    return (void *)(header + 1);
}
