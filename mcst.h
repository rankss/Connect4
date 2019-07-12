#ifndef MCST
#define MCST

#include "state.h"

class MCST {
private:
	State *root;

public:
	MCST();
	~MCST();

	void playout();
	int backpropagation();
}

#endif