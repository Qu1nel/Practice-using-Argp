#include <argp.h>
#include <stdio.h>
#include <stdlib.h>

#include "dotdash.h"

static int parse_opt(int key, char* restrict arg, struct argp_state* restrict state)
{
    switch (key) {
        case 999: {
            fputs("...---...", stdout);
        } break;
    }
    return 0;
}

int main(int argc, char** argv)
{
    struct argp_option opntions[] = {
        {.name = "SOS", .key = 999, .arg = NULL, .flags = 0, .doc = "Show the SOS sequence on the screen"},
        {0},
    };
    struct argp_child children_parsers[] = {
        {.argp = &dotdash_argp, .flags = 0, .header = "Basic Morse Code Options:", .group = 7},
        {0},
    };
    struct argp arg_parser = {
        .options = opntions,
        .parser = parse_opt,
        .args_doc = NULL,
        .doc = NULL,
        .children = children_parsers,
    };

    int status = argp_parse(&arg_parser, argc, argv, 0, 0, 0);
    putchar('\n');
    return status;
}
