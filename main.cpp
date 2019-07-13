#include <iostream>
#include "mcst.h"

using namespace std;

int main() {
	mcst<c4> *root = new mcst<c4>();
	root->getRoot()->getData()->display();
	delete root;
	return 0;
}