#include "hero_hash.h"

// The purpose of this file is to build the hash table functions given in the hero_hash.h file

// Constructor
table::table(int size)
{
	hash_table = new node *[size];
	for (int i = 0; i < size; ++i)
		hash_table[i] = NULL;
	hash_table_size = size;
}
//destrocter
table::~table()
{
	for (int i = 0; i < hash_table_size; ++i)
		delete(hash_table[i]);
	delete [] hash_table;
	hash_table = NULL;	
}
// Function that can be called on to delete nodes recursively 
int table::remove(node * & head)
{
	if (!head) return 0;
	remove(head->next);

	delete head;
	head = NULL;
	return 1;
}

// Function to insert into the hash table 
int table::insert(char * key_value, hero_log & to_add)
{
	int key = hash_function(key_value); // grabs the index

	node * temp = new node; // creates a temp node
	temp->entry.copy_entry(to_add); // stores the info in temp

	if(!hash_table[key])
	{
		hash_table[key] = temp; 
		hash_table[key]->next = NULL;
		return 0;
	}
	temp->next = hash_table[key];
	hash_table[key] = temp;
	return 1;
}

// Hash functoin that uses a formula to create a key
int table::hash_function(char * key_value)
{
	int key = 0;
	int length = strlen(key_value);

	for(int i = 0; i < length; ++i)
		key += key_value[i]*key_value[i]-key_value[i]+3;
	return key % hash_table_size;
}

// function that loads in information from a external data file
int table::load(const char filename[])
{
/*
	hero_log to_add;//Used to copy information into the hash table
	table my_list;
	
	char name[50]; 
	char power[75]; 
	char species[75]; 
	char bio[500];
*/
	temp info;
	hero_log to_add;

	std::ifstream file_in;

	file_in.open(filename);
	if (file_in.is_open())
	{
		file_in.get(info.name, 50, '|'); 
		file_in.ignore(50, '|');
		
		while (!file_in.eof())
		{
			file_in.get(info.power, 75, '|'); 
			file_in.ignore(100, '|');
			
			file_in.get(info.species, 75, '|'); 
			file_in.ignore(100, '|');
			
			file_in.get(info.bio, 500, '\n'); 
			file_in.ignore(500, '\n');
		    
			to_add.create_entry(info.name, info.power, info.species, info.bio);
			insert(info.name, to_add);
			
			file_in.get(info.name, 50, '|'); 
			file_in.ignore(100, '|');
		}
		file_in.close();
	}
	return 1;
}

// function that retrieves from the hash table
int table::retrieve(char * search, node * & searchptr, node * sourceptr)
{
	if(!sourceptr)
	{
		searchptr = NULL;
		return 0;
	}
	
	//if(!strcmp(search, searchptr->entry.name))
	if (sourceptr->entry.match_name(search))
	{
		searchptr = new node;
		searchptr->entry.copy_entry(sourceptr->entry);
		retrieve(search, searchptr->next, sourceptr->next);
	}
	else
		retrieve(search, searchptr, sourceptr->next);
	return 1;
}

// recursive function to display from the hash table
int table::display(node * head)
{
	if (!head) return 0;
	
	head->entry.display();
	display(head->next);
	return 1;
}

// uses a temp pointer to retrieve the infromation and then calls the recursivedisplay function.
int table::display(char * search)
{
	node * searchptr = NULL;
	int key = hash_function(search);
	
	retrieve(search, searchptr, hash_table[key]);
	if (!searchptr) return 0;
	
	display(searchptr);
	remove(searchptr);
	return 1;
}
// Displays all information
int table::display_all()
{
	hero_log entry;
	for (int i = 0; i < hash_table_size; ++i)
		display(hash_table[i]);
	return 1;

}

int table::remove_name(char * search)
{
	int key = hash_function(search);

	remove(hash_table[key]);

	return 1;
}



















