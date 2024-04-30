#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int ans = 0;

	// N의 범위가 백만이기 때문에 100n 복잡도까지는 가능
	for (int i = 1; i < N; i++)
	{
		int temp = i;
		int sum = i;

		// 10씩 나누면서 각 자리수 구하기
		while (temp != 0)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == N)
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}