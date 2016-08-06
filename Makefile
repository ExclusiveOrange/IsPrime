CXX ?= g++
CXXFLAGS = -std=c++11 -O3 -funroll-loops -ftree-vectorize -march=native
LIBS = -lm
RM ?= rm -f

PROGS = isprime countprimes isprimedumb makeprimelist countprimesdumb makeprimemap

all: $(PROGS)

$(PROGS): % : %.cpp isprime.hpp Makefile primeList.txt primeMap.txt
	$(CXX) $(CXXFLAGS) $(LIBS) -o $@ $<

clean :
	$(RM) $(PROGS)
