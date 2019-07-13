#include "mcst.h"

template <typename T>
mcst<T>::mcst() {
	root = new node<T>();
}

template <typename T>
mcst<T>::~mcst() {
	delete root;
}

template <typename T>
node<T>* mcst<T>::getRoot() {
	return root;
}

template <typename T>
void mcst<T>::playout() {

}

template <typename T>
int mcst<T>::backpropagation() {
	return 0;
}

template class mcst<c4>;
