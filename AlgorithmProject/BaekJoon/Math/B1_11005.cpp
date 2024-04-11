#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, B;
	cin >> N >> B;

	vector<char> v;
	v.reserve(10);
	while (N != 0)
	{
		int remainder = N % B;
		N /= B;

		if (remainder < 10)
		{
			remainder += 48;
		}
		else
		{
			remainder += 55;
		}

		v.push_back(static_cast<char>(remainder));
	}

	reverse(v.begin(), v.end());
	for (const char& c : v)
	{
		cout << c;
	}

	return 0;
}