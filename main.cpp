#include <ctime>
#include "mcst.h"
#include "hmcst.h"
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

void startMinimax() {
	time_t start, elapsed;
	minimax<c4> *tree = new minimax<c4>();
	tree->getRoot()->getData()->display();
	bool first = tree->getFirst();
	int turn = first;
	while (!tree->getRoot()->getData()->result(first, true)) {
		if (turn) {
			start = time(nullptr);
			tree->select();
			elapsed = time(nullptr) - start;
			cout << "Move took: " << elapsed << " seconds. Tree depth: " << 7 <<endl;
		} else {
			tree->play();
		}
		tree->getRoot()->getData()->display();
		//cout << tree->getRoot()->getData()->heuristic(tree->getRoot()->getData()->getMoves()) << endl;
		turn++;
		turn%=2;
	}

	delete tree;
}

void startHMCST() {
	// Driver
	time_t start, elapsed;
	hmcst<c4> *tree = new hmcst<c4>();
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

int main() {
	srand(time(nullptr));
	//startMCST();
	startMinimax();
	//startHMCST();
	return 0;
}
