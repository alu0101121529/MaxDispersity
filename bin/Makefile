IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=../src

.PHONY: all

_OBJ = matrix.o greedyAlgorithm.o 2ndGreedyAlgorithm.o localSearch.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: maxdispersity

$(ODIR)/matrix.o: $(ODIR)/matrix.cpp $(IDIR)/matrix.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/greedyAlgorithm.o: $(ODIR)/greedyAlgorithm.cpp $(IDIR)/greedyAlgorithm.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/2ndGreedyAlgorithm.o: $(ODIR)/2ndGreedyAlgorithm.cpp $(IDIR)/2ndGreedyAlgorithm.hpp
	$(CC) -c -o $@ $< $(CFLAGS)


$(ODIR)/grasp.o: $(ODIR)/localSearch.cpp $(IDIR)/localSearch.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)


maxdispersity: $(OBJ)
	$(CC)  -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./P1