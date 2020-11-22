#include <lab2lib.h>


int main()
{
	char choise;

	while (true)
	{
		cin.clear();
		fflush(stdin);

		cout << "MENU:" << endl;
		cout << "1. SortCheck" << endl;
		cout << "2. Palindrome checker" << endl;
		cout << "3. Print 2D array" << endl;
		cout << "4. Swap sort" << endl;
		cout << "5. Shrink" << endl;
		cout << "6. Vector database" << endl;
		cout << "7. Quit" << endl;

		cin >> choise;

		if (choise == '7')
			break;

		switch (choise)
		{
			case '1':
			{
				bool check_sort = true;
				int numbers[arraysize];
				cout << "Enter " << arraysize << " numbers: ";
				for (int i = 0; i < arraysize; i++)
				{
					cin >> numbers[i];
				}
				check_sort = is_sorted(numbers, sizeof(numbers) / sizeof(numbers[0]));
				cout << "Answer is: " << check_sort << endl;
				break;
			}
			case '2':
			{
				bool check_pali = true;
				char chararray[charsize];
				cout << "Enter word: ";
				cin >> chararray;

				check_pali = is_palindrome(chararray);
				cout << "Status: " << check_pali << endl;
				break;
			}
			case '3':
			{				
				int rows = 0, columns = 0;
				int** p_matrix;
				cout << "Rows: ";
				cin >> rows;
				cout << "Columns: ";
				cin >> columns;

				p_matrix = new int* [rows];
				for (int i = 0; i < rows; i++)
				{
					p_matrix[i] = new int[columns];
				}

				srand(time(NULL));
				for (int i = 0; i < rows; i++)
				{
					for (int j = 0; j < columns; j++)
					{
						p_matrix[i][j] = rand() % 10;
					}
				}

				array_rows_cols(p_matrix, columns, rows);

				delete[] p_matrix;
				break;
			}
			case '4':
			{
				int a = 1;
				int b, c;
				char c_order = 'a';
				bool order;

				while (true)
				{
					cout << "Enter a (0 to quit): ";
					cin >> a;
					if (a == 0)
						break;
					cout << "Enter b: ";
					cin >> b;
					cout << "Enter c: ";
					cin >> c;
					cout << "ascending or descending [a/d]: ";
					cin >> c_order;

					if (c_order == 'a')
						order = 1;
					else order = 0;

					swap_sort(a, b, c, &order);
					cout << "Result: " << a << ',' << b << ',' << c << endl;
				}
				cout << "Bye bye!" << endl;
				break;
			}
			case '5':
			{
				int inputarray[] = { 5, 5, 7, 6, 2, 2, 11, 11, 5, 4 };

				int asize = sizeof(inputarray) / sizeof(inputarray[0]);
				shrink_array(inputarray, asize);
				for (int i = 0; i < asize; i++)
				{
					cout << inputarray[i];
					if (i != asize - 1)
						cout << ',';
				}
				cout << endl;
				break;
			}
			case '6':
			{
				vector_menu();
				break;
			}
			default:
			{
				cout << "Sorry, there is no such task!" << endl;
				break;
			}
		}
	}
	return 0;   
}
