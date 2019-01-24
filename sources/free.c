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

void free(void *ptr)
{
    block_t header = (block_t)ptr - 1;
    block_t tmp;
    void *end = sbrk(0);

    if ((char *)ptr + header->size == end) {
        tmp = head;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        tmp->next = NULL;
        sbrk(0 - (sizeof(block_t) + header->size));
    } else {
        header->free = true;
        fusion_block(header);
    }
}