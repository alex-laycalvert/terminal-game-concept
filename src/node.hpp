#ifndef NODE_HPP
#define NODE_HPP

enum Type { PLAYER, BLOCK, EMPTY };

class Node {
   public:
    int row;
    int col;
    Type type;
    char ch;
    Node(const int row, const int col, const Type type, const char ch);
    Node();
    ~Node();
};

#endif  // NODE_HPP
