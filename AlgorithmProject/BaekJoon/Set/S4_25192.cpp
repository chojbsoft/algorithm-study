#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	// clear의 경우 해시 방식의 unordered가 더 느릴 수도 있음
	// set도 map처럼 레드블랙트리, unordered_set도 해시 방식으로 구현되어 있음
	set<string> s;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str == "ENTER")
		{
			cnt += s.size();
			s.clear();
		}
		else
		{
			s.insert(str);
		}
	}
	
	cnt += s.size();
	cout << cnt;

	return 0;
}
