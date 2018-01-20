# macros
CC = g++
OPTIONS = -static-libgcc -static-libstdc++
EXE = li.exe

# suffix rules
.cpp.o:
	$(CC) -c $< -o $@ $(OPTIONS)

$(EXE): main.o commands.o CommandProcess.o CommandLine.o exception.o
	$(CC) $^ -o $@ $(OPTIONS)
main.o: main.cpp class.h function.h
commands.o: commands.cpp extern.h
CommandProcess.o: CommandProcess.cpp extern.h function.h constant.h
CommandLine.o: CommandLine.cpp function.h
exception.o: exception.cpp class.h
