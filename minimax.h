#ifndef MINIMAX
#define MINIMAX

#include "state.h"

class Minimax {
private:
	State *root;

public:
	Minimax();
	~Minimax();

	void populate();
	int backpropagation();
}

#endif