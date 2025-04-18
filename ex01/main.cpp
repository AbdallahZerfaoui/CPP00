#include "phonebook.hpp"
#include <iostream>
#include <cctype>

int main()
{
	std::cout << "Welcome MASTER !!\n"; 
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
					std::cout << "Exiting...\n";
					return 1;
				}
				std::cout << "Invalid command. Please enter a valid command\n";
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
			phonebook.display_contactS();
			std::cout << "Enter the index of the contact please:\n";
			int index;
			std::cin >> index;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// Contact contact = phonebook.search(index);
			// std::cout << contact.first_name << "\n";
			phonebook.display_contact(index);
		}

	} while (command != "EXIT");

	return 0;
}