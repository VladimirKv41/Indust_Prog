#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ����� �������
void matrix_output(int** matrix, int row_numb, int column_numb) {

	for (int i = 0; i < row_numb; i++)
	{
		for (int j = 0; j < column_numb; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
// ���������� ����������
void submatrix_fill(int** submatrix, int** matrix_reduced, int new_dimension, int shift_row, int shift_column) {
	for (int i = 0; i < new_dimension / 2; i++)
	{
		for (int j = 0; j < new_dimension / 2; j++)
			submatrix[i][j] = matrix_reduced[i + shift_row][j + shift_column];
	}
}

void main()
{
	srand(time(NULL));
	int row_numb_1, column_numb_1, row_numb_2, column_numb_2, new_dimension = 2;
	bool fill_method;
	system("chcp 1251");
	cout << "��� ������������ ���������" << endl <<
		"�������� ������������ ������ ������� ���������\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////���� �������� ������� �������������////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> row_numb_1 >> column_numb_1;
	} while (row_numb_1 <= 0 || column_numb_1 <= 0);
	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> row_numb_2 >> column_numb_2;
	} while (row_numb_2 <= 0 || column_numb_2 <= 0);

	int** matrix_1 = new int* [row_numb_1];
	for (int i = 0; i < row_numb_1; i++)
		matrix_1[i] = new int[column_numb_1];
	int** matrix_2 = new int* [row_numb_2];
	for (int i = 0; i < row_numb_2; i++)
		matrix_2[i] = new int[column_numb_2];

	///////////////////////////////////////////////////////////////////////////////
	////////////////����� ������� ���������� � ���������� ������///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cin.clear();
		cout << "�������� ������ ���������� ������\n" <<
			"1 - ������� \n0 - ��������� �������\n";
		cin >> fill_method;
	} while (!cin);
	for (int i = 0; i < row_numb_1; i++)
		for (int j = 0; j < column_numb_1; j++)
			if(fill_method) cin >> matrix_1[i][j];
			else matrix_1[i][j] = rand() % 10;
	for (int i = 0; i < row_numb_2; i++)
		for (int j = 0; j < column_numb_2; j++)
			if (fill_method) cin >> matrix_2[i][j];
			else matrix_2[i][j] = rand() % 10;
	cout << "\n������� " << 1 << "\n\n";
	matrix_output(matrix_1, row_numb_1, column_numb_1);
	cout << "\n������� " << 2 << "\n\n";
	matrix_output(matrix_2, row_numb_2, column_numb_2);


	///////////////////////////////////////////////////////////////////////////////
	/////////////////���������� ������ � ���������� �������////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (new_dimension < row_numb_1 || new_dimension < row_numb_2 || new_dimension < column_numb_1 || new_dimension < column_numb_2)
		new_dimension *= 2;
	int** matrix_1_reduced = new int* [new_dimension];
	for (int i = 0; i < new_dimension; i++)
	{
		matrix_1_reduced[i] = new int[new_dimension];
		for (int j = 0; j < new_dimension; j++) {
			if (i <= row_numb_1 - 1 && j <= column_numb_1 - 1)
				matrix_1_reduced[i][j] = matrix_1[i][j];
			else matrix_1_reduced[i][j] = 0;
		}
	}
	int** matrix_2_reduced = new int* [new_dimension];
	for (int i = 0; i < new_dimension; i++)
	{
		matrix_2_reduced[i] = new int[new_dimension];
		for (int j = 0; j < new_dimension; j++)
			if (i <= row_numb_2 - 1 && j <= column_numb_2 - 1)
				matrix_2_reduced[i][j] = matrix_2[i][j];
			else matrix_2_reduced[i][j] = 0;
	}
	cout << "����������� �������\n";
	cout << "\n������� " << 1 << "\n\n";
	matrix_output(matrix_1_reduced, new_dimension, new_dimension);
	cout << "\n������� " << 2 << "\n\n";
	matrix_output(matrix_2_reduced, new_dimension, new_dimension);

	///////////////////////////////////////////////////////////////////////////////
	///////////////��������� ������ �� ���������� � �� ����������//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int*** list_submatrix = new int** [8];
	for (int i = 0; i < 8; i++)
	{
		list_submatrix[i] = new int* [new_dimension / 2];
		for (int j = 0; j < new_dimension/2; j++)
		{
			list_submatrix[i][j] = new int[new_dimension/2];
		}
	}
	submatrix_fill(list_submatrix[0], matrix_1_reduced, new_dimension, 0, 0);
	submatrix_fill(list_submatrix[1], matrix_1_reduced, new_dimension, 0, new_dimension / 2);
	submatrix_fill(list_submatrix[2], matrix_1_reduced, new_dimension, new_dimension / 2, 0);
	submatrix_fill(list_submatrix[3], matrix_1_reduced, new_dimension, new_dimension / 2, new_dimension / 2);
	submatrix_fill(list_submatrix[4], matrix_2_reduced, new_dimension, 0, 0);
	submatrix_fill(list_submatrix[5], matrix_2_reduced, new_dimension, 0, new_dimension / 2);
	submatrix_fill(list_submatrix[6], matrix_2_reduced, new_dimension, new_dimension / 2, 0);
	submatrix_fill(list_submatrix[7], matrix_2_reduced, new_dimension, new_dimension / 2, new_dimension / 2);
	

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////�������� ������������� ������//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int*** list_intermed_matrix = new int** [7];
	for (int i = 0; i < 7; i++)
	{
		list_intermed_matrix[i] = new int* [new_dimension / 2];
		for (int j = 0; j < new_dimension / 2; j++)
		{
			list_intermed_matrix[i][j] = new int[new_dimension / 2];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////////���������� �������� ������������� ������///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < new_dimension / 2; i++)
	{
		for (int j = 0; j < new_dimension / 2; j++)
		{
			list_intermed_matrix[0][i][j] = 0;
			for (int z = 0; z < new_dimension / 2; z++)
			{
				list_intermed_matrix[0][i][j] += (list_submatrix[0][i][z] + list_submatrix[3][i][z]) * (list_submatrix[4][z][j] + list_submatrix[7][z][j]);
			}

			list_intermed_matrix[1][i][j] = 0;
			for (int z = 0; z < new_dimension / 2; z++)
			{
				list_intermed_matrix[1][i][j] += (list_submatrix[2][i][z] + list_submatrix[3][i][z]) * list_submatrix[4][z][j];
			}

			list_intermed_matrix[2][i][j] = 0;
			for (int z = 0; z < new_dimension / 2; z++)
			{
				list_intermed_matrix[2][i][j] += list_submatrix[0][i][z] * (list_submatrix[5][z][j] - list_submatrix[7][z][j]);
			}

			list_intermed_matrix[3][i][j] = 0;
			for (int z = 0; z < new_dimension / 2; z++)
			{
				list_intermed_matrix[3][i][j] += list_submatrix[3][i][z] * (list_submatrix[6][z][j] - list_submatrix[4][z][j]);
			}

			list_intermed_matrix[4][i][j] = 0;
			for (int z = 0; z < new_dimension / 2; z++)
			{
				list_intermed_matrix[4][i][j] += (list_submatrix[0][i][z] + list_submatrix[1][i][z]) * list_submatrix[7][z][j];
			}

			list_intermed_matrix[5][i][j] = 0;
			for (int z = 0; z < new_dimension / 2; z++)
			{
				list_intermed_matrix[5][i][j] += (list_submatrix[2][i][z] - list_submatrix[0][i][z]) * (list_submatrix[4][z][j] + list_submatrix[5][z][j]);
			}

			list_intermed_matrix[6][i][j] = 0;
			for (int z = 0; z < new_dimension / 2; z++)
			{
				list_intermed_matrix[6][i][j] += (list_submatrix[1][i][z] - list_submatrix[3][i][z]) * (list_submatrix[6][z][j] + list_submatrix[7][z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////�������� ��������������� ������/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int*** list_aux_matrix = new int** [4];
	for (int i = 0; i < 4; i++)
	{
		list_aux_matrix[i] = new int* [new_dimension / 2];
		for (int j = 0; j < new_dimension / 2; j++)
		{
			list_aux_matrix[i][j] = new int[new_dimension / 2];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////������� �������� ��������������� ������ �� �������������///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < new_dimension / 2; i++)
	{
		for (int j = 0; j < new_dimension / 2; j++)
		{
			list_aux_matrix[0][i][j] = list_intermed_matrix[0][i][j] + list_intermed_matrix[3][i][j] - list_intermed_matrix[4][i][j] + list_intermed_matrix[6][i][j];
			list_aux_matrix[1][i][j] = list_intermed_matrix[2][i][j] + list_intermed_matrix[4][i][j];
			list_aux_matrix[2][i][j] = list_intermed_matrix[1][i][j] + list_intermed_matrix[3][i][j];
			list_aux_matrix[3][i][j] = list_intermed_matrix[0][i][j] - list_intermed_matrix[1][i][j] + list_intermed_matrix[2][i][j] + list_intermed_matrix[5][i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////�������� �������������� �������/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** result_matrix = new int* [new_dimension];
	for (int i = 0; i < new_dimension; i++)
	{
		result_matrix[i] = new int[new_dimension];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////��������� ���������� �� ��������������� ������ � ��������������/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < new_dimension / 2; i++)
	{
		for (int j = 0; j < new_dimension / 2; j++)
		{
			result_matrix[i][j] = list_aux_matrix[0][i][j];
			result_matrix[i][j + new_dimension / 2] = list_aux_matrix[1][i][j];
			result_matrix[i + new_dimension / 2][j] = list_aux_matrix[2][i][j];
			result_matrix[i + new_dimension / 2][j + new_dimension / 2] = list_aux_matrix[3][i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////������������ ������ �������������� �������/////////////////////
	///////////////////////////////////////////////////////////////////////////////
	int x = 0, f = 100, s = 100;
	for (int i = 0; i < new_dimension; i++)
	{
		x = 0;
		for (int j = 0; j < new_dimension; j++)
		{
			if (result_matrix[i][j] != 0)
			{
				x++;
				f = 100;
			}
		}
		if (x == 0 && i < f)
		{
			f = i;
		}
	}
	for (int i = 0; i < new_dimension; i++)
	{
		x = 0;
		for (int j = 0; j < new_dimension; j++)
		{
			if (result_matrix[j][i] != 0)
			{
				x++;
				s = 100;
			}
		}
		if (x == 0 && i < s)
		{
			s = i;
		}
	}
	int** final_result_matrix = new int* [f];
	for (int i = 0; i < f; i++)
	{
		final_result_matrix[i] = new int[s];
		for (int j = 0; j < s; j++)
			final_result_matrix[i][j] = result_matrix[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////����� �������������� �������////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\n�������������� �������\n\n";
	matrix_output(final_result_matrix, f, s);

	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////������� ������������ ������///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < row_numb_1; i++)
		delete[] matrix_1[i];
	for (int i = 0; i < row_numb_2; i++)
		delete[] matrix_2[i];
	for (int i = 0; i < new_dimension; i++)
	{
		delete[] matrix_1_reduced[i];
		delete[] matrix_2_reduced[i];
		delete[] result_matrix[i];
	}
	for (int i = 0; i < f; i++)
		delete[] final_result_matrix[i];
	for (int i = 0; i < new_dimension / 2; i++)
	{
		delete[] list_submatrix[0][i];
		delete[] list_submatrix[1][i];
		delete[] list_submatrix[2][i];
		delete[] list_submatrix[3][i];
		delete[] list_submatrix[4][i];
		delete[] list_submatrix[5][i];
		delete[] list_submatrix[6][i];
		delete[] list_submatrix[7][i];
		delete[] list_aux_matrix[0][i];
		delete[] list_aux_matrix[1][i];
		delete[] list_aux_matrix[2][i];
		delete[] list_aux_matrix[3][i];
		delete[] list_intermed_matrix[0][i];
		delete[] list_intermed_matrix[1][i];
		delete[] list_intermed_matrix[2][i];
		delete[] list_intermed_matrix[3][i];
		delete[] list_intermed_matrix[4][i];
		delete[] list_intermed_matrix[5][i];
		delete[] list_intermed_matrix[6][i];
	}
	delete[] matrix_1, matrix_2, matrix_1_reduced, matrix_2_reduced, result_matrix, final_result_matrix, list_submatrix, list_intermed_matrix, list_aux_matrix;
	delete[] list_submatrix[0], list_submatrix[1], list_submatrix[2], list_submatrix[3], list_submatrix[4], list_submatrix[5], list_submatrix[6], list_submatrix[7], list_aux_matrix[0], list_aux_matrix[1], list_aux_matrix[2], list_aux_matrix[3];
	delete[] list_intermed_matrix[0], list_intermed_matrix[1], list_intermed_matrix[2], list_intermed_matrix[3], list_intermed_matrix[4], list_intermed_matrix[5], list_intermed_matrix[6];
}