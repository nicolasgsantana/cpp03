#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Construction ===" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	std::cout << "\n=== Attack difference (message wording) ===" << std::endl;
	clap.attack("enemy");
	scav.attack("enemy");

	std::cout << "\n=== ScavTrap-specific ability ===" << std::endl;
	scav.guardGate();

	std::cout << "\n=== takeDamage / beRepaired ===" << std::endl;
	clap.takeDamage(50);
	clap.beRepaired(10);

	std::cout << "\n=== Copy constructor ===" << std::endl;
	ScavTrap scavCopy(scav);
	scavCopy.attack("copy-test-target");

	std::cout << "\n=== Assignment operator ===" << std::endl;
	ScavTrap scavAssigned("Temp");
	scavAssigned.takeDamage(80);
	scavAssigned = scav;
	scavAssigned.attack("post-assign-target");

	std::cout << "\n=== Energy depletion ===" << std::endl;
	ClapTrap depleted("Empty");
	for (int i = 0; i < 51; i++)
		depleted.attack("target");

	std::cout << "\n=== HP depletion ===" << std::endl;
	ClapTrap fragile("Fragile");
	fragile.takeDamage(1000);
	fragile.attack("target");

	std::cout << "\n=== Polymorphism (base pointer) ===" << std::endl;
	ClapTrap *poly = new ScavTrap("PolyScav");
	poly->attack("poly-target");
	delete poly;

	std::cout << "\n=== Destruction order ===" << std::endl;
	return (0);
}
