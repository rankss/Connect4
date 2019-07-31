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
	int s, p = P;
	U8 m, mc = n->getData()->getMoves(), cmc;
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
			c->play(m); // Play move
			cmc = c->getData()->getMoves() - mc;
			c->setScore(c->getData()->result(first, false)/cmc);
			s = c->getScore();
		}
		backpropagate(n);
	}
}

template <typename T>
void hmcst<T>::populate() {
	int max = INT_MIN;
	node<T> *n = nullptr;
	for (U8 m : root->getData()->possible()) {
		n = new node<T>(*root);
		n->play(m);

		if (!n->getData()->result(first, false))
			playout(n);
		else {
			if (n->getData()->result(first, false) > 0) {
				root->setChild(n);
				break;
			}
		}
		
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
	if (n->getChild() == nullptr)
		return n->getScore();

	n->setScore(n->getScore() + backpropagate(n->getChild()));
	return n->getScore();
}

template <typename T>
node<T>* hmcst<T>::getRoot() {
	return root;
}

template <typename T>
bool hmcst<T>::getFirst() {
	return first;
}

template <typename T>
void hmcst<T>::select() {
	// AI move
	std::cout << "AI's turn" << std::endl;
	populate();
	node<T> *n = new node<T>(*root->getChild());
	std::cout << "AI chose: " << n->getMove() << std::endl;
	delete root;
	root = n;
}

template <typename T>
void hmcst<T>::play() {
	// Player move
	std::vector<U8> moves = root->getData()->possible();
	std::cout << "Player's turn" << std::endl;

	U8 m;
	std::cout << "Please choose a move: ";
	while (std::cin >> m && std::find(moves.begin(), moves.end(), m) == moves.end())
		std::cout << "Please choose a valid move: ";

	root->play(m);
}

template class hmcst<c4>;
