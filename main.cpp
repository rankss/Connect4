#include <iostream>
#include <ctime>
#include "mcst.h"

using namespace std;

int main() {
	mcst<c4> *tree = new mcst<c4>();
	tree->populate();
	tree->getRoot()->getChild()->getData()->display();
	delete tree;
	return 0;
}