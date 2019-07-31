CC = g++-7
CFLAGS = -Wall -g
TARGET = c4
OBJS = c4.o node.o mcst.o main.o heuristics.o minimax.o hmcst.o

all: $(TARGET)

%.o : %.cpp
	$(CC) -c $(CFLAGS) $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)
