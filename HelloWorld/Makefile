PROJECT := helloworld
CC := clang++ -arch x86_64
OBJECTS := helloworld.o
LIB := -L /usr/lib

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CC) $^ -o $(PROJECT) $(LIB)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(PROJECT)
	rm -f *.o



