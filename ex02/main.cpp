#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "=== Construction ===" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FragTrap frag("Fraggy");

	std::cout << "\n=== Attack difference (message wording) ===" << std::endl;
	clap.attack("enemy");
	scav.attack("enemy");
	frag.attack("enemy");

	std::cout << "\n=== ScavTrap-specific ability ===" << std::endl;
	scav.guardGate();

	std::cout << "\n=== FragTrap-specific ability ===" << std::endl;
	frag.highFivesGuys();

	std::cout << "\n=== takeDamage / beRepaired ===" << std::endl;
	clap.takeDamage(50);
	clap.beRepaired(10);
	frag.takeDamage(20);
	frag.beRepaired(5);

	std::cout << "\n=== Copy constructor ===" << std::endl;
	ScavTrap scavCopy(scav);
	scavCopy.attack("copy-test-target");
	FragTrap fragCopy(frag);
	fragCopy.highFivesGuys();

	std::cout << "\n=== Assignment operator ===" << std::endl;
	ScavTrap scavAssigned("Temp");
	scavAssigned.takeDamage(80);
	scavAssigned = scav;
	scavAssigned.attack("post-assign-target");

	FragTrap fragAssigned("Temp");
	fragAssigned.takeDamage(90);
	fragAssigned = frag;
	fragAssigned.highFivesGuys();

	std::cout << "\n=== Energy depletion ===" << std::endl;
	ClapTrap depleted("Empty");
	for (int i = 0; i < 51; i++)
		depleted.attack("target");

	FragTrap fragDepleted("Empty");
	for (int i = 0; i < 101; i++)
		fragDepleted.highFivesGuys();

	std::cout << "\n=== HP depletion ===" << std::endl;
	ClapTrap fragile("Fragile");
	fragile.takeDamage(1000);
	fragile.attack("target");

	FragTrap fragFragile("Fragile");
	fragFragile.takeDamage(1000);
	fragFragile.highFivesGuys();

	std::cout << "\n=== Polymorphism (base pointer) ===" << std::endl;
	ClapTrap *polyScav = new ScavTrap("PolyScav");
	polyScav->attack("poly-target");
	delete polyScav;

	ClapTrap *polyFrag = new FragTrap("PolyFrag");
	polyFrag->attack("poly-target 2");
	delete polyFrag;

	std::cout << "\n=== Destruction order ===" << std::endl;
	return (0);
}