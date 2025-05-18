#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

/**
getline(cin, answer);: Reads the entire line, including spaces.
cin >> answer;: Only reads up to the first space.
a string literal like "apple" is const char * and not char *
**/

Contact::Contact(int index, std::string infos[])
{
	this->index = index;

	first_name = (infos == NULL) ? "" : infos[0];
	last_name = (infos == NULL) ? "" : infos[1];
	nickname = (infos == NULL) ? "" : infos[2];
	phone_number = (infos == NULL) ? "" : infos[3];
	dark_secret = (infos == NULL) ? "" : infos[4];

}

PhoneBook::PhoneBook(int n_contacts):
	size(0),
	nbr_contacts_added(0)
{
	std::string file_name = "contacts.txt";
	if (DEBUG_MODE)
		readContactsFromFile(*this, file_name, n_contacts);
}

void PhoneBook::addFromUser()
{
	int index = getIndex();

	const char *infos[] = {
		"First name", 
		"Last name", 
		"Nickname", 
		"Phone number", 
		"Dark secret",
		NULL};

	std::string answers[NBR_INFOS];

	std::cout << "Please enter the infos of your new contact" << "\n";
	
	for (int i = 0; infos[i] != NULL; i++)
	{
		std::cout << infos[i] << ":\n";
		std::string answer;

		getline(std::cin, answer);

		answers[i] = answer;
	}

	Contact contact(index, answers);
	contacts_list[index] = contact;
	// contacts_list[index].index = index; // only abdallah knows
	size = (size + 1 >= MAX_NBR_CONTACTS) ? MAX_NBR_CONTACTS : size + 1;
	nbr_contacts_added++;
}

void PhoneBook::addContact(Contact new_contact)
{
	int slot_idx = getIndex();
	bool is_full = (nbr_contacts_added >= MAX_NBR_CONTACTS);

	contacts_list[slot_idx] = new_contact;
	contacts_list[slot_idx].index = slot_idx;
	size = is_full ? MAX_NBR_CONTACTS : size + 1;
	nbr_contacts_added++;
}

Contact PhoneBook::search(int target_index)
{
	int i = 0;
	while(contacts_list[i].index != target_index && 
			i < MAX_NBR_CONTACTS &&
			contacts_list[i].index != INIT_INDEX)
	{	
		i++;
	}
	Contact contact;
	if (i == target_index){
		contact = contacts_list[i];
	}
	return contact;
}

/**
 * Print the contacts infos in the short
 * format when the user start a search
 */
void PhoneBook::displayContactS()
{
	Contact target_contact;
	for (int index = 0; index < size; index++)
	{
		target_contact = contacts_list[index];

		//first line
		for (int i = 0; i < 4 * COLUMN_SIZE + 5; i++)
			std::cout << "-";

		std::cout << '\n' << '|';
		
		// second line
		std::cout << std::setw(COLUMN_SIZE) << std::right << target_contact.index << '|';
		printFormatted(target_contact.first_name);
		printFormatted(target_contact.last_name);
		printFormatted(target_contact.nickname); std::cout << '\n';
	}

	//third line
	for (int i = 0; i < 4 * COLUMN_SIZE + 5; i++)
		std::cout << "-";
	
	std::cout << '\n';
}

/**
 * Print the contact infos in the long
 * format when the user select a specific contact
 */
void PhoneBook::displayContact(int index)
{
	Contact target_contact = search(index);

	//first line
	for (int i = 0; i < 5 * (COLUMN_SIZE + 1) + 1; i++)
		std::cout << "-";

	std::cout << '\n' << '|';
	
	// second line
	// cout << setw(10) << right << target_contact.index << '|';
	printFormatted(target_contact.first_name);
	printFormatted(target_contact.last_name);
	printFormatted(target_contact.nickname); 
	printFormatted(target_contact.phone_number);
	printFormatted(target_contact.dark_secret); std::cout << '\n';

	//third line
	for (int i = 0; i < 5 * (COLUMN_SIZE + 1) + 1; i++) {
		std::cout << "-";
	}
	std::cout << '\n';
}


int PhoneBook::oldest_contact()
{
	int idx_oldest_contact = 
		(nbr_contacts_added <= MAX_NBR_CONTACTS) ? 0 : nbr_contacts_added - MAX_NBR_CONTACTS;
	return idx_oldest_contact;
}

int PhoneBook::getIndex()
{
	bool is_full = (nbr_contacts_added >= MAX_NBR_CONTACTS);

	int idx_contact =
		is_full ? oldest_contact() : nbr_contacts_added;

	return idx_contact;
}
