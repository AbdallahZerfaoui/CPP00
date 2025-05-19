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
CXX = c++
RM = rm -f

# Compiler flags:
# -std=c++17 : Use the C++17 standard
# -Wall      : Enable most common warnings
# -Wextra    : Enable extra warnings
# -g         : Generate debugging information
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g

# Name of the final executable
TARGET = megaphone

# Find all .cpp files in the current directory
SOURCES = megaphone.cpp

# Generate corresponding object file names (replace .cpp with .o)
OBJECTS = $(SOURCES:.cpp=.o)

# Default target: Build the executable
# This is the rule executed when you just type 'make'
all: art $(TARGET)

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

re: art fclean $(TARGET)

run: re
	@echo "${GREEN}Running $(TARGET)...${RESET}"
	./$(TARGET) "shhhhh... I think the students are asleep..."
	./$(TARGET) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(TARGET) "I am not a robot"
	./$(TARGET)

art:
	@echo "                                                                                                   "
	@echo "        CCCCCCCCCCCCCPPPPPPPPPPPPPPPPP   PPPPPPPPPPPPPPPPP        000000000          000000000     "
	@echo "     CCC::::::::::::CP::::::::::::::::P  P::::::::::::::::P     00:::::::::00      00:::::::::00   "
	@echo "   CC:::::::::::::::CP::::::PPPPPP:::::P P::::::PPPPPP:::::P  00:::::::::::::00  00:::::::::::::00 "
	@echo "  C:::::CCCCCCCC::::CPP:::::P     P:::::PPP:::::P     P:::::P0:::::::000:::::::00:::::::000:::::::0"
	@echo " C:::::C       CCCCCC  P::::P     P:::::P  P::::P     P:::::P0::::::0   0::::::00::::::0   0::::::0"
	@echo "C:::::C                P::::P     P:::::P  P::::P     P:::::P0:::::0     0:::::00:::::0     0:::::0"
	@echo "C:::::C                P::::PPPPPP:::::P   P::::PPPPPP:::::P 0:::::0     0:::::00:::::0     0:::::0"
	@echo "C:::::C                P:::::::::::::PP    P:::::::::::::PP  0:::::0 000 0:::::00:::::0 000 0:::::0"
	@echo "C:::::C                P::::PPPPPPPPP      P::::PPPPPPPPP    0:::::0 000 0:::::00:::::0 000 0:::::0"
	@echo "C:::::C                P::::P              P::::P            0:::::0     0:::::00:::::0     0:::::0"
	@echo "C:::::C                P::::P              P::::P            0:::::0     0:::::00:::::0     0:::::0"
	@echo " C:::::C       CCCCCC  P::::P              P::::P            0::::::0   0::::::00::::::0   0::::::0"
	@echo "  C:::::CCCCCCCC::::CPP::::::PP          PP::::::PP          0:::::::000:::::::00:::::::000:::::::0"
	@echo "   CC:::::::::::::::CP::::::::P          P::::::::P           00:::::::::::::00  00:::::::::::::00 "
	@echo "     CCC::::::::::::CP::::::::P          P::::::::P             00:::::::::00      00:::::::::00   "
	@echo "        CCCCCCCCCCCCCPPPPPPPPPP          PPPPPPPPPP               000000000          000000000     "


.PHONY: all clean fclean re art