CC  	:= gcc
CFLAGS 	:= -std=c17 -Wall -Wextra -Wpedantic -pedantic -Wundef -Wshadow -Walloca -Wvla -Wfloat-equal -Wstrict-prototypes \
		   -Wswitch-default -Wswitch-enum -Wconversion -Wimplicit-fallthrough -Wunreachable-code -Wformat=2 -Wparentheses \
		   -Wmisleading-indentation

.PHONY: step0

step0: step0.c
	$(CC) step0.c -o $@ $(CFLAGS)
