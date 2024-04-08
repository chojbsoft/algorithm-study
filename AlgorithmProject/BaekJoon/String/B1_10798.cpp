#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> v;
	v.reserve(5);
	int colMax = 0;
	for (int i = 0; i < 5; i++)
	{
		string input;
		getline(cin, input);
		v.push_back(input);

		size_t len = input.length();

		// size_t�� unsigned long long�̱� ������, ���� colMax�� -1�̶�� �ǵ�ġ ���� ����� ����
		if (len > colMax)
		{
			colMax = len;
		}
	}

	size_t row = v.size();
	for (int i = 0; i < colMax; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			try
			{
				cout << v[j][i];
			}
			catch (const exception& e)
			{
				
			}
		}
	}

	return 0;
}