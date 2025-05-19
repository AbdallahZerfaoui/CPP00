#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"
# include "constants.hpp"
# include <string>

// Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

class PhoneBook
{
	private:
		Contact contacts_list[MAX_NBR_CONTACTS];
		int _size;
		int _nbr_contacts_added;

		int oldest_contact();

	public:
		// Getters
		int getSize() const;
		int getNbrContactsAdded() const;

		// Setters
		void setSize(int size);
		void setNbrContactsAdded(int nbr_contacts_added);

		// Methods
		void addFromUser();
		void addContact(Contact new_contact);
		Contact search(int index);
		void displayContactS();
		void displayContact(int index);
		int getIndex();

		// Constructor
		PhoneBook(int n_contacts = MAX_NBR_CONTACTS);
};

// Helper functions
bool isInArray(std::string command, std::string array[], int size);
void printEachStringOnNewLine(std::string array[], int size);
void readContactsFromFile(PhoneBook &phonebook, const std::string &filename, int n_lines);
void printFormatted(const std::string &str);

#endif