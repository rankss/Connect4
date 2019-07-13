#ifndef MCST
#define MCST

#include <cstdlib>
#include "node.h"

template <typename T>
class mcst {
private:
	node<T> *root;

	void playout(node<T> *n, int p);
	int backpropagation(node<T> *n);

public:
	mcst();
	~mcst();

	node<T>* getRoot();

	void populate();
};

#endif