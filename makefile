CXX= g++ # complier

CPP_FLAGS= -std=cpp11 -Wall -pedantic-errors -g #flags for c++
INC= -I ./include # linkes the all .h files to the project

SRCS= main.cpp ./src/* # targets that the make file watches
OBJS= ${SRCS: .cpp=.o} # creates the object files 
MAIN = game # name of the executable


all: ${MAIN} #complies and prints if successful
	@echo Successly compiled! 

${MAIN}: ${OBJS} #how the project is complied
	${CXX} ${CXXFLAGS} ${OBJS} ${INC} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@
