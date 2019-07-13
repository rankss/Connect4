#include "node.h"

template <typename T>
node<T>::node() {
	data = new T();
	score = 0;
	child = nullptr;
}

template <typename T>
node<T>::node(const node<T> &n) {
	data = new T();
	*data = *n.data;
	score = 0;
	child = nullptr;
}

template <typename T>
node<T>::~node() {
	std::cout << "...calling node dtor" << std::endl;
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
node<T>* node<T>::getChild() {
	return child;
}

template <typename T>
int node<T>::getScore() {
	return score;
}

template <typename T>
void node<T>::setScore(int s) {
	score = s;
}

template <typename T>
void node<T>::set_child(node<T> *n) {
	child = n;
}

template <typename T>
void node<T>::add_child(node<T> *n) {
	children.push_back(n);
}

template class node<c4>;
