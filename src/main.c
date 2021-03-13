#include <stdio.h>
#include <argp.h>
#include "cli.c"
#include "app.c"

int main(int argc, char *argv[]) {

    struct arguments arguments;

    arguments.mode = CHARACTER_COUNT;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    run_app(15);

    return 0;
}

