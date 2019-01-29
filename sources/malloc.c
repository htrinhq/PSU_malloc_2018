/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc.c,
*/

#include "malloc.h"

block_t get_head(size_t size)
{
    static block_t head = NULL;
    static bool_t first = true;

    if (first) {
        void *block = sbrk(BLOCK_SIZE + size);
        if (block == (void *)-1)
            return NULL;
        head = block;
        head->size = size;
        head->free = false;
        head->next = NULL;
        first = false;
    }
    return (head);
}

block_t new_block(size_t size)
{
    void *block = sbrk(BLOCK_SIZE + size);
    block_t new;
    block_t tmp = get_head(size);

    if (block == (void *)-1)
        return NULL;
    new = block;
    new->size = size;
    new->free = false;
    new->next = NULL;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return new;
}

block_t check_size(block_t block, size_t size)
{
    if (block->size > (size + BLOCK_SIZE)) {
        block = split_block(block, size);
    }
    return block;
}

block_t find_block(size_t size)
{
    block_t current = get_head(1);

    while (current->next) {
        if (current->free && current->size > size)
            return check_size(current, size);
        current = current->next;
    }
    return NULL;
}

void *malloc(size_t size)
{
    block_t header;

    if (!size)
        return NULL;
    header = find_block(size);
    if (header) {
        header->free = false;
        header->size = size;
        return (void *)(header + 1);
    } else {
        header = new_block(size);
        if (!header)
            return NULL;
    }
    return (void *)(header + 1);
}
