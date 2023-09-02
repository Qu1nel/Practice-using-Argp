#include <argp.h>
#include <stdio.h>

// typedef struct argp_state ArgpState_t;
// typedef struct argp_option Option_t;
// typedef struct argp ArgParser;


static int my_parse_options(int key, char *argument, struct argp_state *state)
{
    switch (key) {
        case 'd':
            puts(".");
            break;
    }
    return 0;
}


int main(int argc, char **argv)
{
    // clang-format off
    struct argp_option options[] = {
        [0] = {.name = NULL, .key = 'd', .arg = NULL, .flags = 0, .doc = "Show a dot on the screen", .group = 0},
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
