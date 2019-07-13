# Connect 4 (With 2 AI Components)

Project written in C++. Makefile added, build by running $make.

### Pure Monte Carlo Search Tree

Uses K amount of random playouts and selects move with most amount of wins.
After each playout, data is back propagated back to parent node.

### Minimax Search Tree (Alpha Beta/Quiescence Search)

Alpha Beta returns node with best estimated value if node state is quiet, otherwise recursively search children with quiescence search and return node with best value of children.
