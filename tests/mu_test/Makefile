CC = gcc

CFLAGS  = -pedantic -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -g3
CFLAGS += -std=c99

LDLIBS = -lm

CPPFLAGS = -DDEBUG
CPPFLAGS += $(foreach dir, $(INCLUDE_DIRS), -I$(dir))


INC_BASE_DIR  = ../../inc
SRC_BASE_DIR = ../../src

INCLUDE_DIRS += $(INC_BASE_DIR)

OBJS = $(TARGET:%=%.o) $(SRC_BASE_DIR)/geometry.o
TARGET = utest

all : $(TARGET)

$(TARGET) : $(OBJS)

checks : $(TARGET)
	@./$(TARGET) -v

clean:
	@$(RM) ./$(TARGET) $(OBJS)

# dependencies
utest.c : $(INC_BASE_DIR)/geometry.h $(INC_BASE_DIR)/mu_test.h
$(SRC_BASE_DIR)/geometry.c : $(INC_BASE_DIR)/geometry.h

.PHONY : make clean checks
