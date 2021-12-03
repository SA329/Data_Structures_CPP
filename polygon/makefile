CC=g++
CFLAGS=-g

ODIR=obj
IDIR=include
SDIR=src
TDIR=tst

_DEPS=polygon.h integrity_checker.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DEPSC=integrity_checker.cc
DEPSC = $(patsubst %,$(SDIR)/%,$(_DEPSC))

_OBJ=polygon.o integrity_checker.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC=polygon.cc integrity_checker.cc
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

_TEST=test.cc
TEST = $(patsubst %,$(TDIR)/%,$(_TEST))

$(ODIR)/%.o: $(SDIR)/%.cc $(DEPS) $(DEPSC)
	$(CC) -c -o $@ $< $(CFLAGS) 

.PHONY: all
all: $(OBJ) 

test: $(TEST) $(OBJ)
	$(CC) -o $(TDIR)/$@ $^ $(CFLAGS)

.PHONY: clean 

clean:
	rm -f $(ODIR)/*.o *~ core 
