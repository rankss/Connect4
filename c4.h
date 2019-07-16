#ifndef C4
#define C4

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>

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

public:
	c4();
	~c4();

	bool play(int col);
	int evalMCST(int t);
	int evalMinimax();
	std::vector<int> possible();

	void display();
};

#endif