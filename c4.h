#ifndef C4
#define C4

#include <iostream>
#include <cstring>
#include <vector>

#define U64 uint64_t
#define HEIGHT 6
#define WIDTH 7

class c4 {
private:
	U64 curr, mask; 
	int moves;

	U64 bottom_mask(int col);
	U64 top_mask(int col);
	bool playable(int col);
	bool alignment(U64 c);
	bool draw(U64 c);
	int evaluate(U64 c);

public:
	c4();
	~c4();

	void play(int col);
	int result(int t, bool p);
	int heuristic(int t);
	std::vector<short> possible();

	void display();
};

#endif