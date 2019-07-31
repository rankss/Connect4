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
#define LOWINVERSE_VALUE 10

U8 threat(U64 mask, U64 s, U8 m);
bool columns(U64 mask, U8 track[], bool t);

int claimEven(U8 col, U64 mask, bool zug);
int vertical(U64 mask, U64 s, U8 col);
int lowInverse(U64 stateOfTheBoard, U8 column, bool zug);


#endif