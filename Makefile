#Makefile

CXX=clang++
CXXFLAGS=-g -Wall -std=c++11
release=-O2
debug=-O0 -Wextra -pedantic -Wshadow -Wnon-virtual-dtor
OFILES=List.o ListItr.o ListNode.o postfixCalculator.o stack.o testPostfixCalc.o
 
release: CXXFLAGS+=$(release)
release: $(OFILES)
	$(CXX) $(OFILES)
	@echo "success"

debug: CXXFLAGS+=$(debug)
debug: $(OFILES)
	$(CXX) $(OFILES)
	@echo "debug mode"

.PHONY: clean
clean:      
	rm *.o a.out

List.o: List.cpp List.h ListNode.h ListItr.h
ListItr.o: ListItr.cpp ListItr.h ListNode.h List.h
ListNode.o: ListNode.cpp ListNode.h
postfixCalculator.o: postfixCalculator.cpp postfixCalculator.h stack.h \
	List.h ListNode.h ListItr.h
stack.o: stack.cpp stack.h List.h ListNode.h ListItr.h
testPostfixCalc.o: testPostfixCalc.cpp postfixCalculator.h stack.h List.h \
	ListNode.h ListItr.h
