#include <Header.h>


int print2d_main(void)
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
	return 0;
 }

void array_rows_cols(int** p_matrix, int columns, int rows)
{
	int colsum[2] = { 0,0 };
	int *rowsum = new int[columns];

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