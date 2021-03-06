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
    static bool first = true;
    void *block;

    if (first) {
        block = sbrk(BLOCK_SIZE + size);
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
    block_t tmp = get_head(size);
    block_t new;

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
    if (block->size >= (size + BLOCK_SIZE))
        block = split_block(block, size);
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
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    if (!size)
        return NULL;
    pthread_mutex_lock(&mutex);
    size = (size < (size_t)getpagesize()) ? ALIGN(size) : ALIGNPAGE(size);
    header = find_block(size);
    if (header) {
        header->free = false;
        header->size = size;
        pthread_mutex_unlock(&mutex);
        return (void *)(header + 1);
    } else {
        header = new_block(size);
        pthread_mutex_unlock(&mutex);
        if (!header)
            return NULL;
    }
    pthread_mutex_unlock(&mutex);
    return (void *)(header + 1);
}
