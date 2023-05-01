# my first ever makefile

CXX = g++

CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

acc-sys:
	$(CXX) $(CXXFLAGS) main.cpp system.cpp system.h -o acc-sys

debug: CXXFLAGS += -g3 -DDEBUG -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
debug:
	$(CXX) $(CXXFLAGS) main.cpp system.cpp system.h -o acc-sys_debug
.PHONY: debug


clean:
	-rm acc-sys*
.PHONY: clean