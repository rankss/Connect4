#ifndef NODE
#define NODE

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
	void setChild(node<T> *n);
	void addChild(node<T> *n);
	int getScore();
	void setScore(int s);
};

#endif
