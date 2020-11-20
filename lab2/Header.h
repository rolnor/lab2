#include <iostream>
#include <cstdlib> 
#include <time.h>  


const int arraysize = 5;
const int charsize = 20;

bool is_sorted(int i_array[], int asize);
bool is_palindrome(char c_array[]);

void array_rows_cols(int** p_matrix, int columns, int rows);
void swap_sort(int& a, int& b, int& c, bool* order);

void shrink_array(int i_array[], int asize);


using namespace std;