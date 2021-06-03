CC=gcc
INCLUDE=include
SRC=src
ODIR=build

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(addprefix $(ODIR)/,$(notdir $(SRCS:.c=.o)))
CFLAGS = -I$(INCLUDE)

all: $(ODIR)/simulator

$(ODIR)/%.o: $(SRC)/%.c
	$(CC) -o $@ $^ $(CFLAGS) -c

$(ODIR)/simulator: $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(ODIR)/*

$(shell mkdir -p $(ODIR))

.PHONY: all clean