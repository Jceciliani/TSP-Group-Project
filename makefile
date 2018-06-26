CXX = g++
CXXFLAGS = -std=c++11

SOURCES = TSPAlgo.cpp

tsp: ${SOURCES}
	${CXX} ${CXXFLAGS} ${SOURCES} -o TSPAlgo

clean:
	rm *.o TSPAlgo
