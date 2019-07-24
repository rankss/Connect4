#include "hmcst.h"

template <typename T>
hmcst<T>::hmcst() {
	root = new node<T>();
	first = rand() % 2;
}

template <typename T>
hmcst<T>::~hmcst() {
	delete root;
}

