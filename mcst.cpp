#include "mcst.h"

template <typename T>
mcst<T>::mcst(bool f) {
	root = new node<T>();
	first = f;
}

template <typename T>
mcst<T>::~mcst() {
	delete root;
}

template <typename T>
void mcst<T>::playout(node<T> *n, int p) {
	int m, s;
	std::vector<int> moves;
	node<T> *c = nullptr, *curr = nullptr;
	while (p--) {
		// Do a playout
		curr = n;
		s = 0;
		while (!s) {
			// Generate random playouts
			// Be careful of memory leaks (use valgrind)
			moves = curr->getData()->possible(); // Get all possible moves
			if (moves.empty()) break;
			m = moves[rand() % moves.size()]; // Select random move
			c = new node<T>(*curr);
			c->getData()->play(m); // Create new copy node and play the move
			s = c->getData()->result(first, false);
			c->setScore(s);
			curr->setChild(c); // Set node as child
			curr = curr->getChild();
		}
		backpropagate(n);
	}
}

template <typename T>
void mcst<T>::populate() {
	int max = INT_MIN;
	node<T> *n = nullptr;
	std::vector<int> moves = root->getData()->possible();
	for (int m : moves) {
		n = new node<T>(*root);
		n->getData()->play(m);

		n->setScore(n->getData()->result(first, false));
		if (!n->getScore())
			playout(n, 2000);
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
void mcst<T>::select() {
	// AI move
	std::cout << "AI's turn" << std::endl;
	populate();
	node<T> *n = new node<T>(*root->getChild());
	delete root;
	root = n;
}

template <typename T>
void mcst<T>::play() {
	// Player move
	std::vector<int> moves = root->getData()->possible();
	int m;
	std::cout << "Player's turn" << std::endl;
	std::cout << "Please choose a move: ";

	std::cin >> m;
	while (std::find(moves.begin(), moves.end(), m) == moves.end()) {
		std::cout << "Please choose a legal move: ";
		std::cin >> m;
	}

	root->getData()->play(m);
}

template class mcst<c4>;
