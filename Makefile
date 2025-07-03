# Makefile for Snake Game in C

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lncurses

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Target executable
TARGET = $(BINDIR)/main

# Default target
all: $(TARGET)

# Create target executable
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Clean up generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Clean and rebuild
rebuild: clean all

# Install dependencies (for Ubuntu/Debian)
install-deps:
	sudo apt-get update
	sudo apt-get install libncurses5-dev libncursesw5-dev

# Run the game
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -DDEBUG
debug: $(TARGET)

# Release build
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all         - Build the game (default)"
	@echo "  clean       - Remove generated files"
	@echo "  rebuild     - Clean and build"
	@echo "  run         - Build and run the game"
	@echo "  debug       - Build with debug symbols"
	@echo "  release     - Build optimized release version"
	@echo "  install-deps- Install ncurses development libraries"
	@echo "  help        - Show this help message"

# Declare phony targets
.PHONY: all clean rebuild run debug release install-deps help
