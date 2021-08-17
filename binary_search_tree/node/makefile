CC=g++
CFLAGS=-g

ODIR=obj
IDIR=include
SDIR=src
TDIR=tst

OUTPUTFILE=libbstcc_node.a

_DEPS=bst_node.h bst_terminal_node.h bst_node_if.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=bst_node.o bst_terminal_node.o bst_node_if.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC=bst_node.cc bst_terminal_node.cc bst_node_if.cc
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

_TEST=test_node.cc
TEST = $(patsubst %,$(TDIR)/%,$(_TEST))

$(ODIR)/%.o: $(SDIR)/%.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

.PHONY: all
all: $(OUTPUTFILE)

$(OUTPUTFILE): $(OBJ)
	ar -rc $@ $^
	ranlib $@

test: $(TEST) $(OBJ)
	$(CC) -o $(TDIR)/$@ $^ $(CFLAGS)

.PHONY: clean 

clean:
	rm -f $(ODIR)/*.o *~ core $(OUTPUTFILE) *~ core
