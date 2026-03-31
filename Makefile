CXX = g++
CXXFLAGS = -std=c++20
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
OUT = mp3.out

all: $(OUT) cleanObj

$(OUT): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(OUT)

cleanObj:
	rm -f $(OBJ)

