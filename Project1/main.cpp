#include<iostream>
using namespace std;
//������� ����� ��� ������ � ���������.
//�������������, ��� �������, ������� ��� �������� ������, ��������� ������, ���������������� ������, ������������ ������ ���� �����(����������� �����������), ��������� � ��������� ������������� �������� �������(������ ����� �������).
template <class T>
class Matrix
{
	T ptr;
	int str; // ������
	int st; //�������
public: 
	// ����������� �����������
	// ��������� � ��������� ������������� �������� �������(������ ����� �������).
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