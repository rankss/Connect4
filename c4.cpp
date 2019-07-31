#include "c4.h"

c4::c4() {
	curr = 0;
	mask = 0;
	moves = 0;
	std::memset(track, 0, sizeof(track));
	zug = false;
}

c4::~c4() {
}

U64 c4::top_mask(U8 col) {
	return (U64(1) << (HEIGHT - 1) << col*(HEIGHT + 1));
}

U64 c4::bottom_mask(U8 col) {
	return (U64(1) << col*(HEIGHT + 1));
}

bool c4::playable(U8 col) {
	return !(mask & top_mask(col));
}

bool c4::alignment(U64 c) {
	// Checks if state c is a win
	U64 w = 0;
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

bool c4::draw(U64 c) {
	if (moves >= HEIGHT*WIDTH && !alignment(c))
		return true;
	return false;
}

void c4::getZug() {
	if (!zug) {
		zug = true;
		//std::cout << "AI gain control of Zugswang" << std::endl;
	}
	
}

void c4::giveZug() {
	if (zug) {
		zug = false;
		//std::cout << "AI lost control of Zugswang" << std::endl;
	}
}

void c4::setZug(bool z) {
	zug = z;
}

U8 c4::getMoves() {
	return moves;
}

void c4::play(U8 col) {
	curr ^= mask;
	mask |= mask + bottom_mask(col);
	moves++;
	track[col]++;
}

int c4::result(bool t, bool p) {
	U64 c = curr^mask;

	if (alignment(c)) {
		if (moves%2 == t) {
			if (p) std::cout << "AI wins." << std::endl;
			return 3000;
		}
		else {
			if (p) std::cout << "Player wins." << std::endl;
			return -5000;
		}
	} else if (draw(c)) {
		if (p) std::cout << "Draw." << std::endl;
		return 1000;
	}

	return 0;
}

int c4::heuristic_fp() {
	U64 c = curr^mask;
	int score = 0;
	//std::cout << "First player heurtistic" << std::endl;
	if (threat(mask, c, moves)) {
		getZug();
		score += 50;
	}
	else {
		giveZug();
	}

	if (threat(mask, c^mask, moves-1)) {
		score -= 50;
	}

	for (int i = 0; i < WIDTH; i++) {
		score += vertical(mask, c, i);
		score -= vertical(mask, c^mask, i);
	}

	if (alignment(c)) return 1000;
	if (alignment(c^mask)) return -1000;

	return score;
}

int c4::heuristic_sp() {
	U64 c = curr;
	int score = 0;
	//std::cout << "Second player heurtistic" << std::endl;
	if (threat(mask, c, moves-1)) {
		giveZug();
		score -= 50;
	}
	else {
		getZug();
		score += 50;
	}

	if (threat(mask, c^mask, moves)) {
		score += 50;
	}

	for (int i = 0; i < WIDTH; i++) {
		score += vertical(mask, c^mask, i);
		score -= vertical(mask, c, i);
	}

	if (alignment(c)) return 1000;
	if (alignment(c^mask)) return -1000;

	return score;
}

int c4::heuristic(bool t) {
	if (moves%2 == t) return heuristic_fp();
	else return heuristic_sp();
}

std::vector<U8> c4::possible() {
	U8 all[7] = {3,4,2,5,1,6,0};
	std::vector<U8> moves;
	for (U8 i = 0; i < 7; i++) {
		if (playable(all[i])) {
			moves.push_back(all[i]);
		}
	}
	return moves;
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
	*/
	if (moves)
		std::cout << "Turn: " << moves << std::endl;
	else
		std::cout << "Game Start" << std::endl;

	std::string bin_c = "", bin_o = "";
	U64 c, o;
	if (moves%2)
		c = curr^mask, o = curr;
	else
		c = curr, o = curr^mask;

	int length = 64;
	while (length--) {
		bin_c += (c%2 == 0 ? '0' : '1');
		bin_o += (o%2 == 0 ? '0' : '1');
		c/=2;
		o/=2;
	}

	for (int i = 6; i >= 0; i--) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 6)
				std::cout << j << " ";
			else {
				if (bin_c[i+j*WIDTH] == '1')
					std::cout << "O ";
				else if(bin_o[i+j*WIDTH] == '1')
					std::cout << "X ";
				else
					std::cout << "- ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
