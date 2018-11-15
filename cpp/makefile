CC     := g++
CFLAGS := -Wall
SRCS   := $(wildcard *.cpp)
OBJS   := $(patsubst %.cpp,%.out,$(SRCS))


.PHONY: all clean

all: $(OBJS)

%.out: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.out *.o