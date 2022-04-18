EXE = main
TEST = test
OBJS = main.o node.o graph.o dfs.o pagerank.o betweenness.o
TEST_OBJS = node.o graph.o dfs.o pagerank.o betweenness.o tests.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) -g -c
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm
OBJS_DIR = .objs


# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

all: $(EXE)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXE): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)

main.o: src/main.cpp src/graph.cpp src/graph.h src/dfs.cpp src/dfs.h src/pagerank.cpp src/pagerank.h
	$(CXX) $(CXXFLAGS) src/main.cpp

node.o: src/node.cpp src/node.h 
	$(CXX) $(CXXFLAGS) src/node.cpp

graph.o: src/graph.cpp src/graph.h src/node.cpp src/node.h src/betweenness.cpp src/betweenness.h src/dfs.cpp src/dfs.h
	$(CXX) $(CXXFLAGS) src/graph.cpp

betweenness.o: src/betweenness.cpp src/betweenness.h src/node.cpp src/node.h
	$(CXX) $(CXXFLAGS) src/betweenness.cpp

dfs.o: src/dfs.cpp src/dfs.h src/node.cpp src/node.h src/graph.cpp src/graph.h 
	$(CXX) $(CXXFLAGS) src/dfs.cpp

pagerank.o: src/pagerank.cpp src/pagerank.h src/node.cpp src/node.h src/graph.cpp src/graph.h 
	$(CXX) $(CXXFLAGS) src/pagerank.cpp

test: output_msg $(TEST_OBJS)
	$(LD) $(TEST_OBJS) $(LDFLAGS) -o test

tests.o: tests/tests.cpp tests/catch.hpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean:
	rm -rf $(EXE) $(TEST) $(OBJS_DIR) $(CLEAN_RM) *.o *.d

.PHONY: all test clean output_msg