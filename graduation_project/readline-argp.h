#ifndef READLINE_ARGP_H
#define READLINE_ARGP_H
#include <argp.h>
extern struct argp readline_argp;
extern char* default_history_file;

struct readline_arguments {
    char* history_file;
};
#endif  // !READLINE_ARGP_H
