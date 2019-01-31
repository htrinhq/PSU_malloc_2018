/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** show_alloc_mem
*/

#include "malloc.h"

void show_alloc_mem(void)
{
    block_t tmp = get_head(1);

    setvbuf(stdout, NULL, _IONBF, 0);
    printf("break : %p\n", sbrk(0));
    while (tmp->next) {
        printf("%p - %p : %ld bytes\n", tmp + 1,
        (tmp + 1 + BLOCK_SIZE + tmp->size), tmp->size);
        tmp = tmp->next;
    }
}
