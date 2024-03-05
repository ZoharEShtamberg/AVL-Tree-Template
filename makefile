CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic-errors -DNDEBUG -g -I.
EXEC = olympics	
OBJECTS = Contestant.o ContestantTree.o Country.o DoubleTree.o Team.o Olympicsa1.o maina1.o


$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^


Contestant.o: Contestant.cpp Contestant.h Scripts/wet1util.h AVLTree.h Exceptions.h StupidArr.h Country.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

ContestantTree.o: ContestantTree.cpp ContestantTree.h DoubleTree.h AVLTree.h Exceptions.h StupidArr.h Contestant.h Scripts/wet1util.h Country.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Country.o: Country.cpp Country.h AVLTree.h Exceptions.h StupidArr.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

DoubleTree.o: DoubleTree.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Team.o: Team.cpp Team.h ContestantTree.h DoubleTree.h AVLTree.h Exceptions.h StupidArr.h Contestant.h Scripts/wet1util.h Country.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Olympicsa1.o: Scripts/Olympicsa1.cpp Scripts/Olympicsa1.h Scripts/wet1util.h Scripts/../Team.h Scripts/../ContestantTree.h Scripts/../DoubleTree.h Scripts/../AVLTree.h Scripts/../Exceptions.h Scripts/../StupidArr.h Scripts/../Contestant.h Scripts/.././Scripts/wet1util.h Scripts/../Country.h Scripts/../Country.h Scripts/../AVLTree.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

maina1.o: Scripts/maina1.cpp Scripts/Olympicsa1.h Scripts/wet1util.h Scripts/../Team.h Scripts/../ContestantTree.h Scripts/../DoubleTree.h Scripts/../AVLTree.h Scripts/../Exceptions.h Scripts/../StupidArr.h Scripts/../Contestant.h Scripts/.././Scripts/wet1util.h Scripts/../Country.h Scripts/../Country.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXEC)