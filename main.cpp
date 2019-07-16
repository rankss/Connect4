#include <ctime>
#include "mcst.h"

using namespace std;

int main() {
	srand(time(nullptr));

	bool first = false;
	mcst<c4> *tree = new mcst<c4>(first);
	tree->getRoot()->getData()->display();
	if (first)
		tree->select();
	else
		tree->play();
	tree->getRoot()->getData()->display();
	delete tree;
	return 0;
}