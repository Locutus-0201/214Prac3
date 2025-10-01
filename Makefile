CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g -MMD -MP

TARGET := mediator_test

# Find all .cpp files except any main.cpp (to avoid conflicts)
SRCS := $(filter-out main.cpp, $(wildcard *.cpp))

OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean rebuild

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

rebuild: clean all

test: run