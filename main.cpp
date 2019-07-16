#include <ctime>
#include "mcst.h"

using namespace std;

void startMCST() {
	// Driver
	bool first = rand() % 2;
	mcst<c4> *tree = new mcst<c4>(first);
	tree->getRoot()->getData()->display();
	int turn = first;
	while (!tree->getRoot()->getData()->result(first, true)) {
		if (turn) {
			tree->select();
		} else {
			tree->play();
		}
		tree->getRoot()->getData()->display();
		turn++;
		turn%=2;
	}
	
	delete tree;
}

int main() {
	srand(time(nullptr));
	startMCST();
	
	return 0;
}
