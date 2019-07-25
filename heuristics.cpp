#include "heuristics.h"

bool check(U64 mask, U8 col, U8 row) {
	return !((U64(1) << (col*WIDTH + row)) & mask);
}

// Detects even/odd threat depending on move count and returns row
U8 threat(U64 mask, U64 s, U8 m) {
	U64 triple = 0; 
	U8 left, right, i, j;

	// Horizontal
	for (i = 0; i < WIDTH-2; i++) {
		for (j = 0; j < HEIGHT; j++) {
			triple = 16513; // Magic number
			triple <<= (i*WIDTH)+j; // Shifting
			if ((triple & s) == triple) {
				left = i-1, right = i+3; // Also magic
				if (left >= 0 && check(mask, left, j) && (j+1)%2 == m%2)
					return j+1;
				if (right < WIDTH && check(mask, right, j) && (j+1)%2 == m%2)
					return j+1;
			}
		}
	}

	// Diagonals
	for (i = 0; i < WIDTH-2; i++) {
		for (j = 0; j < HEIGHT-2; j++) {
			triple = 65793; // Magic number | left to right diagonal
			triple <<= (i*WIDTH)+j;
			if ((triple & s) == triple) {
				left = i-1, right = i+3; // Also magic
				if (left >= 0 && (j-1) >= 0 && check(mask, left, j-1) && (j)%2 == m%2)
					return j;
				if (right < WIDTH && (j+3) < HEIGHT && check(mask, right, j+3) && (j+4)%2 == m%2)
					return j+4;
			}

			triple = 16644; // Magic number | right to left diagonal
			triple <<= (i*WIDTH)+j;
			if ((triple & s) == triple) {
				left = i-1, right = i+3; // Also magic
				if (left >= 0 && (j+3) < HEIGHT && check(mask, left, j+3) && (j+4)%2 == m%2)
					return j+4;
				if (right < WIDTH && (j-1) >= 0 && check(mask, right, j-1) && (j)%2 == m%2)
					return j;
			}
		}
	}

	return 0;
}
