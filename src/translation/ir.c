#include "translation/ir.h"
#include "init/parser.h"
#include "utils/paged_vector.h"
#include <stddef.h>
#include <stdlib.h>

void gen_ir_nodes(PagedVector_t *prog, Node_t *nodes, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		switch (nodes[i].kind)
		{
		case NODE_INC_PTR:
			pv_push(prog, &(IRInstr_t){IR_MOVE, +1, 0});
			break;
		case NODE_DEC_PTR:
			pv_push(prog, &(IRInstr_t){IR_MOVE, -1, 0});
			break;
		case NODE_INC_VAL:
			pv_push(prog, &(IRInstr_t){IR_ADD, +1, 0});
			break;
		case NODE_DEC_VAL:
			pv_push(prog, &(IRInstr_t){IR_ADD, -1, 0});
			break;
		case NODE_OUTPUT:
			pv_push(prog, &(IRInstr_t){IR_OUTPUT, 0, 0});
			break;
		case NODE_INPUT:
			pv_push(prog, &(IRInstr_t){IR_INPUT, 0, 0});
			break;
		case NODE_LOOP:
		{
			size_t open_idx = prog->count;
			pv_push(prog, &(IRInstr_t){IR_LOOP_BEG, 0, 0});
			gen_ir_nodes(prog, nodes[i].children, nodes[i].child_count);
			size_t close_idx = prog->count;
			pv_push(prog, &(IRInstr_t){IR_LOOP_END, (int)open_idx, 0});
			((IRInstr_t *)(pv_get(prog, open_idx)))->arg = (int)close_idx;
			break;
		}
		}
	}
}
