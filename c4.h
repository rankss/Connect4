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

public:
	c4();
	~c4();

	bool playable(int col);
	bool play(int col);
	bool alignment();
	int evaluate();
	std::vector<int> possible();

	void display();
};

#endif