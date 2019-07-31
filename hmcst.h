#ifndef HMCST
#define HMCST

#include <cstdlib>
#include <algorithm>
#include <climits>
#include "node.h"

#define P 25000

template <typename T>
class hmcst {
private:
	node<T> *root;
	bool first;

	void playout(node<T> *n);
	void populate();
	int backpropagate(node<T> *n);

public:
	hmcst();
	~hmcst();

	node<T>* getRoot();
	bool getFirst();

	void select();
	void play();
};

#endif
