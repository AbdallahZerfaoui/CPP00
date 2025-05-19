#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

/**
getline(cin, answer);: Reads the entire line, including spaces.
cin >> answer;: Only reads up to the first space.
a string literal like "apple" is const char * and not char *
**/

// Getters
int PhoneBook::getSize() const { return _size; }
int PhoneBook::getNbrContactsAdded() const { return _nbr_contacts_added; }

// Setters
void PhoneBook::setSize(int size) { _size = size; }
void PhoneBook::setNbrContactsAdded(int nbr_contacts_added) { _nbr_contacts_added = nbr_contacts_added; }

// Constructor
PhoneBook::PhoneBook(int n_contacts):
	_size(0),
	_nbr_contacts_added(0)
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
	_size = (_size + 1 >= MAX_NBR_CONTACTS) ? MAX_NBR_CONTACTS : _size + 1;
	_nbr_contacts_added++;
}

void PhoneBook::addContact(Contact new_contact)
{
	int slot_idx = getIndex();
	bool is_full = (_nbr_contacts_added >= MAX_NBR_CONTACTS);

	contacts_list[slot_idx] = new_contact;
	contacts_list[slot_idx].setIndex(slot_idx);
	_size = is_full ? MAX_NBR_CONTACTS : _size + 1;
	_nbr_contacts_added++;
}

Contact PhoneBook::search(int target_index)
{
	int i = 0;
	while(contacts_list[i].getIndex() != target_index && 
			i < MAX_NBR_CONTACTS &&
			contacts_list[i].getIndex() != INIT_INDEX)
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
	for (int index = 0; index < _size; index++)
	{
		target_contact = contacts_list[index];

		//first line
		for (int i = 0; i < 4 * COLUMN_SIZE + 5; i++)
			std::cout << "-";

		std::cout << '\n' << '|';
		
		// second line
		std::cout << std::setw(COLUMN_SIZE) << std::right << target_contact.getIndex() << '|';
		printFormatted(target_contact.getFirstName());
		printFormatted(target_contact.getLastName());
		printFormatted(target_contact.getNickName()); std::cout << '\n';
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

	std::cout << "First name: " << target_contact.getFirstName() << std::endl;
	std::cout << "Last name: " << target_contact.getLastName() << std::endl;
	std::cout << "Nickname: " << target_contact.getNickName() << std::endl;
	std::cout << "Phone number: " << target_contact.getPhoneNumber() << std::endl;
	std::cout << "Dark secret: " << target_contact.getDarkSecret() << std::endl;
}

int PhoneBook::oldest_contact()
{
	int idx_oldest_contact = 
		(_nbr_contacts_added <= MAX_NBR_CONTACTS) ? 0 : _nbr_contacts_added - MAX_NBR_CONTACTS;
	return idx_oldest_contact;
}

int PhoneBook::getIndex()
{
	bool is_full = (_nbr_contacts_added >= MAX_NBR_CONTACTS);

	int idx_contact =
		is_full ? oldest_contact() : _nbr_contacts_added;

	return idx_contact;
}
