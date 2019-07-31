#include "heuristics.h"

bool placeable(U64 mask, U8 col, U8 row) {
	return !((U64(1) << (col*WIDTH + (row-1))) & mask);
}

U8 left(U64 mask, U64 s, U64 triple, int _left, U8 row, U8 m) {
	if ((triple & s) == triple) {
		if (_left >= 0 && row > 0 && row <= HEIGHT && placeable(mask, _left, row) && (row)%2 == m%2)
			return row;
	}
	return 255;
}

U8 right(U64 mask, U64 s, U64 triple, int _right, U8 row, U8 m) {
	if ((triple & s) == triple) {
		if (_right < WIDTH && row > 0 && row <= HEIGHT && placeable(mask, _right, row) && (row)%2 == m%2)
			return row;
	}
	return 255;
}

U8 middle(U64 mask, U64 s, U64 triple, int _middle, U8 row, U8 m) {
	if ((triple & s) == triple) {
		if (placeable(mask, _middle, row) && (row)%2 == m%2)
			return row;
	}
	return 255;
}

// Non Zugswang heuristic
// Detects even/odd threat depending on move count and returns row
U8 threat(U64 mask, U64 s, U8 m) {
	U64 triple[9] = {16513, 2113537, 2097281, 65793, 16842753, 16777473, 16644, 2097672, 2129928}; // Magic digits
	U8 _left, _right, _middle, min = 255;
	int i;

	/* Horizontal */
	i = 0;
	while (i <= 33) {
		_left = left(mask, s, triple[0], (i/WIDTH)-1, (i%WIDTH)+1, m);
		_right = right(mask, s, triple[0], (i/WIDTH)+3, (i%WIDTH)+1, m);
		min = std::min({min, _left, _right});
		triple[0] <<= 1, i++;

		if (i%WIDTH == 6)
			triple[0] <<= 1, i++;
	}

	i = 0;
	while (i <= 26) {
		_middle = middle(mask, s, triple[1], (i/WIDTH)+1, (i%WIDTH)+1, m);
		min = std::min({min, _middle});
		triple[1] <<= 1;


		_middle = middle(mask, s, triple[2], (i/WIDTH)+2, (i%WIDTH)+1, m);
		min = std::min({min, _middle});
		triple[2] <<= 1, i++;

		if (i%WIDTH == 6) {
			triple[1] <<= 1;
			triple[2] <<= 1, i++;
		}
	}

	/* Diagonal */
	i = 0;
	while (i <= 31) {
		_left = left(mask, s, triple[3], (i/WIDTH)-1, (i%WIDTH), m);
		_right = right(mask, s, triple[3], (i/WIDTH)+3, (i%WIDTH)+4, m);
		min = std::min({min, _left, _right});
		triple[3] <<= 1;

		_left = left(mask, s, triple[6], (i/WIDTH)-1, (i%WIDTH)+4, m);
		_right = right(mask, s, triple[6], (i/WIDTH)+3, (i%WIDTH), m);
		min = std::min({min, _left, _right});
		triple[6] <<= 1, i++;
		

		if (i%WIDTH == 4) {
			triple[3] <<= 3;
			triple[6] <<= 3, i+=3;
		}
	}

	i = 0;
	while (i <= 23) {
		_middle = middle(mask, s, triple[4], (i/WIDTH)+1, (i%WIDTH)+2, m);
		min = std::min({min, _middle});
		triple[4] <<= 1;

		_middle = middle(mask, s, triple[5], (i/WIDTH)+2, (i%WIDTH)+3, m);
		min = std::min({min, _middle});
		triple[5] <<= 1;

		_middle = middle(mask, s, triple[7], (i/WIDTH)+2, (i%WIDTH)+2, m);
		min = std::min({min, _middle});
		triple[7] <<= 1;

		_middle = middle(mask, s, triple[8], (i/WIDTH)+1, (i%WIDTH)+3, m);
		min = std::min({min, _middle});
		triple[8] <<= 1, i++;

		if (i%WIDTH == 3) {
			triple[4] <<= 4;
			triple[5] <<= 4;
			triple[7] <<= 4;
			triple[8] <<= 4, i+=4;
		}
	}

	if (min <= HEIGHT) {
		return min;
	}

	return 0;
}

bool columns(U64 mask, U8 track[], bool t) {
	for (U8 i = 0; i < WIDTH; i++) {
		std::cout << track[i] << std::endl;
		if ((6-track[i])%2 != t)
			return false;
	}

	return true;
}

// Zugswang heuristic
// Rule 1: Claimeven
int claimEven(U8 col, U64 mask, bool zug) {
	U64 column = (U64(63) << col*WIDTH) & mask;
	U64 spot = U64(1) << col*WIDTH;
	U8 i = 1, h;
	if (zug) {
		while ((spot | column) == column)
			spot <<= 1, i++;
		h = (col*WIDTH + i)%WIDTH;
		if (h < HEIGHT && h%2 == 0)
			return CLAIMEVEN_VALUE;
	}
	return 0;
}

int vertical(U64 mask, U64 s, U8 col) {
	U64 two = U64(3) << (col*WIDTH);
	U64 three = U64(7) << (col*WIDTH);

	int i = 0;
	while (i+3 < HEIGHT) {
		if ((three & s) == three && placeable(mask, col, i+4)) {
			return 10;
		}

		if ((two & s) == two && placeable(mask, col, i+3)) {
			return 5;
		}
		three <<= 1;
		two <<= 1;
		i++;
	}
	return 0;
}

// If the number of empty squares in a column are odd then the function returns true, otherwise false.
bool oddColumns(U64 stateOfTheBoard, U8 column) {
	U64 spot = 1;
	spot <<= U64((HEIGHT+1)*column);
	int counter = 0;

	for (int i = 0; i < HEIGHT; i++) {
		if ((spot & stateOfTheBoard) == spot)
			counter += 1;
		spot <<= U64(1);
	}
	return counter % 2;
}

// If there is 2 or more columns containing an odd number of empty squares and
// the current column is one of those columns, then it returns of heurstic value,
// Assuming the player has the zugswang.
int lowInverse(U64 stateOfTheBoard, U8 column, bool zug) {
	if (zug)
		return 0;

	int oddColumnz = 0;

	for (int i = 0; i < 7; i++)
		if (oddColumns(stateOfTheBoard, i) == true)
			oddColumnz += 1;

	if (oddColumnz >= 2 && (oddColumns(stateOfTheBoard, column) == true))
		return LOWINVERSE_VALUE;

	return 0;
}