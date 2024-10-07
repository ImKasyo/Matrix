#include<iostream>
using namespace std;
//Ñîçäàòü êëàññ äëÿ ðàáîòû ñ ìàòðèöàìè.
//Ïðåäóñìîòðåòü, êàê ìèíèìóì, ôóíêöèè äëÿ ñëîæåíèÿ ìàòðèö, óìíîæåíèÿ ìàòðèö, òðàíñïîíèðîâàíèÿ ìàòðèö, ïðèñâàèâàíèÿ ìàòðèö äðóã äðóãó(êîíñòðóêòîð êîïèðîâàíèÿ), óñòàíîâêà è ïîëó÷åíèå ïðîèçâîëüíîãî ýëåìåíòà ìàòðèöû(äîñòóï ÷åðåç èíäåêñû).
template <class T>
class Matrix
{
	T** ptr;
	int str; // ñòðîêè
	int st; //ñòîëáöû
public: 
	// êîíñòðóêòîð êîïèðîâàíèÿ
	// óñòàíîâêà è ïîëó÷åíèå ïðîèçâîëüíîãî ýëåìåíòà ìàòðèöû(äîñòóï ÷åðåç èíäåêñû).
	Matrix()
	{
		ptr = nullptr;
		str = st = 0;
	}
	Matrix(int _str, int _st) //str - строки, st - столбцы
	{
		str = _str;
		st = _st;
		ptr = new T* [str]; //создается массив указатедей типа *T размера str

		for (int i = 0; i < str; i++)
		{
			ptr[i] = new T[st]();
		}

	}
	void Input() const
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

	Matrix<T> operator+(const Matrix<T>& other) const {
		Matrix<T> result(str, st);
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < st; j++) {
				result.ptr[i][j] = ptr[i][j] + other.ptr[i][j];
			}
		}
		return result;
	}

	Matrix<T> operator*(const Matrix<T>& other) const {
		Matrix<T> result(str, other.st);
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < other.st; j++) {
				result.ptr[i][j] = 0;
				for (int k = 0; k < st; k++) {
					result.ptr[i][j] += ptr[i][k] * other.ptr[k][j];
				}
			}
		}
		return result;
	}

	T GetEl(int i, int j) const {
		return ptr[i][j];
	}
	void SetEl(int i, int j, T value) {
		ptr[i][j] = value;
	}

	Matrix<T> Transpose() const {
		Matrix<T> result(st, str); // Ìåíÿåì ìåñòàìè ñòðîêè è ñòîëáöû
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < st; j++) {
				result.ptr[j][i] = ptr[i][j];
			}
		}
		return result;
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
	const Matrix<int> obj1(2, 2);
	obj1.Input();
	obj1.Print();
	const Matrix<int> obj2(3, 3);
	cout << endl;
	obj2.Input();
	obj2.Print();

	Matrix<int> sum = obj1 + obj2;
	cout << endl;
	sum.Print();

	Matrix<int> multi = obj1 * obj2;
	cout << endl;
	multi.Print();

	Matrix<int> transposed = obj1.Transpose();
	cout << endl;
	transposed.Print();


}
