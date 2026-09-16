#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const FragTrap &obj);
	FragTrap(const std::string &name);
	FragTrap &operator=(const FragTrap &obj);
	~FragTrap(void);

	void	highFivesGuys(void);
};

#endif
