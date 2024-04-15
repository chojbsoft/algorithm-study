#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1방		2방		3방		n방
	// 1이하		7이하	19이하	a[n] = a[n-1] + (n-1)*6

	int N;
	cin >> N;

	// 점화식: 이전 항들과의 관계로 항을 표현하는 표현식
	// 항: 피연산자와 연산자로 구성된 표현식의 최소 단위
	// 조건에 맞을 때까지, 1부터 cnt를 늘려가며 점화식 대입
	int start = 1;
	int cnt = 0;
	while (true)
	{
		cnt++;
		if (N <= start)
		{
			break;
		}

		start = start + cnt * 6;
	}

	cout << cnt;

	return 0;
}