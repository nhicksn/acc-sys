# my first ever makefile

CXX = g++

CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

FILES = main.cpp exceptions.h system.cpp system.h

acc-sys:
	$(CXX) $(CXXFLAGS) $(FILES) -o acc-sys

debug: CXXFLAGS += -g3 -DDEBUG -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
debug:
	$(CXX) $(CXXFLAGS) $(FILES) -o acc-sys_debug
.PHONY: debug


clean:
	-rm acc-sys*
.PHONY: clean