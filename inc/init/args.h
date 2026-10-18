#pragma once

#include <stddef.h>

typedef enum ArgType
{
	ARG_PARAM,
	ARG_OPT
} ArgType_t;

typedef enum ParamName
{
	ARG_ASM_OUTPUT,
	ARG_BINARY_NAME,
	ARG_OPTI_FLAG
} ParamName_t;
typedef enum OptionName
{
	ARG_HELP
} OptionName_t;

typedef struct Param
{
	ParamName_t name;
	char *value;
} Param_t;

typedef struct Option
{
	OptionName_t name;
	char *value;
} Option_t;

typedef struct BrainfxckerArgs
{
	Param_t **params_value;
	size_t params_count;
	Option_t **options_value;
	size_t options_count;
} BrainfxckerParams_t;
