#include "c4.h"

c4::c4() {
	curr = 0;
	mask = 0;
	moves = 0;
}

c4::~c4() {
	std::cout << "...calling c4 dtor" << std::endl;
}

U64 c4::top_mask(int col) {
	return (U64(1) << (HEIGHT - 1) << col*(HEIGHT + 1));
}

U64 c4::bottom_mask(int col) {
	return (U64(1) << col*(HEIGHT + 1));
}

bool c4::playable(int col) {
	return !(mask & top_mask(col));
}

bool c4::play(int col) {
	if (playable(col)) {
		curr ^= mask;
		mask |= mask + bottom_mask(col);
		moves++;
		return true;
	}
	return false;
}

bool c4::check_win() {
	// Checks if state c is a win
	U64 c = curr^mask, w;
	// Vertical
	w = c & (c >> 1);
	if (w & (w >> 2)) return true;
	// Horizontal
	w = c & (c >> (HEIGHT + 1));
	if (w & (w >> (2 * (HEIGHT + 1)))) return true;
	// Diagonals
	w = c & (c >> HEIGHT);
	if (w & (w >> (2 * HEIGHT))) return true;
	w = c & (c >> (HEIGHT + 2));
	if (w & (w >> (2 * (HEIGHT + 2)))) return true;

	return false;
}

int c4::evaluate() {
	// Makes an estimated score of current board state
	return 0;
}

void c4::display() {
	/*  
		Prints bitboard to console
		.  .  .  .  .  .  .
		5 12 19 26 33 40 47
		4 11 18 25 32 39 46
		3 10 17 24 31 38 45
		2  9 16 23 30 37 44
		1  8 15 22 29 36 43
		0  7 14 21 28 35 42 
		To be done
	*/
	std::cout << "Turn: " << moves << std::endl;

	std::string bin_cur = "", bin_opp = "";
	U64 cur, opp;
	if (moves%2)
		cur = curr^mask , opp = curr;
	else
		cur = curr, opp = curr^mask;

	int length = 64;
	while (length--) {
		bin_cur += (cur%2 == 0 ? '0' : '1');
		bin_opp += (opp%2 == 0 ? '0' : '1');
		cur/=2;
		opp/=2;
	}

	for (int i = 6; i >= 0; i--) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 6)
				std::cout << ". ";
			else {
				if (bin_cur[i+j*WIDTH] == '1')
					std::cout << "O ";
				else if(bin_opp[i+j*WIDTH] == '1')
					std::cout << "X ";
				else
					std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
}