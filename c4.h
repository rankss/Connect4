#ifndef C4
#define C4

#include <iostream>
#include <cstring>
#define U64 uint64_t

class c4 {
private:
	const static int HEIGHT = 6, WIDTH = 7;

	U64 curr, mask; 
	int moves;

	U64 bottom_mask(int col);
	U64 top_mask(int col);
	bool playable(int col);

public:
	c4();
	c4(const c4 &s);

	bool play(int col);
	bool check_win();

	void display();
};

#endif