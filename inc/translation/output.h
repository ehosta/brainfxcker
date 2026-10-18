#pragma once

#include <stddef.h>
#include <stdio.h>

typedef enum OutputDataType
{
	OUTPUT_ASM,
	OUTPUT_OBJECT,
} OutputDataType_t;

typedef struct OutputData
{
	OutputDataType_t type;
	char *path;
	size_t path_len;
	char *cmd;
	size_t cmd_len;
	FILE *file;
} OutputData_t;

typedef struct Output
{
	OutputData_t asm_;
	OutputData_t object;
} Output_t;

Output_t create_output(const char *path);
void free_output(Output_t *out);
