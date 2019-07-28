#ifndef HMCST
#define HMCST

#include "node.h"

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

};

#endif
