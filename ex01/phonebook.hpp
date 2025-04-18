#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <limits>
#include <exception>


using namespace std;

#define INIT_INDEX 99
#define MAX_NBR_CONTACTS 8
#define NBR_INFOS 5
#define NBR_OPTIONS 3
#define COLUMN_SIZE 10 

class Contact{
	public:
		int		index;
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	dark_secret;

		// Constructor
		Contact(int index = INIT_INDEX, string infos[NBR_INFOS] = NULL);
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
		PhoneBook(int n_contacts = 3);
};

// Helper functions
bool isInArray(string command, string array[], int size);
void display_array_V(string array[], int size);
void readContactsFromFile(PhoneBook &phonebook, const std::string &filename, int n_lines);
void printFormatted(const std::string &str);

#endif