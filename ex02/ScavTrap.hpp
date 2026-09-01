#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const ScavTrap &obj);
	ScavTrap(const std::string &name);
	ScavTrap &operator=(const ScavTrap &obj);
	~ScavTrap(void);

	void	attack(const std::string &target);
	void	guardGate(void);
};

#endif
