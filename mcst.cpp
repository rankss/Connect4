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
	int r;
	node<c4> c* = nullptr;
	while (p--) {
		// Do a playout
		while (!n->getData()->check_win()) {
			r = rand() % WIDTH;
			// Generate random playouts
			// Be careful of memory leaks (use valgrind)
			*c = *n;

		}
		backpropagation(n);
	}
}

template <typename T>
void mcst<T>::populate() {
	int p;
	node<T> *n = nullptr;
	for (int i = 0; i < WIDTH; i++) {
		*n = *root;
		if (n->getData()->play(i)) {
			p = 0; // Pick a good number for playouts
			if (!n->getData()->check_win())
				playout(n, p);
		}
	}
}

template class mcst<c4>;
