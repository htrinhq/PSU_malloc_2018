/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc.h,
*/
#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#include <unistd.h>
#include <stdint.h>

typedef uint8_t bool_t;
#define true 1
#define false 0
#define ALIGN(x)  (((((x) - 1) >> 2) << 2) + 4)
#define BLOCK_SIZE sizeof(struct s_block)

typedef struct s_block *block_t;

struct s_block {
	size_t size;
	block_t next;
	bool_t free;
};

block_t head;

void *malloc(size_t size);
block_t new_block(size_t size);
block_t find_block(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem(void);
void free(void *ptr);
block_t fusion_block(block_t block);
block_t get_block_ptr(void *ptr);
block_t split_block(block_t block, size_t size);

#endif
