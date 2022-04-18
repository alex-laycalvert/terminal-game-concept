#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "node.hpp"

class Block : public Node {
   public:
    Block(const int row, const int col);
    ~Block();
};

#endif  // BLOCK_HPP
