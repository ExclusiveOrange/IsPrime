CXX ?= g++
CXXFLAGS = -std=c++11 -O3
RM ?= rm -f

PROGS = isprime countprimes

all: $(PROGS)

$(PROGS): % : %.cpp isprime.hpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean :
	$(RM) $(PROGS)
