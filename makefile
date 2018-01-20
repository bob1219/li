# macros
CC = g++
OPTIONS = -static-libgcc -static-libstdc++
EXE = li.exe

$(EXE): main.o commands.o CommandProcess.o CommandLine.o exception.o
	$(CC) $^ -o $@ $(OPTIONS)

main.o: main.cpp class.h function.h
	$(CC) -c $< -o $@ $(OPTIONS)

commands.o: commands.cpp extern.h
	$(CC) -c $< -o $@ $(OPTIONS)

CommandProcess.o: CommandProcess.cpp extern.h function.h constant.h
	$(CC) -c $< -o $@ $(OPTIONS)

CommandLine.o: CommandLine.cpp function.h
	$(CC) -c $< -o $@ $(OPTIONS)

exception.o: exception.cpp class.h
	$(CC) -c $< -o $@ $(OPTIONS)
