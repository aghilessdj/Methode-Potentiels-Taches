IDIR = include
ODIR = obj
SDIR = src
BDIR = bin

CC = gcc
CFLAGS = -Wall -I$(IDIR) -c -g

LDFLAGS = -lm

PROG=$(BDIR)/mat

_DEPS = job_1.h job_2.h job_3.h elmlist.h list_1.h list_2.h rank.h io.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS= main.o job.o io.o elmlist.o list.o rank.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

.PHONY : run all dirs clean delete

run : all
	./$(PROG)

all : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS)

$(ODIR)/%.o : $(SDIR)/%.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

dirs :
	@mkdir -p $(ODIR) $(BDIR)

clean :	
	rm -rf $(ODIR) core

delete : clean
	rm -rf $(BDIR)