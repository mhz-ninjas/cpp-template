CXX= g++
CC = $(CXX)

CXXFLAGS  = -pedantic -Wall
CXXFLAGS += -Werror
CXXFLAGS += -Wextra
CXXFLAGS += -g3
CXXFLAGS += -std=c++17

CPPFLAGS = -DDEBUG

CPPFLAGS += $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

INC_BASE_DIR  = ../../inc
SRC_BASE_DIR = ../../src

INCLUDE_DIRS += $(INC_BASE_DIR)

OBJS = $(TARGET:%=%.o)
TARGET = utest

all: $(TARGET)

checks : all
	@./$(TARGET) -v

clean:
	@$(RM) ./$(TARGET) $(OBJS)

# dependencies
utest.cpp : classes_under_test.hpp $(INC_BASE_DIR)/mu_test.h

.PHONY : make clean check
