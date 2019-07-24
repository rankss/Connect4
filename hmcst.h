#ifndef HMCST
#define HMCST

#include "node.h"

template <typename T>
class hmcst {
private:
	node<T> *root;
	bool first;

public:
	hmcst();
	~hmcst();

};

#endif
