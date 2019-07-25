#include "heuristics.h"
#include <iostream>

bool check(U64 mask, U8 col, U8 row) {
	return !((U64(1) << (col*WIDTH + row)) & mask);
}

// Detects even/odd threat depending on move count and returns row
int threat(U64 mask, U64 s) {
	U64 triple = 0; // Magic number
	U8 left, right;
	for (int i = 0; i < WIDTH-2; i++) {
		for (int j = 0; j < HEIGHT-1; j++) {
			triple = U64(16513);
			triple <<= (i*WIDTH)+j;
			//std::cout << triple << " " << s << std::endl;
			if ((triple & s) == triple) {
				left = i-1, right = i+3; // Also magic
				if (left >= 0 && right <= 6) {
					if (check(mask, left, j) || check(mask, right, j))
						return j+1;
				} else if (left >= 0 && right > 6) {
					if (check(mask, left, j))
						return j+1;
				} else if (left < 0 && right <= 6) {
					if (check(mask, right, j))
						return j+1;
				}
			}
		}
	}
	return 0;
}
