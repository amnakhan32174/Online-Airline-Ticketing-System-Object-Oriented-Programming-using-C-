# Makefile for PIA Booking System
# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
TARGET = pia_booking_system

# Source files
SOURCES = main.cpp \
          Menu.cpp \
          BookingSystem.cpp \
          Passenger.cpp \
          Flight.cpp \
          Utils.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = Menu.h \
          BookingSystem.h \
          Passenger.h \
          Flight.h \
          Utils.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Clean and rebuild
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the project (default)"
	@echo "  clean   - Remove build files"
	@echo "  rebuild - Clean and rebuild"
	@echo "  run     - Build and run the program"
	@echo "  help    - Show this help message"

.PHONY: all clean rebuild run help
