#include <stdio.h>
#include <argp.h>
#include "app.c"
#include "cli.c"

int main(int argc, char *argv[]) {

    struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    printf("%d\n", arguments.char_count);

    if (arguments.char_count != 0) {
        run_app(arguments.char_count);
    } else {
        run_app(10);
    }

    return 0;
}

