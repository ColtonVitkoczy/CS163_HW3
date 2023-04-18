#include "super_entry.h"

// The prupose of this file is to build the functions in the super_entry.h file
// allowing input with the dynamically allocated arrays when gathering user input. 


//Constructor for the hero log
hero_log::hero_log()
{
	name = NULL;
	power = NULL;
	species = NULL;
	bio = NULL;	
}

// destructor for the hero log
hero_log::~hero_log()
{
	if (name)
		delete [] name;
	if (power)
		delete [] power;
	if (species)
		delete [] species;
	if (bio)
		delete [] bio;

	name = power = species = bio = NULL;
}

// function to help deal with dynamically allocated arrays
int hero_log::array_helper(char array[], char * &ptr)
{
	ptr = new char [strlen(array)+1];
	strcpy(ptr, array);
	return 1;
}

// function that creates an entry for the hero log
int hero_log::create_entry(char * a_name, char * a_power, char * a_species, char * a_bio)
{
	array_helper(a_name, name);
	array_helper(a_power, power);
	array_helper(a_species, species);
	array_helper(a_bio, bio);
	return 1;
}

// copys an entry into the hero log
int hero_log::copy_entry(hero_log & to_add)
{	
	array_helper(to_add.name, name);
	array_helper(to_add.power, power);
	array_helper(to_add.species, species);
	array_helper(to_add.bio, bio);
	return 1;
}
// displays the data
int hero_log::display()
{
	std::cout << name << std::endl;
        std::cout << power << std::endl;
        std::cout << species << std::endl;
        std::cout << bio << std::endl;
	return 1;
}
// Checks to see if the names matching 
int hero_log::match_name(char * search)
{
	return strcmp(search, name);
}




















