#ifndef MCST
#define MCST

#include "node.h"

template <typename T>
class mcst {
private:
	node<T> *root;
	bool first;

	void playout(node<T> *n, int p);
	void populate();
	int backpropagate(node<T> *n);

public:
	mcst(bool f);
	~mcst();

	node<T>* getRoot();

	void select();
	void play();
};

#endif
