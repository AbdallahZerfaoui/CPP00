#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream> 
#include <fstream>


bool isInArray(std::string command, std::string array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == command)
			return true;
	}
	return false;
}

void printEachStringOnNewLine(std::string array[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << '\n';
}

void readContactsFromFile(PhoneBook &phonebook, const std::string &filename, int n_lines) //TO: Should i keep it
{
	std::ifstream file(filename.c_str());
	
	if (!file) {
		std::cerr << "Unable to open file: " << filename << std::endl;
		return;
	}

	int i = 0;
	int idx_slot = 0;
	std::string line;

	while (std::getline(file, line) && i < n_lines) {
		std::istringstream iss(line);
		std::string infos[5];
		idx_slot = phonebook.getIndex();
		// cout << idx_slot << '\n';
		// Parse the line to extract the contact details
		if (iss >> infos[0] >> infos[1] >> infos[2] >> infos[3] >> infos[4]) 
		{
			Contact newContact(idx_slot, infos);
			phonebook.addContact(newContact);
		} 
		else 
		{
			std::cerr << "Error parsing line: " << line << std::endl;
		}
	}

	file.close();
}

void printFormatted(const std::string &str) 
{
	// Truncate and append a dot if the string is longer than 10 characters
	if (str.length() > 10) {
		std::cout << std::setw(10) << std::right << str.substr(0, 9) + ".";
	} else {
		std::cout << std::setw(10) << std::right << str;
	}
	std::cout << '|';  // Add the separator after the string
}