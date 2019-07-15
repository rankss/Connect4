#include <iostream>
#include "mcst.h"

using namespace std;

int main() {
	mcst<c4> *tree = new mcst<c4>();
	tree->getRoot()->getData()->display();
	node<c4> *n = new node<c4>(*tree->getRoot());
	n->getData()->play(0);
	tree->getRoot()->setChild(n);
	tree->getRoot()->getChild()->getData()->display();
	node<c4> *m = new node<c4>(*tree->getRoot()->getChild());
	m->getData()->play(1);
	tree->getRoot()->getChild()->setChild(m);
	tree->getRoot()->getChild()->getChild()->getData()->display();
	delete tree;
	return 0;
}