CC=gcc
INCLUDE=include
SRC=src
TEST=test
ODIR=build

SRCS = $(wildcard $(SRC)/*.c)
TESTS = $(wildcard $(TEST)/*.c)
OBJS = $(addprefix $(ODIR)/,$(notdir $(SRCS:.c=.o)))
TEST_OBJS = $(addprefix $(ODIR)/$(TEST)/,$(notdir $(TESTS:.c=.o)))

CFLAGS = -I$(INCLUDE)

all: $(ODIR)/simulator

$(ODIR)/%.o: $(SRC)/%.c
	$(CC) -o $@ $^ $(CFLAGS) -c -g $(debug)

$(ODIR)/simulator: $(OBJS)
	$(CC) -o $@ $^ -g

test: $(ODIR)/$(TEST)/test_runner

$(ODIR)/$(TEST)/%.o: $(TEST)/%.c 
	$(CC) -o $@ $^ $(CFLAGS) -c -g

$(ODIR)/$(TEST)/test_runner: $(TEST_OBJS) $(ODIR)/cpu.o $(ODIR)/isa-sm83.o
	$(CC) -o $@ $^ -g
	./test_runner


clean:
	rm -rf $(ODIR)/*

$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(ODIR)/$(TEST))

.PHONY: all clean