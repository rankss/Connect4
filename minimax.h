#ifndef MINIMAX
#define MINIMAX

#include "node.h"

class minimax {
private:
	// node *root;

public:
	minimax();
	~minimax();

	void populate();
	int backpropagation();
};

#endif