CC  	:= clang
CFLAGS 	:= -std=c17 -Wall -Wextra -Wpedantic -pedantic -Wundef -Wshadow -Walloca -Wvla -Wfloat-equal -Wstrict-prototypes \
		   -Wswitch-default -Wswitch-enum -Wconversion -Wimplicit-fallthrough -Wunreachable-code -Wformat=2 -Wparentheses \
		   -Wmisleading-indentation

.PHONY: all readline dotdash

all: readline dotdash morse-tool.c morse.c
	$(CC) morse-tool.c morse.c -L. -ldotdash -lreadline-argp -lreadline -o morse-tool

readline: readline-argp.c
	$(CC) -c -o readline-argp.o readline-argp.c
	ar cru libreadline-argp.a readline-argp.o
	ranlib libreadline-argp.a

dotdash: dotdash.c
	$(CC) -c -o dotdash.o $< $(CFLAGS)
	ar cru libdotdash.a dotdash.o
	ranlib libdotdash.a

clean:
	@rm -v dotdash.o
	@rm -v readline-argp.o
