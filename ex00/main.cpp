#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "\n=== Test 1: Default constructor ===\n";
	{
		ClapTrap  defaultTrap;
		defaultTrap.attack("a rock");
	}

	std::cout << "\n=== Test 2: String constructor ===\n";
	{
		ClapTrap  namedTrap("Bumblebee");
		namedTrap.attack("Barricade");
	}

	std::cout << "\n=== Test 3: takeDamage (normal + overkill) ===\n";
	{
		ClapTrap  trap("Grimlock");
		trap.takeDamage(4);
		trap.takeDamage(4);
		trap.takeDamage(10);
	}

	std::cout << "\n=== Test 4: beRepaired ===\n";
	{
		ClapTrap  trap("Wheeljack");
		trap.takeDamage(6);
		trap.beRepaired(3);
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 5: energyPoints reaching 0 ===\n";
	{
		ClapTrap  trap("Ironhide");
		for (int i = 0; i < 10; ++i)
			trap.attack("training dummy");
		trap.attack("training dummy");
		trap.beRepaired(1);
		std::cout << std::endl;
	}

	std::cout << "\n=== Test 6: hitPoints reaching 0 ===\n";
	{
		ClapTrap  trap("Sideswipe");
		trap.takeDamage(15);
		trap.attack("a wall");
	}

	std::cout << "\n=== Test 7: Copy constructor ===\n";
	{
		ClapTrap  original("Optimus");
		original.takeDamage(3);
		ClapTrap  copy(original);
		copy.attack("Megatron");
	}

	std::cout << "\n=== Test 8: Copy assignment operator ===\n";
	{
		ClapTrap  a("Jazz");
		ClapTrap  b("Prowl");
		a.takeDamage(5);
		b = a;
		b.attack("Shockwave");
	}

	std::cout << "\n=== End of tests ===\n" << std::endl;
	return (0);
}
