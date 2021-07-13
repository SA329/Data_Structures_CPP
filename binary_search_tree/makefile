CC=g++
CFLAGS=-g

ODIR=obj
IDIR=include
SDIR=src
TDIR=tst
LDIR=./node/

OUTPUTFILE=libbstcc.a

_DEPS=binary_search_tree.h bst_helper_functions.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DEPSC=bst_display_functions.cc bst_check_integrity_functions.cc
DEPSC = $(patsubst %,$(SDIR)/%,$(_DEPSC))

_OBJ=binary_search_tree.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC=binary_search_tree.cc bst_display_functions.cc bst_check_integrity_functions.cc
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

_TEST=test.cc
TEST = $(patsubst %,$(TDIR)/%,$(_TEST))

$(ODIR)/%.o: $(SDIR)/%.c $(SDIR)/%.cc $(DEPS) $(DEPSC)
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
	rm -f $(ODIR)/*.o *~ core 
