#include <ctime>
#include "mcst.h"

using namespace std;

void startMCST() {
	// Driver
	time_t start, elapsed;
	bool first = rand() % 2;
	mcst<c4> *tree = new mcst<c4>(first);
	tree->getRoot()->getData()->display();
	int turn = first;
	while (!tree->getRoot()->getData()->result(first, true)) {
		if (turn) {
			start = time(nullptr);
			tree->select();
			elapsed = time(nullptr) - start; 
			cout << "Move took: " << elapsed << " seconds. Playouts per second per legal move: " << float(P/elapsed) << "." << endl;
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
