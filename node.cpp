#include "node.h"

template <typename T>
node<T>::node() {
	data = new T();
	child = nullptr;
}

template <typename T>
node<T>::node(const node<T> &n) {
	data = new T();
	*data = *n.data;
	child = nullptr;
}

template <typename T>
node<T>::~node() {
	delete data;
	delete child;
	for (node<T> *child : children)
		delete child;
}

template <typename T>
T* node<T>::getData() {
	return data;
}

template <typename T>
void node<T>::set_child(node<T> *n) {
	child = n;
}

template <typename T>
void node<T>::add_child(node<T> *n) {
	children.push_back(n);
}
