#ifndef MINIMAX
#define MINIMAX

#include <cstdlib>
#include <algorithm>
#include <climits>
#include "node.h"

template <typename T>
class minimax {
private:
	node<T> *root;
	bool first;

	void populate(node<T> *n, int d);
	int iterate();
	int alphabeta(node<T> *n, int a, int b, bool maxPlayer, bool first);

public:
	minimax();
	~minimax();

	node<T>* getRoot();
	bool getFirst();

	void select();
	void play();
};

#endif