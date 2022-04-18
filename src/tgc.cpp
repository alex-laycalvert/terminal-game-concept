#include "tgc.hpp"

#include <ncurses.h>
#include <unistd.h>

#include <vector>

#include "block.hpp"
#include "empty.hpp"
#include "node.hpp"
#include "player.hpp"

using std::vector;

int trows, tcols;
int rows, cols;
int jump_counter;
vector<vector<Node>> map;

void init_map(const int term_rows, const int term_cols) {
    trows = term_rows;
    tcols = term_cols;
    rows = term_rows;
    cols = term_cols;
    for (int i = 0; i < rows; i++) {
        vector<Node> row;
        for (int j = 0; j < cols; j++) {
            Node node;
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                node = Block(i, j);
            else
                node = Empty(i, j);
            row.push_back(node);
        }
        map.push_back(row);
    }
    map[rows / 2][cols / 2] = Player(rows / 2, cols / 2);
    init_pair(BLOCK_CP, COLOR_WHITE, COLOR_WHITE);
    init_pair(PLAYER_CP, COLOR_GREEN, COLOR_GREEN);
}

void print_map() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mvprintw(i, j, "%c", map[i][j].ch);
        }
    }
}

void play() {
    while (1) {
        print_map();
        if (getch() == 'q') break;
    }
}

