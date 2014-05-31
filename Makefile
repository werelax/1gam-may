CXX = clang++
SDL = -framework SDL2 -framework SDL2_image
CXXFLAGS = -Wall -c -std=c++11 -g
LDFLAGS = $(SDL) -ljansson
EXE = game

all: $(EXE)

$(EXE): inputhandler.o game.o character.o sprite.o gameobject.o wall.o texturemanager.o main.o
	$(CXX) $(LDFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $<

game.o: Game.cpp
	$(CXX) $(CXXFLAGS) -c $<

gameobject.o: GameObject.cpp
	$(CXX) $(CXXFLAGS) -c $<

sprite.o: Sprite.cpp
	$(CXX) $(CXXFLAGS) -c $<

character.o: Character.cpp
	$(CXX) $(CXXFLAGS) -c $<

texturemanager.o: TextureManager.cpp
	$(CXX) $(CXXFLAGS) -c $<

wall.o: Wall.cpp
	$(CXX) $(CXXFLAGS) -c $<

# vector2d.o: Vector2D.cpp
# 	$(CXX) $(CXXFLAGS) -c $<

inputhandler.o: InputHandler.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o && rm $(EXE)
