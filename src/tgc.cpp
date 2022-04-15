#include "tgc.hpp"

#include <ncurses.h>

#include <vector>

using std::vector;

vector<vector<char>> map;
int player_row, player_col;
int jump_counter;
bool jumping;
bool falling;

void init_map(const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        vector<char> row;
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                row.push_back(BLOCK);
            row.push_back(EMPTY);
        }
        map.push_back(row);
    }
    player_row = rows / 2;
    player_col = cols / 2;
    jump_counter = 0;
    jumping = false;
    falling = false;
    map[player_row][player_col] = PLAYER;
}

void print_map() {
    for (int i = 0; i < (int)map.size(); i++)
        for (int j = 0; j < (int)map[i].size(); j++)
            mvprintw(i, j, "%c", map[i][j]);
}

void play() {
    bool playing = true;
    while (playing) {
        int key = getch();
        switch (key) {
            case ERR:
                break;
            case 'w':
                break;
            case 'a':
                break;
            case 'd':
                break;
            case 'q':
                playing = false;
                break;
        }
    }
    if (jump_counter <= 0) {
        jump_counter = 0;
        jumping = false;
    }
    if (jumping) {
        player_row--;
        jump_counter--;
    } else if (map[player_row + 1][player_col] == EMPTY) {
        falling = true;
        player_row++;
    } else if (map[player_row + 1][player_col] == BLOCK)
        falling = false;
    map[player_row][player_col] = PLAYER;
    print_map();
}

