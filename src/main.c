#include <stdio.h>
#include <argp.h>
#include "app.h"
#include "cli.h"

int main(int argc, char *argv[]) {

    struct arguments arguments;
    arguments.char_count = 10;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    run_app(arguments.char_count);

    return 0;
}

