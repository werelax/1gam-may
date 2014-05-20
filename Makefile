CXX = clang++
SDL = -framework SDL2 -framework SDL2_image
CXXFLAGS = -Wall -c -std=c++11 -g
LDFLAGS = $(SDL)
EXE = game

all: $(EXE)

$(EXE): game.o sprite.o texturemanager.o main.o
	$(CXX) $(LDFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

game.o: Game.cpp
	$(CXX) $(CXXFLAGS) -c $<

sprite.o: Sprite.cpp
	$(CXX) $(CXXFLAGS) -c $<

texturemanager.o: TextureManager.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o && rm $(EXE)
