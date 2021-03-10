#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int main() {

    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    time_t t;
    srand((unsigned)time(&t));

    initscr();
    cbreak();
    noecho();
    printw("Hello World\n");
    refresh();
    
    for (int i=0; i<5; i++) {
        char rand_char = letters[rand()%26];
        printw("%c\n", rand_char);
        char c = getch();
        refresh();
    }

    getch();
    endwin();

    return 0;
}
