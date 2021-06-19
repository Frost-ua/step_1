/*
#pragma once
#include <vector>
#include <iostream>
#include "Fleet.h"

class Field
{
public:
	Field();
	
	//char** getMatrix()const { return matrix; };
private:

	const size_t rows = 10, cols = 10;
	//vector<vector<T> > a(n, vector<T>(m, значение)); // два размера
	//vector<vector<char>> matrix (rows, vector<char>(cols, ' '));
	
	//char** matrix = new char* [rows];
	char mtrx[10][10]{};
	Fleet enemy_fleet;
	
	friend class Map;
};

inline Field::Field()
{
	
	
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new char[cols];
	}


	for (size_t i = 0; i < rows; i++)
	{	

		

		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = ' ';
			
		}
		

	}
}








*/
