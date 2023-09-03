#include <argp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// typedef struct argp_state ArgpState_t;
// typedef struct argp_option Option_t;
// typedef struct argp ArgParser;


static int my_parse_options(int key, char *argument, struct argp_state *state)
{
    switch (key) {
        case 'd': {
            int32_t count = (argument == NULL) ? 1 : atoi(argument);
            while (count-- > 0) putchar('.');
            putchar('\n');
            break;
        }
        default: {
            return 0;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    // clang-format off
    struct argp_option options[] = {
        [0] = {.name = "dot", .key = 'd', .arg = "NUM", .flags = OPTION_ARG_OPTIONAL, .doc = "Show a dot on the screen"},
        [1] = {.name = "period", .key = 0, .arg = "FOO", .flags = OPTION_ALIAS, .doc = NULL},
        {0}
    };
    // clang-format on

    struct argp arg_parser = {
        .options = options,
        .parser = my_parse_options,
        .args_doc = NULL,
        .doc = NULL,
    };

    return argp_parse(&arg_parser, argc, argv, 0, 0, 0);
}
