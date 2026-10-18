#pragma once

#include "init/parser.h"
#include <stddef.h>

typedef enum IROp
{
	IR_ADD,		 // *ptr += arg	 (peut être négatif)
	IR_MOVE,	 // ptr += arg	 (peut être négatif)
	IR_SET,		 // *ptr = arg	 (généré après optimisation)
	IR_OUTPUT,	 // write(1, ptr, 1)
	IR_INPUT,	 // read(0, ptr, 1)
	IR_LOOP_BEG, // if (*ptr == 0) goto LOOP_END[target]
	IR_LOOP_END, // if (*ptr != 0) goto LOOP_BEG[target]
	IR_MUL_COPY, // ptr[offset] += *ptr * factor  (optimisation)
	IR_NOP,		 // (optimisation uniquement)
} IROp_t;

typedef struct IRInstr
{
	IROp_t op;
	int arg;
	int offset;
} IRInstr_t;

void gen_ir_nodes(PagedVector_t *prog, Node_t *nodes, size_t n);
