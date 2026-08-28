#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : m_name("ClapTrap"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->m_name = obj.m_name;
		this->m_hitPoints = obj.m_hitPoints;
		this->m_energyPoints = obj.m_energyPoints;
		this->m_attackDamage = obj.m_attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "String constructor called" << std::endl;
	this->m_name = name;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->m_energyPoints > 0)
	{
		if (this->m_hitPoints > 0)
		{
			--this->m_energyPoints;
			std::cout << this->m_name << " attacks " << target << ", causing "
				<< this->m_attackDamage << " points of damage!" << std::endl;
		}
		else
			std::cout << this->m_name << " is out of hit points." << std::endl;
	}
	else
		std::cout << this->m_name << " is out of energy points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoints < amount)
		this->m_hitPoints = 0;
	else
		this->m_hitPoints -= amount;
	std::cout << this->m_name << " took " << amount << " points of damage, being left with "
		<< this->m_hitPoints << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_energyPoints > 0)
	{
		if (this->m_hitPoints > 0)
		{
			--this->m_energyPoints;
			this->m_hitPoints += amount;
			std::cout << this->m_name << " repairs itself by " << amount << "hit points, and now has " << this->m_hitPoints << " hit points." << std::endl;
		}
		else
			std::cout << this->m_name << " is out of hit points." << std::endl;
	}
	else
		std::cout << this->m_name << " is out of energy points." << std::endl;
}
