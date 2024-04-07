#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	std::unordered_map<int, int> m;
	for (int i = 0; i < 10; i++)
	{
		int num;
		std::cin >> num;

		int remain = num % 42;
		m.insert(std::make_pair(remain, 1));
	}
	
	size_t cnt = m.size();
	std::cout << cnt;

	return 0;
}