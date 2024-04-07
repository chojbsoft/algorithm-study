#include <iostream>
#include <vector>
int main()
{
	int N, M;
	std::cin >> N >> M;
	
	std::vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}

	for (int i = 0; i < M; i++)
	{
		int left, right;
		std::cin >> left >> right;
		left--;
		right--;

		while (left < right)
		{
			int temp = v[left];
			v[left] = v[right];
			v[right] = temp;

			left++;
			right--;
		}
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << v[i] << ' ';
	}

	return 0;
}