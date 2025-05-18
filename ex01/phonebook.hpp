#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

// Colors
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Constants
#define INIT_INDEX 99
#define MAX_NBR_CONTACTS 8
#define NBR_INFOS 5
#define NBR_OPTIONS 3
#define COLUMN_SIZE 10
#define DEBUG_MODE 0 

class Contact {
	public:
		int		index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	dark_secret;

		// Constructor
		Contact(int index = INIT_INDEX, std::string infos[NBR_INFOS] = NULL);
};

class PhoneBook {
	public:
		Contact contacts_list[MAX_NBR_CONTACTS];
		int size;
		int nbr_contacts_added;

		void addFromUser();
		void addContact(Contact new_contact);
		Contact search(int index);
		void display_contactS();
		void display_contact(int index);
		int oldest_contact();
		int getIndex();
		PhoneBook(int n_contacts = MAX_NBR_CONTACTS);
};

// Helper functions
bool isInArray(std::string command, std::string array[], int size);
void display_array_V(std::string array[], int size);
void readContactsFromFile(PhoneBook &phonebook, const std::string &filename, int n_lines);
void printFormatted(const std::string &str);

#endif