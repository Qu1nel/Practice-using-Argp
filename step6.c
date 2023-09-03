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
        case 777: {
            return my_parse_options('d', "3", state);
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
    //
    // The 2nd field of the struct argp_option (the key field) is special because Argp automatically
    // detects if it is a viewable character to be used in a short option or not. 777 is not a printable character,
    // and this means the --ellipsis option will be a long option, with no short option equivalent
    struct argp_option options[] = {
        {.name = "dot", .key = 'd', .arg = "NUM", .flags = 0, .doc = "Show a dot on the screen"},
        {.name = "ellipsis", .key = 777, .arg = 0, .flags = 0, .doc = "Show an ellipsis on the screen"},
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
