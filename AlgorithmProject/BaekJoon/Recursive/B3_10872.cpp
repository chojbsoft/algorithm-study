#include <iostream>
using namespace std;

int recursive(int n, int acc)
{
	// 0!은 1로 처리
	// 처리 안하면 음수로 빠져서 스택오버플로우
	if (n == 0 || n == 1)
	{
		return acc;
	}
	return recursive(n - 1, acc * n);
}

int main()
{
	int N;
	cin >> N;

	cout << recursive(N, 1);
	return 0;
}