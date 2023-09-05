#include "readline-argp.h"

#include <unistd.h>

char *default_history_file = ".history";

static int parse_opt(int key, char *restrict arg, struct argp_state *restrict state)
{
    struct readline_arguments *args = state->input;
    switch (key) {
        case 411: {
            if (access(arg, R_OK) || access(arg, W_OK)) {
                args->history_file = arg;
            } else {
                argp_failure(state, 1, 0, "Cannot open file '%s' for reading", arg);
            }
        } break;
        case 511: {
            args->history_file = NULL;
        } break;
        case ARGP_KEY_ARG: {
            args->history_file = default_history_file;
        } break;
        default: {
            return 0;
        }
    }
    return 0;
}

// clang-format off
static struct argp_option options[] = {
    {
        .name = "history-file",
        .key = 411,
        .arg = "FILE",
        .flags = 0,
        .doc = "Specify a FILE to store the interactive history",
    },
    {
        .name = "no-history-file",
        .key = 511,
        .arg = NULL,
        .flags = 0,
        .doc = "Do not record a history in interactive mode"
    },
};
// clang-format on
struct argp readline_argp = {options, parse_opt, 0, 0, 0};
