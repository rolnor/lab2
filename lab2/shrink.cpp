#include <Header.h>


int shrink_main()
{
	int inputarray3[] = { 5, 5, 7, 6, 2, 2, 11, 11, 5, 4 };
	int inputarray[] = { 5, 5, 7, 6, 2, 2, 11, 11, 5 };

	int asize = sizeof(inputarray) / sizeof(inputarray[0]);
	shrink_array(inputarray, asize);
	for (int i = 0; i < asize; i++)
	{
		cout << inputarray[i];
		if(i != asize-1)
			cout << ',';
	}
	return 0;

}

void shrink_array(int i_array[], int asize)
{
	int zeroes = 0;
	int position = 0;
	for (int i = 0; i < asize; i+=2)
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

	for (int i = asize-1; zeroes != 0; i--)
	{
		i_array[i] = 0;
		zeroes--;
	}
}