#ifndef MINIMAX
#define MINIMAX

#include "node.h"

template <typename T>
class minimax {
private:
	node<T> *root;
	bool first;

public:
	minimax(bool f);
	~minimax();

	void populate();
	int backpropagate();
};

#endif