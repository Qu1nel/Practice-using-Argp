CC  	:= gcc
CFLAGS 	:= -std=c17 -Wall -Wextra -Wpedantic -pedantic -Wundef -Wshadow -Walloca -Wvla -Wfloat-equal -Wstrict-prototypes \
		   -Wswitch-default -Wswitch-enum -Wconversion -Wimplicit-fallthrough -Wunreachable-code -Wformat=2 -Wparentheses \
		   -Wmisleading-indentation

.PHONY: clean step0 step1

step0: step0.c
	$(CC) $< -o $@ $(CFLAGS)

step1: step1.c
	$(CC) $< -o $@ $(CFLAGS)

step2: step2.c
	$(CC) $< -o $@ $(CFLAGS)

step3: step3.c
	$(CC) $< -o $@ $(CFLAGS)

step4: step4.c
	$(CC) $< -o $@ $(CFLAGS)

step5: step5.c
	$(CC) $< -o $@ $(CFLAGS)

clean:
	@rm -v $(shell find . -type f -name 'step?') 2>/dev/null
