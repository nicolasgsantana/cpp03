#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
protected:
	std::string		m_name;
	unsigned int	m_hitPoints;
	unsigned int	m_energyPoints;
	unsigned int	m_attackDamage;

public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &obj);
	ClapTrap &operator=(const ClapTrap &obj);
	virtual ~ClapTrap(void);

	ClapTrap(const std::string &name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
