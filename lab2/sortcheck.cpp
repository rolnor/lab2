#include <Header.h>;

int sortcheck_main()
{
	bool check_sort = true;
	int numbers[arraysize];
	cout << "Enter " << arraysize << " numbers: ";
	for (int i = 0; i < arraysize; i++)
	{
		cin >> numbers[i];
	}
	check_sort = is_sorted(numbers, sizeof(numbers)/sizeof(numbers[0]));
	cout << "Answer is: " << check_sort << endl;
	return 0;
}


bool is_sorted(int i_array[],int asize)
{
	for (int i = 0; i < asize && i + 1 != asize; i++)
	{
		if (i_array[i] > i_array[i + 1])
			return false;
	}
	return true;
}