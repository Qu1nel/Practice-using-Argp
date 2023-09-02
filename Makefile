CC  := clang

.PHONY: step0
step0: step0.c
	$(CC) step0.c -o step0
