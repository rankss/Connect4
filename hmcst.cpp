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
	int pr, s, p = P, total, i;
	U8 m;
	std::vector<U8> moves;
	node<T> *c = nullptr;
	while (p--) {
		c = new node<T>(*n);
		n->setChild(c);
		total = 0, s = 0;
		std::vector<int> probability;
		while (s < 50 || !c->getData()->result(first, false)) {
			moves = c->getData()->possible();
			for (m : moves) {
				probability.push_back(total);
				total += c->getData()->move_heuristic(m);
			}
			pr = rand() % total;
			m = moves[std::lower_bound(probability.begin(), probability.end(), pr)];
			s += c->getData()->heuristic(first);
			c->setScore(s);
			c->play(m);
		}
	}
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
