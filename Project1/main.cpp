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
				ptr[i][j] = rand() % 100;
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
		if (row > str || col > st)
		{
			cout << "Index out of bounds" << endl;
			return;
		}
		ptr[row][col] = value;
	}
	int GetElement(int row, int col)const
	{
		if (row > str || col > st)
		{
			cout << "Index out of bounds" << endl;
			return -1;
		}

		return ptr[row][col];
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
	Matrix obj1(3, 5);
	obj1.Input();
	obj1.Print();

	Matrix obj2 = obj1;
	obj2.Print();
	cout << "1,3 element: " << obj2.GetElement(1, 3) << endl;
	obj2.SetElement(1, 3, 999);
	obj2.Print();
	cout << "1,3 element: " << obj2.GetElement(1, 3) << endl;
}