#include <ctime>
#include "mcst.h"

using namespace std;

void startMCST() {
	// Driver
	time_t start, elapsed;
	mcst<c4> *tree = new mcst<c4>();
	tree->getRoot()->getData()->display();
	int turn = tree->getFirst();
	while (!tree->getRoot()->getData()->result(tree->getFirst(), true)) {
		if (turn) {
			start = time(nullptr);
			tree->select();
			elapsed = time(nullptr) - start;
			if (elapsed != 0)
				cout << "Move took: " << elapsed << " seconds. Playouts per second per legal move: " << float(P/elapsed) << "." << endl;
			else
				cout << "Move took: " << elapsed << " seconds. Playouts cannot be measured." << endl;
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
	//srand(time(nullptr));
	startMCST();

	return 0;
}
