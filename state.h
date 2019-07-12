#ifndef STATE
#define STATE

#include <vector>
#include <iostream>

#define U64 uint64_t

class State {
private:
	const static int HEIGHT = 6, WIDTH = 7;
	U64 curr, mask, moves;
	int score;
	std::vector<State *> children;

	U64 bottom_mask(int col);
	U64 top_mask(int col);

public:
	State();
	State(const State &s);

	std::vector<int> possible_moves();
	void add_child(State *s);
	
	bool playable(int col);
	void play(int col);

	bool check_win();
	void evaluate();
	
	void display();
}

#endif