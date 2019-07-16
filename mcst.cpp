#include "mcst.h"

template <typename T>
mcst<T>::mcst() {
	root = new node<T>();
}

template <typename T>
mcst<T>::~mcst() {
	std::cout << "...calling mcst dtor" << std::endl;
	delete root;
}

template <typename T>
int mcst<T>::backpropagation(node<T> *n) {
	if (n->getChild() == nullptr)
		return n->getScore();
	n->setScore(n->getScore() + backpropagation(n->getChild()));
	return n->getScore();
}

template <typename T>
node<T>* mcst<T>::getRoot() {
	return root;
}

template <typename T>
void mcst<T>::playout(node<T> *n, int p) {
	int move;
	std::vector<int> moves;
	node<T> *c = nullptr, *curr = n;
	while (p--) {
		// Do a playout
		while (!curr->getData()->alignment()) {
			// Generate random playouts
			// Be careful of memory leaks (use valgrind)
			moves = curr->getData()->possible(); // Get all possible moves
			move = moves[rand() % moves.size()]; // Select random move
			c = new node<T>(*curr);
			c->getData()->play(move); // Create new copy node and play the move
			curr->setChild(c); // Set node as child
			curr = curr->getChild();
		}
		backpropagation(n);
	}
}

template <typename T>
void mcst<T>::populate() {
	int p, max = 0;
	node<T> *n = nullptr;
	for (int i = 0; i < WIDTH; i++) {
		n = new node<T>(*root);
		if (n->getData()->play(i)) {
			p = 1; // Pick a good number for playouts
			if (!n->getData()->alignment())
				playout(n, p);

			if (n->getScore() >= max) {
				max = n->getScore();
				root->setChild(n);
			}
		}
	}
}

template class mcst<c4>;
