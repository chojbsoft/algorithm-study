#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// 배열 초기화 시, 첫 원소를 0으로 초기화하면, 나머지들도 다 0으로 초기화됨
	char arr[100][100] = { 0 };

	int N, x, y;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> x >> y;
		
		// 캐시 적중률을 위해 이너루프는 열루프
		for (int k = y; k < y + 10; k++)
		{
			for (int j = x; j < x + 10; j++)
			{
				arr[k][j]++;
			}
		}
	}

	int zeroCnt = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (!arr[i][j])
			{
				zeroCnt++;
			}
		}
	}

	std::cout << 10000 - zeroCnt;

	return 0;
}