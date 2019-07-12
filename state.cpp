#include "state.h"

State::State() {
	curr = 0;
	mask = 0;
	moves = 0;
	score = 0;
}

State::State(const State &s) {
	curr = s.curr;
	mask = s.mask;
	moves = s.moves;
	score = 0;
}

U64 State::top_mask(int col) {
	return (1 << (HEIGHT - 1) << col*(HEIGHT - 1));
}

U64 State::bottom_mask(int col) {
	return (1 << col*(HEIGHT - 1));
}

std::vector<int> possible_moves() {
	std::vector<int> moves;
	for (int i = 0; i < WIDTH; i++) {
		if (playable(i)) {
			moves.push_back(i);
		}
	}
	return moves
}

void State::add_child(State *s) {
	children.push_back(s);
}

bool State::playable(int col) {
	return !(mask & top_mask(col))
}

void State::play(int col) {
	curr ^= mask;
	mask |= mask + bottom_mask(col);
	moves++;
}

bool State::check_win() {
	return false;
}

void State::evaluate() {
	score = 0;
}

void State::display() {
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
}
