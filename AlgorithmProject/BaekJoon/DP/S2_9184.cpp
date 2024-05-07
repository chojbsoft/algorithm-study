#include <iostream>
#include <map>
#include <vector>

using namespace std;

// unordered_map에서는 vector 타입을 위한 해시함수가 없어서 map을 사용해야됨
// 벡터는 값 비교로 연산자 오버로딩이 되어 있어서 == 연산자 가능
map<vector<int>, int> m;
int recursive(int a, int b, int c)
{
	// 중복된 부분 문제들이 있기 때문에 DP
	if (m[{a, b, c}] !=0)
	{
		return m[{a, b, c}];
	}

	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	if (a > 20 || b > 20 || c > 20)
	{
		return recursive(20, 20, 20);
	}
	if (a < b && b < c)
	{
		return m[{a, b, c}] = recursive(a, b, c - 1) + recursive(a, b - 1, c - 1) - recursive(a, b - 1, c);

	}
	
	return m[{a, b, c}] = recursive(a - 1, b, c) + recursive(a - 1, b-1, c) + recursive(a-1, b, c-1) - recursive(a - 1, b - 1, c - 1);
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		int ans = recursive(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
	}

	return 0;
}