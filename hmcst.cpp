#include "hmcst.h"

template <typename T>
hmcst<T>::hmcst() {
	root = new node<T>();
	first = rand() % 2;
	root->getData()->setZug(!first);
}

template <typename T>
hmcst<T>::~hmcst() {
	delete root;
}

template <typename T>
void hmcst<T>::playout(node<T> *n) {
	// Do playouts based on a probability of each move being selected
	

}

template <typename T>
void hmcst<T>::populate() {
	int max = INT_MAX;
	node<T> *n = nullptr;
	for (U8 m : root->getData()->possible()) {
		n = new node<T>(*root);
		n->play(m);

		if (!n->getData()->result(first, false))
			playout(n);
		else
			root->setChild(n), break;
		
		if (n->getScore() > max) {
			max = n->getScore();
			root->setChild(n);
		} else {
			delete n;
		}

	}
}

template <typename T>
int hmcst<T>::backpropagate(node<T> *n) {
	
}

template class mcst<c4>;
