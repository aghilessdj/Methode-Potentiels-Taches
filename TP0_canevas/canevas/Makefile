BDIR = bin
IDIR = include
ODIR = obj
SDIR = src

CC = gcc
CFLAGS= -Wall -I$(IDIR)

_PROG = my_first_git
PROG = $(patsubst %,$(BDIR)/%,$(_PROG))

_DEP = rational.h geometry.h list.h tree.h algo.h
DEP = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = rational.o geometry.o list.o tree.o algo.o test.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: run dirs clean delete

run: dirs $(PROG)
	./$(PROG)

dirs:
	@mkdir -p bin
	@mkdir -p obj
	
$(PROG) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEP)
	echo $@ " :: " $<
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(ODIR)
	rm -f data/output*
	
delete: clean
	rm -rf $(BDIR)
