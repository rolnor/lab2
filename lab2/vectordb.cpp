#include <Header.h>
#include <vectordb.h>


int main()
{
	vector<string> v;
	char choise;
	

	while (true)
	{
		cin.clear();
		fflush(stdin);

		cout << "MENU:" << endl;
		cout << "1. initialise database" << endl;
		cout << "2. insert" << endl;
		cout << "3. search" << endl;
		cout << "4. delete" << endl;
		cout << "5. print" << endl;
		cout << "6. quit" << endl;
						
		cin >> choise;
		 
		if (choise == '6')
			break;

		switch (choise)
		{
			case '1':
				initialise_database(v);
				break;
			case '2':
				insert_vector(v);
				break;
			case '3':
				search_vector(v);
				break;
			case '4':
				delete_vector(v);
				break;
			case '5':
				print_vector(v);
				break;
			default:
				break;
		}
	}
	return 0;
}

void initialise_database(vector<string>& v)
{
	char areyousure;
	
	cout << "Remove all names. Are you sure? [y/n] ";
	cin >> areyousure;
	if(areyousure == 'y')
		v.clear();
}

void print_vector(vector<string>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}

void insert_vector(vector<string>& v)
{
	string name;
	cout << "Press q or Q to quit" << endl;
	while (true)
	{
		cout << "Enter name: ";
		cin >> name;
		if (name == "q" || name == "Q")
		{
			break;
		}
		else
		{
			v.push_back(name);
		}
	}
}

void delete_vector(vector<string>& v)
{
	string name;

	cout << "Enter name to delete : ";
	cin >> name;

	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
		if (*iterator == name)
		{
			iterator = v.erase(iterator);
		}
}

void search_vector(vector<string>& v)
{
	string name;

	cout << "Enter name to find: ";
	cin >> name;

	for (auto iterator = v.begin(); iterator != v.end(); iterator++)
	{
		if ((*iterator).find(name) != string::npos)
		{
			cout << *iterator << endl;
		}
	}
}