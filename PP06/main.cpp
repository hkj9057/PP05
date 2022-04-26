#include <vector>
#include <iostream>

using namespace std;

template<typename T>

int main()
{
	vector<int> a;

	cout << a.size() << endl; // vectorÀÇ size == length

	a.push_back(1);
	a.push_back(4);
	a.push_back(7);
	a.push_back(8);

	cout << a.size() << endl;
	cout << "°ªÀº : " << a[2] << endl;

	return 0;
}