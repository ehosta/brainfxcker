#include "utils/paged_vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PagedVector_t *pv_create(size_t sib)
{
	PagedVector_t *res = malloc(sizeof(PagedVector_t));
	if (!res)
		return NULL;

	res->pages = NULL;
	res->page_count = 0;
	res->count = 0;
	res->sib = sib;
	return res;
}

void *pv_get(PagedVector_t *vec, size_t i)
{
	size_t page = i >> PAGE_BITS;
	size_t offset = i & PAGE_MASK;
	return (char *)vec->pages[page] + offset * vec->sib;
}

void *pv_push(PagedVector_t *vec, void *element)
{
	if ((vec->count & PAGE_MASK) == 0)
	{
		void **new_pages =
			realloc(vec->pages, (vec->page_count + 1) * sizeof(void *));
		if (!new_pages)
			return NULL;
		vec->pages = new_pages;

		vec->pages[vec->page_count] = malloc(PAGE_SIZE * vec->sib);
		if (!vec->pages[vec->page_count])
			return NULL;
		++vec->page_count;
	}

	void *slot = pv_get(vec, vec->count);
	memcpy(slot, element, vec->sib);
	++vec->count;
	return slot;
}

void pv_free(PagedVector_t *vec)
{
	for (size_t i = 0; i < vec->page_count; ++i)
		free(vec->pages[i]);
	free(vec->pages);
	free(vec);
}
