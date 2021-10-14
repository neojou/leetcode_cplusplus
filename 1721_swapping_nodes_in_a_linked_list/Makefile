PROJECT := listnode 

CC := clang++
OBJS := listnode.o

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



