#include "super_entry.h"

// Colton Vitkoczy
// cs163-009 Karla Fant

// The purpose of this file is to store the node struct and table
// class for the hash table of hero logs. It contains member functions to 
// insert, retrieve, work with a hash key, and diplay all 


struct node
{
	hero_log entry;
	node * next;
};

class table
{
	public:
		table(int size=5);
		~table();
		int remove(node * & head);
		int insert(char * key_value, hero_log & to_add);
		int retrieve(char * search, node * & searchptr, node * sourceptr);
		int display(node * name);
		int display(char * search);	
		int display_all();
		int load(const char filename[]);
		int remove_name(char * search);
	private:
		int hash_function(char*key);
		node ** hash_table;
		int hash_table_size;
};
