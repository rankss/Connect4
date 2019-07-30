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
	if (d == 0 || n->getData()->result(first, false)) return;

	// if (n->getChildren().size() > 0)
	// 	for (node<T> *child : n->getChildren())
	// 		populate(child, d - 1);

	node<T> *c;
	for (int m : root->getData()->possible()) {
		c = new node<T>(*n);
		c->play(m);
		//c->getData()->display();
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
int minimax<T>::alphabeta(node<T> *n, int a, int b, bool maxPlayer) {
	if (n->getChildren().empty()) {
		n->getData()->display();
		std::cout << n->getData()->heuristic(maxPlayer) << std::endl;
		return n->getData()->heuristic(maxPlayer);
	}

	int value;
	if (maxPlayer) {
		value = INT_MIN;
		for (node<T> *c : n->getChildren()) {
			value = std::max(value, alphabeta(c, a, b, !maxPlayer));
			a = std::max(a, value);
			n->setScore(a);
			if (a >= b) break;
		}
	} else {
		value = INT_MAX;
		for (node<T> *c : n->getChildren()) {
			value = std::min(value, alphabeta(c, a, b, !maxPlayer));
			b = std::min(b, value);
			n->setScore(b);
			if (a >= b) break;
		}
	}

	return value;
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
	populate(root, 3);
	int s = alphabeta(root, INT_MIN, INT_MAX, first);
	int idx = root->find(s);
	for (uint i = 0; i < root->getChildren().size(); i++) {
		if (int(i) != idx) {
			delete root->getChildren()[i];
		}
	}
	node<T> *n = root->getChildren()[idx];
	std::vector <node <T> *> v;
	root->setChildren(v);
	delete root;
	root = n;
}

template <typename T>
void minimax<T>::play() {
	// Player move
}

template class minimax<c4>;
