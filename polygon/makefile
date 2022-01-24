CC=g++
CFLAGS=-g

ODIR=obj
IDIR=include
SDIR=src
TDIR=tst

_DEPS=polygonif.h integrity_checker.h rectangle.h triangle.h square.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DEPSC=integrity_checker.cc
DEPSC = $(patsubst %,$(SDIR)/%,$(_DEPSC))

_OBJ=integrity_checker.o triangle.o rectangle.o square.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC=integrity_checker.cc rectangle.cc triangle.cc square.cc
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
