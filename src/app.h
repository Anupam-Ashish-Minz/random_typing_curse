#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

void run_app(int input_size) {
    
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    time_t t;
    srand((unsigned)time(&t));

    struct timeval before,after;

    int correct = 0;
    int inverse_count = input_size;
    unsigned long t_total = 0;
    unsigned int t_avg = 0;

    initscr();
    cbreak();
    noecho();
    refresh();

    clear();

    for (int i=0; i<input_size; i++) {

        printw("%d left\n", inverse_count--);
        char rand_char = letters[rand()%26];
        printw("%c\n", rand_char);

        gettimeofday(&before, NULL);
        char c = getch();
        gettimeofday(&after, NULL);

        t_total += (after.tv_sec - before.tv_sec) * 1000000
                    + (after.tv_usec - before.tv_usec);

        if (rand_char == c) {
            correct++;
        }

        clear();
    }

    t_avg = t_total / (input_size * 1000);

    printw("accuracy = %f\n", (double)correct/input_size*100);
    printw("avg keystoke time = %ums \n", t_avg);

    getch();
    endwin();

}
