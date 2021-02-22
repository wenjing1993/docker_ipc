CC := gcc
CXX := g++

CFLAGS += -std=c99
CXXFLAGS += -std=c++11

OBJS1 := share1.o
OBJS2 := share2.o

TARGET1 := share1
TARGET2 := share2

all: $(TARGET1) $(TARGET2)

$(TARGET1):$(OBJS1)
	$(CXX) $^ $(CXXFLAGS) -o $@

$(TARGET2):$(OBJS2)
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -f $(OBJS1) $(OBJS2) $(TARGET1) $(TARGET2)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^
