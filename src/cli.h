#include <stdlib.h>
#include <argp.h>
#include <stdbool.h>

const char *argp_program_version = "0.1";
const char *argp_program_bug_address = "<your@email.address>";
static char doc[] = "A typing application that spews random characters";
static char args_doc[] = "[OPTIONS]...";
static struct argp_option options[] = { 
    { "character-count", 'c', "char_count", 0, "The Total number of charaters to test"},
    { 0 }
};

struct arguments {
    int char_count;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'c':
            arguments->char_count = atoi(arg);
            break;
        case ARGP_KEY_ARG:
            return 0;
        default:
            return ARGP_ERR_UNKNOWN;
    }   
    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };
