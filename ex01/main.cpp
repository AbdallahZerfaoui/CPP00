#include "phonebook.hpp"
#include <iostream>
#include <cctype>

int main()
{
	std::cout << GREEN << "Welcome MASTER !!\n" << RESET; 
	// bool valid_command = false;
	// bool book_open = true;

	PhoneBook phonebook(10);
	string command;

	do 
	{
		string options[] = {"ADD", "SEARCH", "EXIT"};
		std::cout << "Please enter one of the following commands :\n";
		display_array_V(options, NBR_OPTIONS);
		// we loop until we get a valid command
		do
		{
			// std::cin >> command; // we collect only the first word
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
				std::cout << "Invalid command. Please enter a valid command\n";

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
			if (cin.fail() || index < 0 || index >= MAX_NBR_CONTACTS)
			{
				std::cout << RED << "Invalid index. Please enter a valid index\n" << RESET;
				std::cin.clear(); // clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the line
				continue;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Contact contact = phonebook.search(index);
			// std::cout << contact.first_name << "\n";
			phonebook.display_contact(index);
		}

	} while (command != "EXIT");

	return 0;
}