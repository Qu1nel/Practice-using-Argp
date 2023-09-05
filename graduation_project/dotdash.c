#include "dotdash.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
    }
    return 0;
}

static struct argp_option options[] = {
    {.name = "dot", .key = 'd', .arg = "NUM", .flags = OPTION_ARG_OPTIONAL, .doc = "Show some dots on the screen"},
    {.name = "dash", .key = 888, .arg = NULL, .flags = 0, .doc = "Show a dash on the screen"},
};

struct argp dotdash_argp = {options, my_parse_options, 0, 0, 0};
