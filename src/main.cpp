#include <ncurses.h>
#include <unistd.h>

#include <iostream>

using std::string;

bool stop_listening;
int rows, cols;
int player_row, player_col;

void setup();
void clear_term();
void key_input();
void run();
void exit_game(const int code, const string msg);

int main(int argc, char **argv) {
    (void)argc, (void)argv;
    setup();
    run();
    exit_game(0, "");
}

void setup() {
    initscr();
    noecho();
    keypad(stdscr, true);
    raw();
    curs_set(0);
    nodelay(stdscr, true);
    if (!has_colors()) exit_game(1, "your terminal does not support colors");
    player_row = 10;
    player_col = 10;
}

void run() {
    getmaxyx(stdscr, rows, cols);
    if (rows <= 0 || cols <= 0)
        exit_game(1, "terminal size cannot be less than or equal to 0");
    bool done = false;
    while (!done) {
        move(player_row, player_col);
        addch('X');
        int key = getch();
        switch (key) {
            case ERR:
                break;
            case 'w':
                player_row--;
                break;
            case 's':
                player_row++;
                break;
            case 'a':
                player_col--;
                break;
            case 'd':
                player_col++;
                break;
            case 'q':
                done = true;
                break;
        }
        move(player_row, player_col);
        addch('X');
        refresh();
        player_row--;
        usleep(110000);
    }
}

void exit_game(const int code, const string msg) {
    endwin();
    if (msg.size() <= 0) exit(code);
    if (code == 0)
        std::cout << msg << std::endl;
    else
        std::cerr << "Error: " << msg << std::endl;
    exit(code);
}

