#include<iostream>
using namespace std;
//—оздать класс дл€ работы с матрицами.
//ѕредусмотреть, как минимум, функции дл€ сложени€ матриц, умножени€ матриц, транспонировани€ матриц, присваивани€ матриц друг другу(конструктор копировани€), установка и получение произвольного элемента матрицы(доступ через индексы).

class Matrix
{
	int** ptr;
	int str; // строки
	int st; //столбцы
public: 
	// конструктор копировани€
	// установка и получение произвольного элемента матрицы(доступ через индексы).

	Matrix()
	{
		ptr = nullptr;
		str = st = 0;
	}
	Matrix(int _str, int _st)
	{
		str = _str;
		st = _st;
		ptr = new int* [str];

		for (int i = 0; i < str; i++)
		{
			ptr[i] = new int[st] {0};
		}

	}
	Matrix(const Matrix& obj) 
	{
		str = obj.str;
		st = obj.st;
		ptr = new int* [str];
		for (int i = 0; i < str; i++)
		{
			ptr[i] = new int[st];
			for (int j = 0; j < st; j++)
			{
				ptr[i][j] = obj.ptr[i][j];
			}
		}
	}
	void Input()
	{
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < st; j++)
			{
				ptr[i][j] = rand() % 10;
			}
		}
	}
	void Print()const
	{
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < st; j++)
			{
				cout << ptr[i][j]<<"\t";
			}
			cout << endl << endl;
		}
	}
	void SetElement(int row, int col, int value)
	{
		if (row >= str || col >= st)
		{
			cout << "Index out of bounds" << endl;
			return;
		}
		ptr[row][col] = value;
	}
	int GetElement(int row, int col)const
	{
		if (row >= str || col >= st)
		{
			cout << "Index out of bounds" << endl;
			return -999999;
		}

		return ptr[row][col];
	}
	Matrix AddMatrix(Matrix& obj)const
	{
		if (str != obj.str || st != obj.st)
		{
			cout << "Matrix sizes are different" << endl;
			return Matrix();
		}
		Matrix temp(str, st);

		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < st; j++)
			{
				temp.ptr[i][j] = ptr[i][j] + obj.ptr[i][j];
			}
		}

		return temp;
	}
	Matrix MultiplyMatrix(Matrix& obj)const
	{
		if (st != obj.str)
		{
			cout << "First matrix column count must be equal to second matrix row count" << endl;
			return Matrix();
		}

		Matrix temp(str, obj.st);

		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < obj.st; j++)
			{
				for (int k = 0; k < obj.str; k++)
				{
					temp.ptr[i][j] += ptr[i][k] * obj.ptr[k][j];
				}
			}
		}

		return temp;
	}
	Matrix TransposeMatrix()const
	{
		Matrix temp(st, str);

		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < st; j++)
			{
				temp.ptr[j][i] = ptr[i][j];
			}
		}

		return temp;
	}
	~Matrix()
	{
		for (int i = 0; i < str; i++)
		{
			delete[]ptr[i];
		}
		delete[] ptr;
		cout << "Destructor\n";
	}

};

int main()
{
	
	Matrix obj1(3, 2);
	obj1.Input();
	obj1.Print();

	cout << "\n";

	Matrix obj2(2, 5);
	obj2.Input();
	obj2.Print();

	cout << "=====Copy=====\n";
	Matrix obj3 = obj1;
	obj3.Print();

	cout << "=====Set Element=====\n";
	cout << "2,0 element: " << obj3.GetElement(2, 0) << endl;
	obj3.SetElement(2, 0, 999);
	obj3.Print();
	cout << "2,0 element: " << obj3.GetElement(2, 0) << endl;

	cout << "=====Add Matrix=====\n";
	Matrix obj4 = obj1.AddMatrix(obj3);
	obj4.Print();
	
	cout << "=====Multiply Matrix=====\n";
	Matrix obj5 = obj1.MultiplyMatrix(obj2);
	obj5.Print();

	cout << "=====Transpose Matrix=====\n";
	Matrix obj6 = obj1.TransposeMatrix();
	obj6.Print();
}