CC = g++
CFLAGS = -I. -g -std=c++11
OBJ = GameMechs.o objPos.o objPosArrayList.o MacUILib.o Player.o Project.o Food.o
DEPS = *.h
EXEC = Project

# Detect the OS
ifeq ($(OS),Windows_NT)
    OSSETTING = -DWINDOWS
    POSTLINKER =  # No need for ncurses on Windows
else
    OSSETTING = -DPOSIX
    POSTLINKER = -lncurses  # Link ncurses for POSIX systems (Linux/MacOS)
endif

# Rule to compile .cpp files into .o object files
%.o: %.cpp $(DEPS)
	$(CC) $(OSSETTING) -c -o $@ $< $(CFLAGS)

# Link the object files into the final executable
$(EXEC): $(OBJ)
	$(CC) $(OSSETTING) -o $@ $^ $(CFLAGS) $(POSTLINKER)

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC) $(EXEC).exe
