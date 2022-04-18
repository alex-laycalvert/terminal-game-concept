#ifndef EMPTY_HPP
#define EMPTY_HPP

#include "node.hpp"

class Empty : public Node {
   public:
    Empty(const int row, const int col);
    ~Empty();
};

#endif  // EMPTY_HPP
