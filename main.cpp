#include "client.h"
using namespace std;

// The purpose of this file is the main function allows the user to call the client function
// in order to test the boundary conditions 

int main()
{
	hero_log to_add;
	table my_list(17);
	int selection = 0; 
	char response = 'Y';

	my_list.load("hero_log.txt");

	
	while(toupper(response) == 'Y')
	{
		cout << "enter the following" << endl;
		cout << "type 1 to display all" << endl;
		cout << "type 2 to add in a new hero" << endl;
		cout << "type 3 to search for a specific hero" << endl;
		cout << "type 4 to remove a specific hero" << endl;
		cout << "type 5 to searchfor  a specific power" << endl;

		cout << "please enter a selection: ";
		cin >> selection;
		cin.ignore(100, '\n');
		
		client_option(selection, my_list, to_add);

		cout << "Again? " ;
		cin >> response;
		cin.ignore(100, '\n');
	}

	return 0;
}

