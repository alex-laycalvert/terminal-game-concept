#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "node.hpp"

class Player : public Node {
   public:
    Player(const int row, const int col);
    ~Player();
};

#endif  // PLAYER_HPP
