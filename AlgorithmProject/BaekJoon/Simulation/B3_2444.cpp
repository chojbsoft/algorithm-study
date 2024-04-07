#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int size = 2 * N - 1;
	for (int i = 0; i < size; i++)
	{
		string ans;
		int cnt = i > size / 2
			? 2 * (size - i - 1) + 1
			: 2 * i + 1;

		for (int j = 0; j < cnt; j++)
		{
			ans += '*';
		}

		int remain = (size - cnt) / 2;
		string temp;
		for (int j = 0; j < remain; j++)
		{
			// +=는 push_back, append 호출하는 연산자 오버로딩
			// push_back은 캐릭터
			// append는 문자열
			temp += ' ';
		}

		ans.insert(0, temp);

		// 오른쪽은 공백은 언급이 따로 없었으므로 안넣음
		//ans += temp;
		
		cout << ans;
		if (i != size - 1)
		{
			cout << '\n';
		}
	}

	return 0;
}