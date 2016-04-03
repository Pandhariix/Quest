CC = g++ -std=c++11 -O2 -Wall
SRC = src/main.cpp src/startmenu.cpp src/soundmanager.cpp src/loadgamemenu.cpp src/optionsmenu.cpp
EXE = Quest
PATH_EXE = game
INC = libs/SFML-2.3.2/include
HEADERS = src/
LIB = libs/SFML-2.3.2/build/lib
LINK = -lsfml-audio-2 -lsfml-graphics-2 -lsfml-network-2 -lsfml-system-2 -lsfml-window-2

all:
	echo 'Compiling for $(OS)...'

ifeq ($(OS),Windows_NT)
	$(CC) $(SRC) -o $(PATH_EXE)/$(EXE) -I$(INC) -I$(HEADERS) -L$(LIB) $(LINK)

else
	echo 'not implemented for $(OS) for now'

endif

clean:

ifeq ($(OS),Windows_NT)
	del $(PATH_EXE)\$(EXE).exe

else

endif