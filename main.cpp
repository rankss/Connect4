#include <ctime>
#include "mcst.h"

using namespace std;

void startMCST() {
	// Driver
	time_t start, elapsed;
	mcst<c4> *tree = new mcst<c4>();
	tree->getRoot()->getData()->display();
	bool first = tree->getFirst();
	int turn = first;
	while (!tree->getRoot()->getData()->result(first, true)) {
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

void test() {
	mcst<c4> *tree = new mcst<c4>();
	tree->getRoot()->getData()->display();
	bool first = tree->getFirst();
	int turn = first;
	while (!tree->getRoot()->getData()->result(first, true)) {
		if (turn) {
			tree->play();
		} else {
			tree->play();
		}
		tree->getRoot()->getData()->display();
		cout << "row: " << tree->getRoot()->getData()->heuristic(first) << endl;
		turn++;
		turn%=2;
	}
	
	delete tree;
}

int main() {
	//srand(time(nullptr));
	//startMCST();
	test();
	return 0;
}
