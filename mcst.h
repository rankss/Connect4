#ifndef MCST
#define MCST

#include "node.h"

class mcst {
private:
	// node<T> *root;

public:
	mcst();
	~mcst();

	void playout();
	int backpropagation();
};

#endif