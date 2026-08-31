#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->m_energyPoints > 0)
	{
		if (this->m_hitPoints > 0)
		{
			--this->m_energyPoints;
			std::cout << this->m_name << " stabs " << target << " " << this->m_attackDamage
				<< " times. AWESOME!" << std::endl;
		}
		else
			std::cout << this->m_name << " is out of hit points." << std::endl;
	}
	else
		std::cout << this->m_name << " is out of energy points." << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->m_energyPoints > 0)
	{
		if (this->m_hitPoints > 0)
		{
			std::cout << this->m_name << " is now guarding the gate!" << std::endl;
		}
		else
			std::cout << this->m_name << " is out of hit points." << std::endl;
	}
	else
		std::cout << this->m_name << " is out of energy points." << std::endl;
}
