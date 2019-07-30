#include <ctime>
#include "mcst.h"
#include "minimax.h"

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
			tree->getRoot()->getData()->heuristic(first);
			elapsed = time(nullptr) - start;
			if (elapsed != 0)
				cout << "Move took: " << elapsed << " seconds. Playouts per second per legal move: " << float(P/elapsed) << "." << endl;
			else
				cout << "Move took: " << elapsed << " seconds. Playouts cannot be measured." << endl;
		} else {
			tree->play();
			tree->getRoot()->getData()->heuristic(first);
		}
		tree->getRoot()->getData()->display();
		turn++;
		turn%=2;
	}
	
	delete tree;
}

void startMinimax() {
	minimax<c4> *tree = new minimax<c4>();
	tree->getRoot()->getData()->display();
	bool first = tree->getFirst();
	cout << first << endl;
	tree->select();
	tree->getRoot()->getData()->display();
	delete tree;
}

// void test() {
// 	mcst<c4> *tree = new mcst<c4>();
// 	tree->getRoot()->getData()->display();
// 	bool first = tree->getFirst();
// 	int turn = first;
// 	while (!tree->getRoot()->getData()->result(first, true)) {
// 		if (turn) {
// 			for (U8 m : tree->getRoot()->getData()->possible()) {
// 				cout << "move: " << m << " score: " << tree->getRoot()->getData()->heuristic(m) << endl;
// 			}
// 			tree->play();
// 		} else {
// 			for (U8 m : tree->getRoot()->getData()->possible()) {
// 				cout << "move: " << m << " score: " << tree->getRoot()->getData()->heuristic(m) << endl;
// 			}
// 			tree->play();
// 		}
		
// 		tree->getRoot()->getData()->display();
// 		turn++;
// 		turn%=2;
// 	}
	
// 	delete tree;
// }

int main() {
	//srand(time(nullptr));
	//startMCST();
	startMinimax();
	//test();
	return 0;
}
