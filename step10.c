#include <argp.h>
#include <argz.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const char *argp_program_bug_address = "someone@example.com";
const char *argp_program_version = "version 1.0";

struct arguments {
    char *argz;
    size_t argz_len;
};

static int my_parse_options(const int key, char *restrict arg, struct argp_state *restrict state)
{
    struct arguments *a = (struct arguments *)state->input;
    switch (key) {
        case 'd': {
            int32_t count = (arg == NULL) ? 1 : atoi(arg);
            while (count-- > 0) putchar('.');
        } break;
        case 888: {
            putchar('-');
        } break;
        case 999: {
            my_parse_options('d', "3", state);
            putchar(' ');
            my_parse_options(888, NULL, state);
            my_parse_options(888, NULL, state);
            my_parse_options(888, NULL, state);
            putchar(' ');
            my_parse_options('d', "3", state);
            putchar('\n');
            exit(0);
        } break;
        case ARGP_KEY_ARG: {
            argz_add(&a->argz, &a->argz_len, arg);
        } break;
        case ARGP_KEY_INIT: {
            a->argz = NULL;
            a->argz_len = 0;
        } break;
        case ARGP_KEY_END: {
            size_t count = argz_count(a->argz, a->argz_len);
            if (count > 2) {
                argp_failure(state, 1, 0, "too many arguments");
            } else if (count < 1) {
                argp_failure(state, 1, 0, "too few arguments");
            }
        } break;
        default: {
            return 0;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    // Records that have a larger non-negative value for their group appear after smaller non-negative groups.
    // Groups that have negative values appear after the non-negative ones.

    // clang-format off
    struct argp_option options[] = {
        {0, 0, 0, 0, .doc = "Morse Code Options:", .group = 7},
        {.name = "dot", .key = 'd', .arg = "NUM", .flags = OPTION_ARG_OPTIONAL, .doc = "Show a dot on the screen"},
        {.name = "dash", .key = 888, .arg = 0, .flags = 0, .doc = "Show a dash on the screen"},
        {0, 0, 0, 0, .doc = "Informational Opetions:", .group = -1},
        {.name = "SOS", .key = 999, .arg = 0, .flags = 0, .doc = "Give some help in morse code"},
        {0}
    };
    // clang-format on

    struct argp arg_parser = {.options = options,
                              .parser = my_parse_options,
                              .args_doc = "WORD\nWORD WORD",
                              .doc =
                                  "Show some dots and dashes on the screen.\v"
                                  "A final newline is also shown regardless of whether any options were given."};

    struct arguments arguments;

    if (argp_parse(&arg_parser, argc, argv, 0, 0, &arguments) == 0) {
        const char *prev = NULL;
        char *word;
        while ((word = argz_next(arguments.argz, arguments.argz_len, prev)) != NULL) {
            printf("%s ", word);
            prev = word;
        }
        putchar('\n');
        free(arguments.argz);
    }

    return EXIT_SUCCESS;
}
