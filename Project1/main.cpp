#include<iostream>
using namespace std;
//—оздать класс дл€ работы с матрицами.
//ѕредусмотреть, как минимум, функции дл€ сложени€ матриц, умножени€ матриц, транспонировани€ матриц, присваивани€ матриц друг другу(конструктор копировани€), установка и получение произвольного элемента матрицы(доступ через индексы).
template <class T>
class Matrix
{
	T ptr;
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
		ptr = new T* [str];

		for (int i = 0; i < str; i++)
		{
			ptr[i] = new int[st] {0};
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
	~Matrix()
	{
		for (int i = 0; i < str; i++)
		{
			delete[]ptr[i];
		}
		delete[] ptr;
		cout << "Destructor\n";
	}
	
	Matrix(const Matrix<T>& other);

	Matrix<T>& operator=(const Matrix<T>& other) {
		if (this != &other) {
			for (int i = 0; i < rows; i++) {
				delete[] ptr[i];
			}
			delete[] ptr;

			rows = other.rows;
			cols = other.cols;
			ptr = new T * [rows];
			for (int i = 0; i < rows; i++) {
				ptr[i] = new T[cols];
				for (int j = 0; j < cols; j++) {
					ptr[i][j] = other.ptr[i][j];
				}
			}
		}
		return *this;
	}
};

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) {
	str = other.str;
	st = other.st;
	ptr = new T * [str];
	for (int i = 0; i < str; i++) {
		ptr[i] = new T[st];
		for (int j = 0; j < st; j++) {
			ptr[i][j] = other.ptr[i][j];
		}
	}
}

int main()
{
	

}