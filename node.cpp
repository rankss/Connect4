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
	//std::cout << "...calling node dtor" << std::endl;
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
void node<T>::setChild(node<T> *n) {
	if (child != nullptr) {
		delete child;
		child = nullptr;
	}
	child = n;
}

template <typename T>
void node<T>::addChild(node<T> *n) {
	children.push_back(n);
}

template <typename T>
int node<T>::getScore() {
	return score;
}

template <typename T>
void node<T>::setScore(int s) {
	score = s;
}

template class node<c4>;
