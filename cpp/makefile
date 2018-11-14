CC     := g++
CFLAGS := -Wall
SRCS   := $(wildcard *.cpp)
OBJS   := $(patsubst %.cpp,%.out,$(SRCS))


.PHONY: all clean

all: $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f *.out *.o