#pragma once
#include <iostream>
#include <string>
using namespace std;

class WrongMatrixPrameters
{
public:
	WrongMatrixPrameters(const int& err_row, const int& err_col)
		:err_row(err_row), err_col(err_col)
	{
	}

	int get_err_row() const
	{
		return err_row;
	}
	int get_err_col() const
	{
		return err_col;
	}


	void get_err_message() const
	{
		if (err_row <= 0)
		{
			cout << "Incorrect value of rows (" << get_err_row() << "). Must be bigger than 0.\n\n";
		}
		if (err_col <= 0)
		{
			cout << "Incorrect value of columns (" << get_err_col() << "). Must be bigger than 0.\n\n";
		}
	}

private:
	int err_row;
	int err_col;
};

template<typename T>
class Matrix
{
public:
	Matrix(const int& rows = 2, const int& cols = 2, const T& value = T());   // T() - default for type T

	void fill(const T& value = T());
	void print()const;
	T operator ()(int r, int c)const;   // For const obj
	T& operator ()(int r, int c);
	Matrix(const Matrix<T>& other);
	void operator = (const Matrix& other);                 // overloading operator =
 	Matrix operator + (const Matrix& other);
	Matrix operator + (const T& value);
	bool operator == (const Matrix& other)const;
	bool operator != (const Matrix& other)const;
	

 	T operator += (T value);
	T GetMaxElement()const;
	T GetMinElement()const;
	bool SearchValue(const T& value)const;
	T GetSumElements()const;
	void addRow(const T& value = T());
	void addCol(const T& value = T());

	
	void CopyTmpMatrix(T** tmp);
	

	const int GetRows()const { return rows; };
	const int GetCols()const { return cols; };
	static size_t GetCountObjMatrix() { return count; };

	template<typename T>
	friend istream& operator >> (istream& in, Matrix<T>& m);

	template<typename T>
	friend ostream& operator << (ostream& in, Matrix<T>& m);

	~Matrix();
private:
	bool ValidIndices(int r, int c);
	static size_t count;
	T** matrix;
	int rows, cols;
};

template<typename T>
istream& operator >> (istream& in, Matrix<T>& m)
{
	for (size_t i = 0; i < m.GetRows(); i++)
	{
		for (size_t j = 0; j < m.GetCols(); j++)
		{
			in >> m.matrix[i][j]; // friend of class Matrix
			//in >> m(i, j);      // use operator ()
		}
	}
	return in;
}

template<typename T>
ostream& operator << (ostream& out, Matrix<T>& m)
{
	for (size_t i = 0; i < m.GetRows(); i++)
	{
		for (size_t j = 0; j < m.GetCols(); j++)
		{
			out << m.matrix[i][j] << "\t"; // friend of class Matrix
			//in >> m(i, j);      // use operator ()
		}
		out << endl << endl;
	}
	return out;
}

template<typename T>
size_t Matrix<T>::count = 0;

template<typename T>
Matrix<T> operator+(const T& value, Matrix<T>& other)
{
	return other + value;
}

template<typename T>
inline Matrix<T>::Matrix(const int& rows, const int& cols, const T& value)
{

	if (rows <= 0)
	{
		throw WrongMatrixPrameters(rows, cols);
	}
	if (cols <= 0)
	{
		throw WrongMatrixPrameters(rows, cols);
	}
	this->rows = rows;
	this->cols = cols;


	matrix = new T * [rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new T[cols];
	}
	fill(value);
	++count;
}

template<typename T>
inline void Matrix<T>::fill(const T& value)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = value;
		}
	}
}

