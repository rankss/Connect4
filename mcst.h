#ifndef MCST
#define MCST

#include "node.h"

template <typename T>
class mcst {
private:
	node<T> *root;

public:
	mcst();
	~mcst();

	node<T>* getRoot();

	void playout();
	int backpropagation();
};

#endif