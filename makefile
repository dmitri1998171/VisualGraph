BIN_1 := main 
SOURCES_1 := main.cpp
CC := c++
CFLAGS :=
LDFLAGS := -L./ -lGL -lGLU -lglut -lglui

$(BIN_1): $(SOURCES_1) $(DEPENDENCIES)
	clear && $(CC) $(SOURCES_1) $(DEPENDENCIES) $(LDFLAGS) -o $(BIN_1)
clean:
	rm -rf $(BIN_1)