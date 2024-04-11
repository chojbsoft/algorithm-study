#include <iostream>

using namespace std;

enum EMoney
{
	Quarter = 25,
	Dime = 10,
	Nickel = 5,
	Penny = 1
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int cent;
		cin >> cent;

		int cnt = cent / EMoney::Quarter;
		cent = cent % EMoney::Quarter;
		cout << cnt << ' ';

		cnt = cent / EMoney::Dime;
		cent = cent % EMoney::Dime;
		cout << cnt << ' ';

		cnt = cent / EMoney::Nickel;
		cent = cent % EMoney::Nickel;
		cout << cnt << ' ';

		cnt = cent / EMoney::Penny;
		cent = cent % EMoney::Penny;
		cout << cnt << '\n';
	}

	return 0;
}