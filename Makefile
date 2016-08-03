CXX ?= g++-6
CXXFLAGS = -std=c++11 -O3

PROGS = isprime countprimes

all: $(PROGS)

$(PROGS): % : %.cpp isprime.hpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean :
	$(RM) $(PROGS)
