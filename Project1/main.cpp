#include<iostream>
using namespace std;
//—оздать класс дл€ работы с матрицами.
//ѕредусмотреть, как минимум, функции дл€ сложени€ матриц, умножени€ матриц, транспонировани€ матриц, присваивани€ матриц друг другу(конструктор копировани€), установка и получение произвольного элемента матрицы(доступ через индексы).
template <class T>
class Matrix
{
	T** ptr;
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
			ptr[i] = new T[st]();
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
			for (int i = 0; i < str; i++) {
				delete[] ptr[i];
			}
			delete[] ptr;

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
		return *this;
	}

	T getEl(int i, int j) const {
		return ptr[i][j];
	}
	void setEl(int i, int j, T value) {
		ptr[i][j] = value;
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
	Matrix<int> obj1(2, 2);
	obj1.Input();
	obj1.Print();

}