#include "c4.h"

c4::c4() {
	curr = 0;
	mask = 0;
	moves = 0;
}

c4::c4(const c4 &s) {
	curr = s.curr;
	mask = s.mask;
	moves = s.moves;
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
	return false;
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
	std::string bin_cur = "", bin_opp = "";
	U64 cur, opp;
	if (moves%2)
		cur = curr, opp = curr ^= mask;
	else
		opp = curr, cur = curr ^= mask;

	int length = 64;
	while (length--) {
		bin_cur += (cur%2 == 0 ? '0' : '1');
		bin_opp += (opp%2 == 0 ? '0' : '1');
		cur/=2;
		opp/=2;
	}
	std::cout << bin_cur << std::endl;
	std::cout << bin_opp << std::endl;
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