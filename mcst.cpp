#include "mcst.h"

template <typename T>
mcst<T>::mcst() {
	root = new node<T>();
	first = rand() % 2;
}

template <typename T>
mcst<T>::~mcst() {
	delete root;
}

template <typename T>
void mcst<T>::playout(node<T> *n) {
	int m, s, p = 1;
	std::vector<U8> moves;
	node<T> *c = nullptr;
	while (p--) {
		// Do a playout
		c = new node<T>(*n);
		n->setChild(c);
		s = 0;
		while (!s) {
			moves = c->getData()->possible(); // Get all possible moves
			if (moves.empty()) break;
			m = moves[rand() % moves.size()]; // Select random move
			c->getData()->play(m); // Play move
			c->setScore(c->getData()->result(first, false));
			s = c->getScore();
		}
		backpropagate(n);
	}
}

template <typename T>
void mcst<T>::populate() {
	int max = INT_MIN;
	node<T> *n = nullptr;
	for (U8 m : root->getData()->possible()) {
		n = new node<T>(*root);
		n->getData()->play(m);
		n->setMove(m);

		n->setScore(n->getData()->result(first, false));
		if (!n->getScore())
			playout(n);
		else {
			if (n->getScore() > 0) {
				root->setChild(n);
				break;
			}
		}

		if (n->getScore() >= max) {
			max = n->getScore();
			root->setChild(n);
		} else {
			delete n;
		}
	}
}

template <typename T>
int mcst<T>::backpropagate(node<T> *n) {
	if (n->getChild() == nullptr)
		return n->getScore();

	n->setScore(n->getScore() + backpropagate(n->getChild()));
	return n->getScore();
}

template <typename T>
node<T>* mcst<T>::getRoot() {
	return root;
}

template <typename T>
bool mcst<T>::getFirst() {
	return first;
}

template <typename T>
void mcst<T>::select() {
	// AI move
	std::cout << "AI's turn" << std::endl;
	populate();
	node<T> *n = new node<T>(*root->getChild());
	std::cout << "AI chose: " << n->getMove() << std::endl;
	delete root;
	root = n;
}

template <typename T>
void mcst<T>::play() {
	// Player move
	std::vector<U8> moves = root->getData()->possible();
	std::cout << "Player's turn" << std::endl;

	U8 m;
	while (std::cin >> m && std::find(moves.begin(), moves.end(), m) == moves.end())
		std::cout << "Please choose a valid move: ";

	root->getData()->play(m);
}

template class mcst<c4>;
