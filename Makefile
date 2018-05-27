CXX = g++
TARGET = multinumeralsystemsconverter
CPPFILES = src/MainWindow.cpp src/main.cpp
OBJS = $(CPPFILES:.cpp=.o)
CXXFLAGS = `pkg-config --cflags gtkmm-3.0` -Wall -pedantic
LIBS = `pkg-config --libs gtkmm-3.0`

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)