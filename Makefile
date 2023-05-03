# my first ever makefile

CXX = g++

CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

FILES = main.o exceptions.h system.o

EXEC_FILE = acc-sys

$(EXEC_FILE): $(FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

debug: CXXFLAGS += -g3 -DDEBUG -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
debug: $(FILES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC_FILE)_debug
.PHONY: debug


clean:
	-rm -f *.o
	-rm -f $(EXEC_FILE)*
.PHONY: clean

# dependencies
system.o: system.cpp system.h

main.o: main.cpp