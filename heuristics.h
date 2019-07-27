#ifndef HEURISTICS
#define HEURISTICS

#include <cstdint>
#include <algorithm>
#include <iostream>

#define U64 uint64_t
#define U8 short
#define HEIGHT 6
#define WIDTH 7

#define CLAIMEVEN_VALUE 10
#define CREATETHREAT_VALUE 1000

U8 threat(U64 mask, U64 s, U8 m);
int claimEven(U8 col, U64 mask, bool zug);

#endif