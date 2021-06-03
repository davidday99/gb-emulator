
CC=gcc
INC=include
SRC=src
ODIR=build
CFLAGS=-I $(INC)

DEPS=$(wildcard include/*.h)

OBJ = $(patsubst $(SRC)/%.c, $(ODIR)/%.o, $(wildcard $(SRC)/*.c))

$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simulator: $(OBJ)
	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS)

$(OBJ): | $(ODIR)

$(ODIR):
	mkdir $(ODIR)

.PHONY: clean

clean:
	rm -f $(ODIR)