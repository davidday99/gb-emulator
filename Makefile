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
DEFINE := -D$(DEF)

sim: $(ODIR)/simulator

gb-cli: $(ODIR)/gb-cli

gb-gui: $(ODIR)/gb-gui

test: $(ODIR)/$(TEST)/test_runner
	./$(ODIR)/$(TEST)/test_runner

$(ODIR)/%.o: $(SRC)/%.c
ifeq ($(debug), 1)
	$(CC) -o $@ $^ -c -g -DDEBUG $(CFLAGS)
else
	$(CC) -o $@ $^ -c -g $(CFLAGS)
endif

$(ODIR)/simulator: $(filter-out $(ODIR)/gb_cli.o $(ODIR)/gb_gui.o, $(OBJS))
	$(CC) -o $@ $^ -g $(CFLAGS)

$(ODIR)/gb-cli: $(filter-out $(ODIR)/simulator.o $(ODIR)/gb_gui.o, $(OBJS))
	$(CC) -o $@ $^ -g $(CFLAGS)

$(ODIR)/gb-gui: $(filter-out $(ODIR)/simulator.o $(ODIR)/gb_cli.o, $(OBJS))
	$(CC) -o $@ $^ -g $(CFLAGS)

$(ODIR)/$(TEST)/%.o: $(TEST)/%.c 
	$(CC) -o $@ $^ -c -g $(CFLAGS)

$(ODIR)/$(TEST)/test_runner: $(TEST_OBJS) $(ODIR)/cpu.o $(ODIR)/isa-sm83.o
	$(CC) -o $@ $^ -g $(CFLAGS)

clean:
	rm -rf $(ODIR)/*

$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(ODIR)/$(TEST))

.PHONY: sim gb-cli gb-gui test clean