#include "node.hpp"

Node::Node(const int row, const int col, const Type type, const char ch) {
    this->row = row;
    this->col = col;
    this->type = type;
    this->ch = ch;
}

Node::Node() {}

Node::~Node() {}
