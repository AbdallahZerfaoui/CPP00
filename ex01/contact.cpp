#include "contact.hpp"
#include <string>

// Getters
int Contact::getIndex() const { return _index; }
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickName() const { return _nickName; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkSecret() const { return _darkSecret; }

// Setters
void Contact::setIndex(int index) { _index = index; }
void Contact::setFirstName(std::string firstName) { _firstName = firstName; }
void Contact::setLastName(std::string lastName) { _lastName = lastName; }
void Contact::setNickname(std::string nickName) { _nickName = nickName; }
void Contact::setPhoneNumber(std::string phoneNumber) { _phoneNumber = phoneNumber; }
void Contact::setDarkSecret(std::string darkSecret) { _darkSecret = darkSecret; }

// Constructors
Contact::Contact(): _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkSecret("") {
	this->_index = INIT_INDEX; 
}

Contact::Contact(int index, std::string infos[])
{
	this->_index = index;

	_firstName = (infos == NULL) ? "" : infos[0];
	_lastName = (infos == NULL) ? "" : infos[1];
	_nickName = (infos == NULL) ? "" : infos[2];
	_phoneNumber = (infos == NULL) ? "" : infos[3];
	_darkSecret = (infos == NULL) ? "" : infos[4];

}