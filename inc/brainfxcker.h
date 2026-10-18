#pragma once

typedef enum OptimizationLevel
{
	ANY,
	NO_DUPP
} OptimizationLevel_t;

typedef struct Brainfxcker
{
	char *binary_path;
	OptimizationLevel_t optimization_level;
} Brainfxcker_t;
