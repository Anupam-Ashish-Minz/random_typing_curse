#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int main() {

    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    time_t t;
    srand((unsigned)time(&t));

    int correct = 0;
    int input_size = 15;

    initscr();
    cbreak();
    noecho();
    refresh();
    
    for (int i=0; i<input_size; i++) {

        char rand_char = letters[rand()%26];
        printw("%c\n", rand_char);

        char c = getch();

        if (rand_char == c) {
            correct++;
        }

        clear();
    }

    printw("accuracy = %f", (double)correct/input_size*100);

    getch();
    endwin();

    return 0;
}
