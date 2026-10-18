#pragma once

#include <stddef.h>

#define PAGE_BITS 6
#define PAGE_SIZE (1 << PAGE_BITS)
#define PAGE_MASK (PAGE_SIZE - 1)

typedef struct PagedVector
{
	void **pages;
	size_t page_count;
	size_t count;
	size_t sib;
} PagedVector_t;

PagedVector_t *pv_create(size_t sib);
void *pv_get(PagedVector_t *vec, size_t i);
void *pv_push(PagedVector_t *vec, void *element);
void pv_free(PagedVector_t *vec);
