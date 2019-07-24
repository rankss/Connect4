#ifndef MCST
#define MCST

#include <climits>
#include "node.h"

#define P 25000 //3412223034455066611

template <typename T>
class mcst {
private:
	node<T> *root;
	bool first;

	void playout(node<T> *n);
	void populate();
	int backpropagate(node<T> *n);

public:
	mcst();
	~mcst();

	node<T>* getRoot();
	bool getFirst();

	void select();
	void play();
};

#endif
