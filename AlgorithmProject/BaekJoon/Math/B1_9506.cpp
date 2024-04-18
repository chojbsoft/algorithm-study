#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (true)
	{
		cin >> n;
		if (n == -1)
		{
			break;
		}

		vector<int> v;
		int half = n / 2;
		for (int i = 1; i <= half; i++)
		{
			if (n % i == 0)
			{
				v.push_back(i);
			}
		}

		int sum = 0;
		for (int& e : v)
		{
			sum += e;
		}

		if (sum == n)
		{
			cout << n << " = ";
			int size = v.size();
			for (int i=0; i<size; i++)
			{
				cout << v[i];
				if (i != size - 1)
				{
					cout << " + ";
				}
			}
		}
		else
		{
			cout << n << " is NOT perfect.";
		}
		cout << '\n';
	}

	return 0;
}