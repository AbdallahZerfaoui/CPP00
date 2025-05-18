#include "phonebook.hpp"
#include <iostream>

int main()
{
	std::cout << GREEN << "Welcome MASTER !!\n" << RESET; 

	PhoneBook phonebook(MAX_NBR_CONTACTS);
	std::string command;

	do 
	{
		std::string options[] = {"ADD", "SEARCH", "EXIT"};
		std::cout << "Please enter one of the following commands :\n";
		print_each_string_on_new_line(options, NBR_OPTIONS);

		// we loop until we get a valid command
		do
		{
			if (!(std::cin >> command))
			{
				if (std::cin.eof())
				{
					std::cout << RED << "Exiting...\n" << RESET;
					return 1;
				}
				std::cout << RED <<"Invalid command. Please enter a valid command\n" << RESET;
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
			if (!isInArray(command, options, NBR_OPTIONS))
				std::cout << RED << "Invalid command. Please enter a valid command\n" << RESET;

		} while (!isInArray(command, options, NBR_OPTIONS));

		if (command == "ADD")
		{
			phonebook.addFromUser();
		}
		else if (command == "SEARCH")
		{
			if (phonebook.size == 0)
			{
				std::cout << RED << "No contacts to display.\n" << RESET;
				continue;
			}
			phonebook.display_contactS();
			std::cout << "Enter the index of the contact please:\n";
			int index;
			std::cin >> index;
			if (std::cin.fail() || index < 0 
				|| index >= phonebook.size || index >= MAX_NBR_CONTACTS)
			{
				std::cout << RED << "Invalid index. Please enter a valid index\n" << RESET;
				std::cin.clear(); // clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			phonebook.display_contact(index);
		}

	} while (command != "EXIT");

	return 0;
}