#include <iostream>
using namespace std;

// return문에 연산을 없애서, 함수 스택을 유지하지 않는 꼬리재귀
int fivo(int n, int prev, int twicePrev)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return prev;
	}

	// 피보나치를 꼬리재귀로 구현하기 위해서는 상향식으로 계산
	return fivo(n - 1, prev + twicePrev, prev);
}

int main()
{
	int n;
	cin >> n;

	cout << fivo(n, 1, 0);
	return 0;
}