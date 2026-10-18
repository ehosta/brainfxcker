#include "init/args.h"
#include "utils/paged_vector.h"
#include <stddef.h>
#include <string.h>

PagedVector_t *parse_args(int argc, char *argv[])
{
	PagedVector_t *out = pv_create(1);

	(void)argc;
	(void)argv;

	return out;
}
