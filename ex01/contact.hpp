#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "constants.hpp"
# include <string>


class Contact
{
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkSecret;
	
	public:
		// Getters
		int			getIndex() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkSecret() const;

		// Setters
		void		setIndex(int index);
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickname(std::string nickName);
		void		setPhoneNumber(std::string phoneNumber);
		void		setDarkSecret(std::string darkSecret);

		// Constructor
		Contact();
		Contact(int index = INIT_INDEX, std::string infos[NBR_INFOS] = NULL);
};

#endif