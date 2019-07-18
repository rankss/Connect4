#ifndef NODE
#define NODE

#include "c4.h"

template <typename T>
class node {
private:
	T* data;
	
	node<T> *child;
	std::vector< node<T> *> children;

	int score, move;

public:
	node();
	node(const node<T> &n);
	~node();

	T* getData();
	node<T>* getChild();
	void setChild(node<T> *n);
	void addChild(node<T> *n);
	std::vector< node<T> *> getChildren();
	int getScore();
	void setScore(int s);
	int getMove();
	void setMove(int m);
};

#endif
