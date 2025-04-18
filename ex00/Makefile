# =============================================================================
#      COLOR DEFINITIONS
#      These variables define color codes for terminal output.
# =============================================================================
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif
# =============================================================================

# Compiler
CXX = g++
RM = rm -f

# Compiler flags:
# -std=c++17 : Use the C++17 standard
# -Wall      : Enable most common warnings
# -Wextra    : Enable extra warnings
# -g         : Generate debugging information
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g

# Linker flags (if any, e.g., -lm for math library)
# LDFLAGS =

# Name of the final executable
TARGET = megaphone

# Find all .cpp files in the current directory
SOURCES = megaphone.cpp
# Generate corresponding object file names (replace .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target: Build the executable
# This is the rule executed when you just type 'make'
all: $(TARGET)

# Rule to link the executable
# Depends on all object files
$(TARGET): $(OBJECTS)
	@echo "${GREEN}Linking $(TARGET)...${RESET}"
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Pattern rule to compile .cpp files into .o files
# $< is the first prerequisite (.cpp file)
# $@ is the target (.o file)
%.o: %.cpp
	@echo "${GREEN}Compiling $<...${RESET}"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "${GREEN}Cleaning up...${RESET}"
	$(RM) $(OBJECTS)

# Rule to clean up generated files
# .PHONY prevents 'make' from confusing this rule with a file named 'clean'
fclean: clean
	$(RM) $(TARGET)

re: fclean all


.PHONY: all clean fclean re