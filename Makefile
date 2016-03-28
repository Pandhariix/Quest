CC = g++ -std=c++11 -O2 -Wall
SRC = src/main.cpp src/startmenu.cpp
EXE = Quest
INC = libs/SFML-2.3.2/include/SFML
HEADERS = src/
LIB = libs/SFML-2.3.2/bin
LINK = -lsfml-window-2 -lsfml-window-d-2

all:
	echo 'Compiling for $(OS)...'

ifeq ($(OS),Windows_NT)
	$(CC) $(SRC) -o $(EXE) -I$(INC) -I$(HEADERS) -L$(LIB) $(LINK)

else
	echo 'not implemented for $(OS) for now'

endif

clean:

ifeq ($(OS),Windows_NT)
	del Quest.exe

else

endif