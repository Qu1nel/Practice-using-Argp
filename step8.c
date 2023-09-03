#include <argp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// typedef struct argp_state ArgpState_t;
// typedef struct argp_option Option_t;
// typedef struct argp ArgParser;


static int my_parse_options(const int key, char *restrict argument, struct argp_state *restrict state)
{
    switch (key) {
        case 'd': {
            int32_t count = (argument == NULL) ? 1 : atoi(argument);
            while (count-- > 0) putchar('.');
            break;
        }
        case 888: {
            putchar('-');
            break;
        }
        case 777: {
            return my_parse_options('d', "3", state);
        }
        case ARGP_KEY_ARG: {
            argp_failure(state, 1, 0, "to many arguments");
            break;
        }
        case ARGP_KEY_END: {
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
    // The 2nd field of the struct argp option (the key field) is special because Argp automatically
    // detects if it is a viewable character to be used in a short option or not. 777 is not a printable character,
    // and this means the --ellipsis option will be a long option, with no short option equivalent

    // clang-format off
    // Hidden options require a balance of utility and information management
    struct argp_option options[] = {
        {.name = "dot", .key = 'd', .arg = "NUM", .flags = OPTION_ARG_OPTIONAL, .doc = "Show a dot on the screen"},
        {.name = "ellipsis", .key = 777, .arg = 0, .flags = OPTION_HIDDEN, .doc = "Show an ellipsis on the screen"},
        {.name = "dash", .key = 888, .arg = 0, .flags = 0, .doc = "Show a dash on the screen"},
        {0}
    };
    // clang-format on

    struct argp arg_parser = {
        .options = options,
        .parser = my_parse_options,
        .args_doc = NULL,
        .doc = NULL,
    };

    // And here we can see that we are indeed passing in a pointer to an int as the
    // 6th parameter of the argp_parse function, and the value it points to is 4.
    // When callback functions are employed in a C program, there is almost
    // always a way to pass your own piece of data into the callback function. The
    // 6th parameter of the argp_parse function is a way for you to pass any data you
    // want into your callback function. For command-line processing with Argp
    // this value is frequently a struct that contains flags that can be set by options.

    return argp_parse(&arg_parser, argc, argv, 0, NULL, NULL);
}
