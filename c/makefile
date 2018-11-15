CC     := gcc
CFLAGS := -Wall
SRCS   := $(wildcard *.c)
OBJS   := $(patsubst %.c,%.o,$(SRCS))


.PHONY: all clean

all: $(OBJS)

%.out: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.out *.o