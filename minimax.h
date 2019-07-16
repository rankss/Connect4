#ifndef MINIMAX
#define MINIMAX

#include "node.h"

template <typename T>
class minimax {
private:
	node<T> *root;

public:
	minimax();
	~minimax();

	void populate();
	int backpropagate();
};

#endif