#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// �迭 �ʱ�ȭ ��, ù ���Ҹ� 0���� �ʱ�ȭ�ϸ�, �������鵵 �� 0���� �ʱ�ȭ��
	char arr[100][100] = { 0 };

	int N, x, y;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> x >> y;
		
		// ĳ�� ���߷��� ���� �̳ʷ����� ������
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