BIN := main 
SOURCES := main.cpp
CC := g++
CFLAGS := -g -Wall
DEPENDENCIES = glut_install.sh

LIBS = -lXmu -lXext -lX11 -lXi -lm
LIBGL = -lGLU -lGL -lglut
LIBGLUI = -L./lib -lglui
GLUI_LIB := lib/libglui.a

$(BIN): $(SOURCES) $(GLUI_LIB)
	clear && mkdir -p bin && $(CC) $(SOURCES) $(CFLAGS) $(LIBGLUI) $(LIBGL) $(LIBS) -o bin/$(BIN)

depend: 
	./$(DEPENDENCIES)

clean:
	rm -rf bin/$(BIN)