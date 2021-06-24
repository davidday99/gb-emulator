CC=gcc
INCLUDE=include
SRC=src
TEST=test
ODIR=build

SRCS := $(wildcard $(SRC)/*.c)
TESTS := $(wildcard $(TEST)/*.c)
OBJS := $(addprefix $(ODIR)/,$(notdir $(SRCS:.c=.o)))
TEST_OBJS := $(addprefix $(ODIR)/$(TEST)/,$(notdir $(TESTS:.c=.o)))

GTK_DEP := `pkg-config --cflags --libs gtk+-3.0`
CFLAGS := -I$(INCLUDE) $(GTK_DEP)

sim: $(ODIR)/simulator

gb: $(ODIR)/gb

test: $(ODIR)/$(TEST)/test_runner
	./$(ODIR)/$(TEST)/test_runner

$(ODIR)/%.o: $(SRC)/%.c
	$(CC) -o $@ $^ $(CFLAGS) -c -g `pkg-config --cflags --libs gtk+-3.0` $(debug)

$(ODIR)/simulator: $(filter-out $(ODIR)/gb.o, $(OBJS))
	$(CC) -o $@ $^ -g `pkg-config --cflags --libs gtk+-3.0`

$(ODIR)/gb: $(filter-out $(ODIR)/simulator.o, $(OBJS))
	$(CC) -o $@ $^ -g `pkg-config --cflags --libs gtk+-3.0`

$(ODIR)/$(TEST)/%.o: $(TEST)/%.c 
	$(CC) -o $@ $^ $(CFLAGS) -c -g

$(ODIR)/$(TEST)/test_runner: $(TEST_OBJS) $(ODIR)/cpu.o $(ODIR)/isa-sm83.o
	$(CC) -o $@ $^ -g

clean:
	rm -rf $(ODIR)/*

$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(ODIR)/$(TEST))

.PHONY: sim gb test clean