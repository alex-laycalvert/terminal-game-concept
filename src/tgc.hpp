#ifndef TGC_HPP
#define TGC_HPP

#define EMPTY ' '
#define BLOCK 'B'
#define PLAYER 'X'

#define BLOCK_CP 1
#define PLAYER_CP 2

void init_map(const int rows, const int cols);
void print_map();
void play();
void jump();

#endif  // TGC_HPP
