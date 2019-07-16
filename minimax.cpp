#include "minimax.h"

template <typename T>
minimax<T>::minimax() {
	root = new node<T>();
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
