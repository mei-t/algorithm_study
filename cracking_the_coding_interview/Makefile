# The options we want to give to g++
CXXFLAGS=-std=c++11 -Wall

16-12: 16-12.cpp tinyxml2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@