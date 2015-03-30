CC ?= gcc
CFLAGS = -std=c99 -Wall -Wextra -Ideps
DEPS = $(wildcard deps/*/*.c)
STEP_DEFINITIONS = $(wildcard features/*/*.c)

CSTEPS_INCLUDE_PATH = $(shell bundle exec csteps-include-path)

LIB = libatm.so

atm: atm.c $(DEPS)
	$(CC) $(CFLAGS) $^ -shared -o $(LIB)

step_definitions: atm.c $(DEPS) $(STEP_DEFINITIONS)
	$(CC) $(CFLAGS) -I. -I$(CSTEPS_INCLUDE_PATH) $^ -shared -o $(LIB)

features: step_definitions
	cucumber

clean:
	rm -f $(LIB)

install-deps:
	clib install stephenmathieson/assertion-macros.h

.PHONY: atm
