#include "mcst.h"

template <typename T>
mcst<T>::mcst(bool f) {
	root = new node<T>();
	first = f;
}

template <typename T>
mcst<T>::~mcst() {
	//std::cout << "...calling mcst dtor" << std::endl;
	delete root;
}

template <typename T>
void mcst<T>::playout(node<T> *n, int p) {
	int m;
	std::vector<int> moves;
	node<T> *c = nullptr, *curr = n;
	while (p--) {
		// Do a playout
		while (!curr->getScore()) {
			// Generate random playouts
			// Be careful of memory leaks (use valgrind)
			moves = curr->getData()->possible(); // Get all possible moves
			if (moves.empty()) break;
			m = moves[rand() % moves.size()]; // Select random move
			c = new node<T>(*curr);
			c->getData()->play(m); // Create new copy node and play the move
			curr->setChild(c); // Set node as child
			curr = curr->getChild();
			curr->setScore(curr->getData()->evalMCST(first));
		}
		backpropagate(n);
	}
}

template <typename T>
void mcst<T>::populate() {
	int p, max = 0;
	node<T> *n = nullptr;
	for (int i = 0; i < WIDTH; i++) {
		n = new node<T>(*root);
		if (n->getData()->play(i)) {
			p = 2; // Pick a good number for playouts
			n->setScore(n->getData()->evalMCST(first));
			if (!n->getScore())
				playout(n, p);

			if (n->getScore() >= max) {
				max = n->getScore();
				root->setChild(n);
			} else {
				delete n;
			}
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
	std::cout << "Please choose a move from: " << std::endl;
	for (int move : moves) 
		std::cout << move << " ";
	std::cout << std::endl;

	std::cin >> m;
	while (std::find(moves.begin(), moves.end(), m) == moves.end()) {
		std::cout << "Please choose a legal move: ";
		std::cin >> m;
	}

	root->getData()->play(m);
}

template class mcst<c4>;
