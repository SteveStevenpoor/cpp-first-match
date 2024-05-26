BIN_NAME	= match

SRCS		= main.cpp\
			  src/match_test.cpp

HEADERS		= include/match.h

OBJ			= $(SRCS:.cpp=.o)

CC			= g++

CFLAGS		= -fsanitize=address -Iinclude -std=c++20

LDFLAGS		= -fsanitize=address -lgtest -pthread

all: $(BIN_NAME) clean

clean:
	@rm -rf *.o src/*.o

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@