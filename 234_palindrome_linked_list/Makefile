PROJECT := is_palindrome

CC := clang++
OBJS := is_palindrome.o

CFLAGS := -arch x86_64 --std=c++11
LIB := -L /usr/lib

all: $(PROJECT)

$(PROJECT): $(OBJS)
	$(CC) $^ -o $(PROJECT) $(LIB)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(PROJECT)
	rm -f *.o



