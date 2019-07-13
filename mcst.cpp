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
node<T>* mcst<T>::getRoot() {
	return root;
}

template <typename T>
void mcst<T>::playout(node<T> *n, int p) {
	//int r;
	while (p--) {
		// Do a playout
		while (!n->getData()->check_win()) {
			//r = rand() % WIDTH;
			// Generate random playouts
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
			p = 0; // number of playouts
			if (!n->getData()->check_win())
				playout(n, p);
		}
	}
}

template <typename T>
int mcst<T>::backpropagation(node<T> *n) {
	if (n->getChild() == nullptr)
		return n->getScore();
	n->setScore(n->getScore() + backpropagation(n->getChild()));
	return n->getScore();
}

template class mcst<c4>;
