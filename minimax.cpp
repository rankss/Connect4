#include "minimax.h"

template <typename T>
minimax<T>::minimax(bool f) {
	root = new node<T>();
	first = f;
}

template <typename T>
minimax<T>::~minimax() {
	delete root;
}

template <typename T>
void minimax<T>::populate() {

}

template <typename T>
int minimax<T>::backpropagate() {
	return 0;
}

template class minimax<c4>;
