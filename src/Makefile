IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj

_DEPS = issuerCategory.h issuerName.h utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = issuerCategory.o issuerName.o utils.o driver.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o ../$@ $^ $(CFLAGS)
