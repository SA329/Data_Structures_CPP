CC=g++
CFLAGS=-g

ODIR=obj
IDIR=include
SDIR=src
TDIR=tst
LDIR=./node/

OUTPUTFILE=libbstcc.a

_DEPS=binary_search_tree.h integrity_checker.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DEPSC=integrity_checker.cc
DEPSC = $(patsubst %,$(SDIR)/%,$(_DEPSC))

_OBJ=binary_search_tree.o integrity_checker.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC=binary_search_tree.cc integrity_checker.cc
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

_TEST=test.cc
TEST = $(patsubst %,$(TDIR)/%,$(_TEST))

$(ODIR)/%.o: $(SDIR)/%.cc $(DEPS) $(DEPSC)
	$(CC) -c -o $@ $< $(CFLAGS) 

.PHONY: all
all: $(OUTPUTFILE)

$(OUTPUTFILE): $(OBJ)
	ar -rc $@ $^
	ranlib $@

test: $(TEST) $(OBJ)
	$(CC) -o $(TDIR)/$@ $^ $(CFLAGS) -L$(LDIR) -lbstcc_node

.PHONY: clean 

clean:
	rm -f $(ODIR)/*.o $(OUTPUTFILE) *~ core 
