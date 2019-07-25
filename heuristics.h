#ifndef HEURISTICS
#define HEURISTICS

#include <cstdint>
#include <vector>
#include <iostream>

#define U64 uint64_t
#define U8 short
#define HEIGHT 6
#define WIDTH 7

bool check(U64 mask, U8 col, U8 row);
U8 threat(U64 mask, U64 s, U8 m);

#endif