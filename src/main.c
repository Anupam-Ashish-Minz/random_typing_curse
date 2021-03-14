#include <stdio.h>
#include <argp.h>
#include "app.c"
#include "cli.c"

int main(int argc, char *argv[]) {

    struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    // incorrect output due to incorrect conversion from ascii to int
    printf("%d\n", arguments.char_count);

    run_app(15);

    return 0;
}

