#ifndef HEURISTICS
#define HEURISTICS

#include <cstdint>

#define U64 uint64_t
#define U8 short
#define HEIGHT 6
#define WIDTH 7

bool check(U64 mask, U8 col, U8 row);
int threat(U64 mask, U64 s);

#endif