template<typename T>
inline void Matrix<T>::print() const
{
	cout << "\n\n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>
inline T Matrix<T>::operator()(int r, int c) const
{
	if (ValidIndices(r, c))
	{
		return matrix[r][c];
	}
	else
	{
		throw out_of_range("Operator () const: Incorrect index of row or column!\n\n");
	}
}

template<typename T>
inline T& Matrix<T>::operator()(int r, int c)
{
	if (ValidIndices(r, c))
	{
		return matrix[r][c];
	}
	else
	{
		throw out_of_range("\nOperator (): Incorrect index of row or column!\n\n");
	}
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& other)
{
	this->rows = other.rows;
	this->cols = other.cols;
	matrix = new T * [other.rows];
	for (size_t i = 0; i < other.rows; i++)
	{
		matrix[i] = new T[other.cols];
	}

	for (size_t i = 0; i < other.rows; i++)
	{
		for (size_t j = 0; j < other.cols; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

template<typename T>
inline void Matrix<T>::operator=(const Matrix& other)
{
	if (matrix != other.matrix && cols == other.cols && rows == other.rows)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = other.matrix[i][j];
	}

}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const Matrix& other)
{
		
	if (rows == other.rows && cols == other.cols)
	{
		Matrix tmp(rows, cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				tmp.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
			}
		}
		return tmp;
	}
	else
	{
		throw logic_error("Matrices have the different size!\n");
	}

}

template<typename T>
inline Matrix<T> Matrix<T>::operator+(const T& value)
{
	Matrix tmp(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			tmp.matrix[i][j] = matrix[i][j] + value;
		}
	}
	return tmp;
}

template<typename T>
inline bool Matrix<T>::operator==(const Matrix& other)const
{
	if (rows != other.rows || cols != other.cols)
	{
		return false;
	}
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] != other.matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

template<typename T>
inline bool Matrix<T>::operator!=(const Matrix& other)const
{
	return !(*this == other); 
}



template<typename T>
inline T Matrix<T>::operator+=(T value)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] += value;
		}
	}
	return **matrix;
}

template<typename T>
inline T Matrix<T>::GetMaxElement() const
{
	T max = matrix[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 1; j < cols; j++)
		{
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
	}
	return max;
}

template<typename T>
inline T Matrix<T>::GetMinElement() const
{
	T min = matrix[0][0];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 1; j < cols; j++)
		{
			if (matrix[i][j] < min)
				min = matrix[i][j];
		}
	}
	return min;
}

template<typename T>
inline bool Matrix<T>::SearchValue(const T& value) const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] == value)
			{
				return true;
			}
		}
	}
	return false;
}

template<typename T>
inline T Matrix<T>::GetSumElements() const
{
	T sum = T();
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

template<typename T>
inline void Matrix<T>::addRow(const T& value)
{
	T** tmp = new T * [rows + 1];
	for (size_t i = 0; i < rows + 1; i++)
	{
		tmp[i] = new T[cols];
	}

	/*for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			tmp[i][j] = matrix[i][j];
		}
	}*/

	CopyTmpMatrix(tmp);

	for (size_t i = rows, j = 0; j < cols; j++)
	{
		tmp[i][j] = value;
	}
	
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	this->matrix = tmp;
	++this->rows;

}

template<typename T>
inline void Matrix<T>::addCol(const T& value)
{
	T** tmp = new T * [rows];

	for (size_t i = 0; i < rows; i++)
	{
		tmp[i] = new T[cols + 1];
	}
	
	/*for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			tmp[i][j] = matrix[i][j];
		}
	}*/
	CopyTmpMatrix(tmp);
	for (size_t i = 0, j = cols; i < rows; i++)
	{
		tmp[i][j] = value;
	}
	for (size_t i = 0; i < cols; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = tmp;
	++cols;
}

template<typename T>
inline void Matrix<T>::CopyTmpMatrix(T** tmp)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)			{
			tmp[i][j] = matrix[i][j];
		}
	}
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < this->rows; i++)
	{
		delete[] this->matrix[i];

	}

	delete[] this->matrix;
}

template<typename T>
inline bool Matrix<T>::ValidIndices(int r, int c)
{
	return r < rows&& c < cols;
}




