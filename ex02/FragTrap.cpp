#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	this->m_hitPoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->m_energyPoints > 0)
	{
		if (this->m_hitPoints > 0)
		{
			std::cout << this->m_name << ": HIGH FIVES GUYS" << std::endl;
		}
		else
			std::cout << this->m_name << " is out of hit points." << std::endl;
	}
	else
		std::cout << this->m_name << " is out of energy points." << std::endl;
}