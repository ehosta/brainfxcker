#include "init/args.h"
#include "utils/paged_vector.h"
#include <stddef.h>
#include <string.h>

PagedVector *parse_args(int argc, char *argv[])
{
	PagedVector *out = pv_create(sizeof(Arg));

	for (size_t i = 0; i < (size_t)argc; ++i)
	{
		const char *s = argv[i];

		if (!strcmp(s, "-h") || !strcmp(s, "--help"))
		{
			pv_push();
		}
	}

	return out;
}
