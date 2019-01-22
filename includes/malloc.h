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

typedef struct s_block *t_block;

struct s_block {
	size_t size;
	t_block next;
	bool_t free;
};

#endif
