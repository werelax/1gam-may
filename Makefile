CXX = clang++
SDL = -framework SDL2 -framework SDL2_image
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
EXE = game

all: $(EXE)

$(EXE): game.o sprite.o main.o
	$(CXX) $(LDFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

game.o: game.cpp
	$(CXX) $(CXXFLAGS) -c $<

sprite.o: sprite.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o && rm $(EXE)
