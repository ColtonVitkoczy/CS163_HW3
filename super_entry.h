#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
// Colton Vitkoczy
// CS163-009 Karla Fant

// The purpose of this efile is to store the class data structure for the hero log
// it contains functions to add an entry, copy, retrieve, and display. The private 
// members are for the super heros name, power, species, bio. 
struct temp
{
	char name[50]; 
	char power[75]; 
	char species[75]; 
	char bio[500];
};

class hero_log
{
	public: 
		hero_log();
		~hero_log();
		int create_entry(char * name, char * power, char * species, char * bio);
		int copy_entry(hero_log & to_add);
		int retrieve(char * name, char * power, char * species, char * bio);
		int retrieve(hero_log & new_entry);
		int display();
		int array_helper(char array[], char * &ptr);
		int match_name(char * search);

	private:
		
		char * name; 
		char * power; 
		char * species; 
		char * bio;
};
