#ifndef NODE
#define NODE

#include <vector>
#include "c4.h"

template <typename T>
class node {
private:
	T* data;
	int score;
	node<T> *child;
	std::vector< node<T> *> children;

public:
	node();
	node(const node<T> &n);
	~node();

	T* getData();
	node<T>* getChild();
	int getScore();
	void setScore(int s);

	void setChild(node<T> *n);
	void addChild(node<T> *n);

};

#endif
