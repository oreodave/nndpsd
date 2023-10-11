CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wswitch-enum -ggdb -fsanitize=address -std=c11
LIBS=
ARGS=
OUT=main.out

SRC=src
DIST=build

CODE=$(addprefix $(SRC)/, main.c)
OBJECTS=$(CODE:$(SRC)/%.c=$(DIST)/%.o)
DEPS=$(OBJECTS:%.o=%.d)

.PHONY: all
all: $(OUT)

$(OUT): $(DIST)/$(OUT)

$(DIST)/$(OUT): $(OBJECTS)
	mkdir -p $(DIST)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

-include $(DEPS)

$(DIST)/%.o: $(SRC)/%.c
	mkdir -p $(DIST)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(LIBS)

.PHONY: run
run: $(DIST)/$(OUT)
	./$^ $(ARGS)

.PHONY:
clean:
	rm -rfv $(DIST)/*
