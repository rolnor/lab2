#include <Header.h>


int swap_main()
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
	return 0;
}

void swap_sort(int& a, int& b, int& c, bool *order)
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