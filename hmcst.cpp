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

template class mcst<c4>;
