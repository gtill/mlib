.PHONY: clean

stack.o: stack.c stack.h include/lib/stack.h
	$(CROSS_COMPILE)$(CC) --std=c99 -Wpedantic -Wall -Wextra -Wmissing-prototypes -Wstrict-prototypes -Iinclude -c stack.c
clean:
	rm -rf stack.o
