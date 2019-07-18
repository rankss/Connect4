#include "minimax.h"

template <typename T>
minimax<T>::minimax() {
	root = new node<T>();
	first = rand() % 2;
}

template <typename T>
minimax<T>::~minimax() {
	delete root;
}

template <typename T>
void minimax<T>::populate(node<T> *n, int d) {
	// Populates tree until depth d
	if (d == 0) return;

	if (n->getChildren().size() > 0)
		for (node<T> *child : n->getChildren())
			populate(child, d - 1);

	node<T> *c;
	for (int m : root->getData()->possible()) {
		c = new node<T>(*n);
		c->getData()->play(m);
		n->addChild(c);
		populate(c, d - 1);
	}
	return;
}

template <typename T>
int minimax<T>::iterate() {
	return 0;
}

template <typename T>
int minimax<T>::alphabeta(node<T> *n, int a, int b) {
	if (n->getChildren().empty())
		return n->getData()->heuristic();
	if (first) {

	}
	return 0;
}

template <typename T>
node<T>* minimax<T>::getRoot() {
	return root;
}

template <typename T>
bool minimax<T>::getFirst() {
	return first;
}

template <typename T>
void minimax<T>::select() {
	// AI move
	populate(root, 7);
	//alphabeta();
}

template <typename T>
void minimax<T>::play() {
	// Player move
}

template class minimax<c4>;
