CC = g++
CFLAGS =
LFLAGS = -O2
TARGETS = forward.out
OBJS = forward.o

all: $(TARGETS)

%.out: %.o
	$(CC) $(LFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^

test: $(TARGETS)
	./forward.out

clean:
	rm -rf $(TARGETS) $(OBJS)
