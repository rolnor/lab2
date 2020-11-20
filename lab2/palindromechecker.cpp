#include <Header.h>;
using namespace std;

int pali_main()
{
	bool check_pali = true;
	char chararray[charsize];
	cout << "Enter word: ";
	cin >> chararray;

	check_pali = is_palindrome(chararray);
	cout << "Status: " << check_pali << endl;
	return 0;
}

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