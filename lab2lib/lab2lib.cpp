#include <lab2lib.h>

//---Task 1 sortcheck---------------------------------------------------------------
bool is_sorted(int i_array[], int asize)
{
	for (int i = 0; i < asize && i + 1 != asize; i++)
	{
		if (i_array[i] > i_array[i + 1])
			return false;
	}
	return true;
}
//--Task 2 palindromechecker----------------------------------------------------------------
bool is_palindrome(char c_array[])
{
	int check_wordlen = 0;
	bool check_pal = true;
	int read_last;

	// check array for initilised valid chars
	for (int i = 0; i < charsize; i++)
	{
		if (c_array[i] < 123 && c_array[i] > 96)
			check_wordlen++;
		else
			break;
	}
	
	// calculate array size for valid chars
	read_last = check_wordlen - 1;

	// traverse and check for palindrome
	for (int i = 0; i < check_wordlen; i++)
	{
		read_last -= i;
		if (i > read_last)
			break;
		else if (c_array[i] != c_array[read_last])
			check_pal = false;

	}

	return check_pal;
}
//---Task 3: Print 2d array---------------------------------------------------------------
void array_rows_cols(int** p_matrix, int columns, int rows)
{
	int colsum[2] = { 0,0 };
	int* rowsum = new int[columns];

	for (int i = 0; i < columns; i++)
	{
		rowsum[i] = 0;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "\t" << p_matrix[i][j];
			colsum[0] += p_matrix[i][j];
			rowsum[j] += p_matrix[i][j];
		}
		cout << "\t" << colsum[0] << endl;
		colsum[1] += colsum[0];
		colsum[0] = 0;
	}

	for (int i = 0; i < columns; i++)
	{
		cout << "\t" << rowsum[i];
	}

	cout << "\t" << colsum[1] << endl;
	delete[] rowsum;
}
//---Task 4: Swap sort (pass-by-reference)---------------------------------------------------------------
void swap_sort(int& a, int& b, int& c, bool* order)
{
	int temp;

	if (*order == 1)
	{
		if (!(a <= b && b <= c))
		{
			if (a > b)
			{
				temp = b;
				b = a;
				a = temp;
			}
			if (b > c)
			{
				temp = c;
				c = b;
				b = temp;
			}
			swap_sort(a, b, c, order);
		}

	}
	else
	{
		if (!(a >= b && b >= c))
		{
			if (a < b)
			{
				temp = b;
				b = a;
				a = temp;
			}
			if (b < c)
			{
				temp = c;
				c = b;
				b = temp;
			}
			swap_sort(a, b, c, order);
		}
	}
}
//---Task 5: Shrink ---------------------------------------------------------------
void shrink_array(int i_array[], int asize)
{
	int zeroes = 0;
	int position = 0;
	for (int i = 0; i < asize; i += 2)
	{
		if (i == asize - 1)
			i_array[position] = i_array[i];
		else
		{
			i_array[position] = i_array[i] + i_array[i + 1];
			zeroes += 1;
		}
		position += 1;
	}

	for (int i = asize - 1; zeroes != 0; i--)
	{
		i_array[i] = 0;
		zeroes--;
	}
}
//---Task 6: Vector database ---------------------------------------------------------------
int vector_menu()
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
	if (areyousure == 'y')
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
			break;
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