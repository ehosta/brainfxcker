#pragma once

#include "utils/paged_vector.h"
#include <stddef.h>

typedef enum TokenKind
{
	TOK_INC_PTR,	// >
	TOK_DEC_PTR,	// <
	TOK_INC_VAL,	// +
	TOK_DEC_VAL,	// -
	TOK_OUTPUT,		// .
	TOK_INPUT,		// ,
	TOK_LOOP_OPEN,	// [
	TOK_LOOP_CLOSE, // ]
} TokenKind_t;

typedef struct Token
{
	TokenKind_t kind;
	size_t line;
	size_t col;
} Token_t;

PagedVector_t *lex_file(const char *path);
void free_token_list(PagedVector_t *tl);
