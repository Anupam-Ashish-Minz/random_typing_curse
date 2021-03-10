#include <stdio.h>
#include <ncurses.h>

int main() {

    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    initscr();
    cbreak();
    noecho();
    printw("Hello World\n");
    refresh();
    
    for (int i=0; i<5; i++) {
        char c = getch();
        printw("%c\n", c);
        refresh();
    }

    getch();
    endwin();

    return 0;
}
