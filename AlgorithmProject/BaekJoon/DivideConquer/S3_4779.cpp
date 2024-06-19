#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string s;
void go(int left, int right)
{
	// base case
	if (left >= right)
	{
		return;
	}

	// conquer
	int block = (right - left + 1) / 3;
	int mid1 = left + block;
	int mid2 = mid1 + block;
	for (int i = mid1; i < mid2; i++)
	{
		s[i] = ' ';
	}

	// divide
	go(left, mid1 - 1);
	go(mid2, right);
}

int main()
{
	int N;
	while (cin >> N)
	{
		int size = pow(3, N);

		// 특정 원소로 resize 할 때는, size가 앞에
		s.resize(size, '-');

		go(0, size - 1);
		for (char& c : s)
		{
			cout << c;
		}
		cout << '\n';
	}

	return 0;
}