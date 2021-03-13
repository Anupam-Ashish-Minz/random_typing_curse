#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

void run_app(int input_size) {
    
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    time_t t;
    srand((unsigned)time(&t));

    int correct = 0;
    int inverse_count = input_size;
    double t_total_keystroke = 0;
    double t_avg_keystroke = 0;

    initscr();
    cbreak();
    noecho();
    refresh();

    for (int i=3; i>0; i--) {
        printw("please wait ... %d\n", i);
        // should be printed before the thread suspeds but that's not working
        sleep(1);
    }
    clear();

    for (int i=0; i<input_size; i++) {

        printw("%d left\n", inverse_count--);
        char rand_char = letters[rand()%26];
        printw("%c\n", rand_char);

        char t_before = time(&t);
        char c = getch();
        char t_after = time(&t);

        t_total_keystroke += t_after - t_before;

        if (rand_char == c) {
            correct++;
        }

        clear();
    }

    t_avg_keystroke = t_total_keystroke / input_size;

    printw("accuracy = %f\n", (double)correct/input_size*100);
    printw("avg keystoke time = %f\n", t_avg_keystroke);

    getch();
    endwin();

}
