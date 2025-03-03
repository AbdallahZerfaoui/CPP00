#include <iostream>
#include <string>
#include <cctype> // for std::toupper

int main(int argc, char** argv) {
    // If no arguments are passed, print the feedback noise
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    // Iterate through all the arguments passed
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        // Convert each character in the argument to uppercase
        for (char& c : arg) {
            c = (char)std::toupper(c);
        }
		std::cout << arg;
        // Add a space between arguments (but not after the last one)
        if (i < argc - 1) {
            std::cout << " ";
        }
    }

    // Newline after all arguments are printed
    std::cout << std::endl;
    
    return 0;
}
