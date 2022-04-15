#include "tgc.hpp"

#include <ncurses.h>
#include <unistd.h>

#include <vector>

using std::vector;

vector<vector<char>> map;
int trows, tcols;
int rows, cols;
int player_row, player_col;
int camera_row, camera_col;
int jump_counter;
bool jumping;

void init_map(const int term_rows, const int term_cols) {
    trows = term_rows;
    tcols = term_cols;
    rows = term_rows;
    cols = tcols + tcols / 2;
    for (int i = 0; i < rows; i++) {
        vector<char> row;
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                row.push_back(BLOCK);
            else
                row.push_back(EMPTY);
        }
        map.push_back(row);
    }
    // settings some blocks
    map[rows - 2][cols / 2] = BLOCK;
    map[rows - 3][cols / 2] = BLOCK;
    map[rows - 4][cols / 2] = BLOCK;

    // init values
    camera_row = rows / 2;
    camera_col = cols / 2;
    player_row = rows / 2;
    player_col = cols / 2;
    jump_counter = 0;
    jumping = false;
    map[player_row][player_col] = PLAYER;
    init_pair(BLOCK_CP, COLOR_WHITE, COLOR_WHITE);
    init_pair(PLAYER_CP, COLOR_GREEN, COLOR_GREEN);
}

void print_map() {
    int start_row = camera_row - trows / 2;
    int start_col = camera_col - tcols / 2;
    int end_row = camera_row + trows / 2;
    int end_col = camera_col + tcols / 2;
    for (int i = 0; i < trows; i++)
        for (int j = 0; j < tcols; j++) mvprintw(i, j, " ");
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_col; j <= end_col; j++) {
            if (i < 0 || j < 0 || i >= rows || j >= cols) continue;
            switch (map[i][j]) {
                case PLAYER:
                    attron(COLOR_PAIR(PLAYER_CP));
                    mvprintw(i - start_row, j - start_col, "%c", map[i][j]);
                    attroff(COLOR_PAIR(PLAYER_CP));
                    break;
                case BLOCK:
                    attron(COLOR_PAIR(BLOCK_CP));
                    mvprintw(i - start_row, j - start_col, "%c", map[i][j]);
                    attroff(COLOR_PAIR(BLOCK_CP));
                    break;
                default:
                    mvprintw(i - start_row, j - start_col, "%c", map[i][j]);
                    break;
            }
        }
    }
}

void play() {
    bool playing = true;
    while (playing) {
        map[player_row][player_col] = PLAYER;
        print_map();
        map[player_row][player_col] = EMPTY;
        int key = getch();
        switch (key) {
            case ERR:
                break;
            case 'w':
                if (map[player_row + 1][player_col] != EMPTY) jump();
                break;
            case 'a':
                if (player_col - 1 <= 0) break;
                if (map[player_row][player_col - 1] == EMPTY) {
                    player_col--;
                    if (player_col >= tcols / 2 &&
                        player_col < cols - tcols / 2)
                        camera_col--;
                }
                break;
            case 'd':
                if (player_col + 1 >= cols - 1) break;
                if (map[player_row][player_col + 1] == EMPTY) {
                    player_col++;
                    if (player_col > tcols / 2 &&
                        player_col <= cols - tcols / 2)
                        camera_col++;
                }
                break;
            case 'q':
                playing = false;
                break;
        }
        if (jump_counter == 0) jumping = false;
        if (jumping) {
            if (map[player_row - 1][player_col] == EMPTY) player_row--;
            jump_counter--;
        } else if (map[player_row + 1][player_col] == EMPTY)
            player_row++;
    }
}

void jump() {
    jumping = true;
    jump_counter = JUMP_STRENGTH;
}

