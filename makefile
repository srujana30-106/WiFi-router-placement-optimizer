CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11
LDFLAGS = -lfreeglut -lopengl32 -lglu32

SRC = src/graph_loader.cpp src/optimizer.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)

BINDIR = bin

all: main vis

main: $(OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/main $(OBJ)

vis:
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) src/visualizer.cpp -o $(BINDIR)/vis $(LDFLAGS)

clean:
	rm -f src/*.o $(BINDIR)/main $(BINDIR)/vis
