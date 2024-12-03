CC = g++
CFLAGS = -I. -g
OBJ = GameMechs.o objPos.o objPosArrayList.o MacUILib.o Player.o Project.o Food.o # Include Food.o in the object list
DEPS = *.h
EXEC = Project

ifeq (${OS}, Windows_NT)
    OSSETTING = -DWINDOWS
else
    OSSETTING = -DPOSIX
    POSTLINKER = -lncurses
endif

# Rule for compiling .o files from .cpp files
%.o: %.cpp $(DEPS)
	$(CC) ${OSSETTING} -c -o $@ $< $(CFLAGS)

# Rule for linking the executable
${EXEC} : $(OBJ)
	$(CC) ${OSSETTING} -o $@ $^ $(CFLAGS) ${POSTLINKER}

# Clean up the compiled files and executable
clean :
	rm -f $(OBJ) ${EXEC} ${EXEC}.exe
