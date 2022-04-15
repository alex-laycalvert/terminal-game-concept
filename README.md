# terminal-game-concept

A proof of concept for a 2D terminal game with a side-scroller camera view.

Use the following keybindings to move:

- W (Jump)
- A (Left)
- D (Right)

The player is the green block that starts falling in the middle of the screen.
Various blocks have been placed to test jumping over obstacles.

The camera follows the player through the map in a side-scroller fashion.

## Running

On Linux and macOS:

```bash
# Clone the repo
git clone https://github.com/alex-laycalvert/terminal-game-concept

# cd into the repo directory
cd /path/to/terminal-game-concept

# Compile with make
make

# Optionally use the dev option
make dev

# Or manually compile
g++ src/*.cpp -lncurses -o ./tgc

# Run
./tgc
```
