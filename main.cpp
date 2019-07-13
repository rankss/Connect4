#include <iostream>
#include "node.h"

using namespace std;

int main() {
	node<c4> *n = new node<c4>();
	n->getData()->play(0);
	n->getData()->display();

	node<c4> *m = new node<c4>(*n);
	m->getData()->play(1);
	m->getData()->display();
	return 0;
}