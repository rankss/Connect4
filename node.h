#ifndef NODE
#define NODE

#include <vector>

template <typename T>
class node {
private:
	T* data;
	node<T> *child;
	std::vector< node<T> *> children;

public:
	node();
	node(const node<T> &n);
	~node();

	T* getData();
	void set_child(node<T> *n);
	void add_child(node<T> *n);

};

#endif
