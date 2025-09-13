CC = gcc

CFLAGS += -std=c17
CFLAGS += -O0
CFLAGS += -g3
CFLAGS += -Wall -Wextra -pedantic
CFLAGS += -Werror
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wshadow
CPPFLAGS += -I$(INC_DIR)

INC_DIR = ../../inc
SRC_DIR = ../../src

LDFLAGS += -fPIC
LDLIBS += -lm

OBJS = $(SRCS:.c=.o)

SRCS = $(TARGET).c $(SRC_DIR)/funcs.c $(SRC_DIR)/geometry.c
TARGET = utest

$(TARGET): $(OBJS)

all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

clean:
	$(RM) $(TARGET) $(OBJS)

.PHONY: all clean check

# dependencies
utest.o : $(INC_DIR)/funcs.h
funcs.o : $(INC_DIR)/funcs.h
geometry.o : $(INC_DIR)/geometry.h

