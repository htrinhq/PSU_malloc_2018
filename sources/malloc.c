/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** malloc.c,
*/

#include "malloc.h"

t_block new(size_t size)
{
	t_block new = sbrk(0);
if (sbrk(BLOCK_SIZE + size) == (void *) -1)
		return NULL;
	new->size = size;
	new->free = false;
	new->next = NULL;
	return new;
}

void *malloc(size_t size)
{

}
