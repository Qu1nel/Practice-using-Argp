CC  	:= gcc
CFLAGS 	:= -std=c17 -Wall -Wextra -Wpedantic -pedantic -Wundef -Wshadow -Walloca -Wvla -Wfloat-equal -Wstrict-prototypes \
		   -Wswitch-default -Wswitch-enum -Wconversion -Wimplicit-fallthrough -Wunreachable-code -Wformat=2 -Wparentheses \
		   -Wmisleading-indentation

.PHONY: clean step0 step1 step2 step3 step4 step5 step6 step7 step8 step9 step10 step11 lib

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

step6: step6.c
	$(CC) $< -o $@ $(CFLAGS)

step7: step7.c
	$(CC) $< -o $@ $(CFLAGS)

step8: step8.c
	$(CC) $< -o $@ $(CFLAGS)

step9: step9.c
	$(CC) $< -o $@ $(CFLAGS)

step10: step10.c
	$(CC) $< -o $@ $(CFLAGS)

step11: step11.c
	$(CC) $< -L. -ldotdash -o $@ $(CFLAGS)

lib: dotdash.c
	$(CC) -c -o dotdash.o $< $(CFLAGS)
	ar cru libdotdash.a dotdash.o
	ranlib libdotdash.a

clean:
	@rm -v dotdash.o
	@rm -v $(shell find . -type f -name 'step?' -or -name 'step??') 2>/dev/null
