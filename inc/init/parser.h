#pragma once

#include "utils/paged_vector.h"
#include <stddef.h>

typedef enum NodeKind
{
	NODE_INC_PTR,
	NODE_DEC_PTR,
	NODE_INC_VAL,
	NODE_DEC_VAL,
	NODE_OUTPUT,
	NODE_INPUT,
	NODE_LOOP
} NodeKind_t;

typedef struct Node
{
	NodeKind_t kind;
	struct Node *children;
	size_t child_count;
	size_t line, col;
} Node_t;

typedef struct AST
{
	Node_t *nodes;
	size_t count;
} AST_t;

void free_nodes(Node_t *nodes, size_t count);
size_t parse_block(PagedVector_t *tokens, size_t start, size_t len,
				   Node_t **out, size_t *out_count);
