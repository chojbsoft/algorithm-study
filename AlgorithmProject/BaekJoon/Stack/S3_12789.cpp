#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		q.push(input);
	}

	// 번호표를 1로 두고, 들어올 때마다 증가시키기
	int curr = 1;
	stack<int> s;
	while (!q.empty())
	{
		int num = q.front();
		if (num == curr)
		{
			curr++;
			q.pop();
			
			// curr가 올라갔으니, 스택에 쌓인 번호표가 curr와 일치한다면 털기
			while (!s.empty() && s.top() == curr)
			{
				s.pop();
				curr++;
			}
		}
		else if (s.empty())
		{
			s.push(num);
			q.pop();
		}
		else if (num < s.top())
		{
			s.push(num);
			q.pop();
		}
		else
		{
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";

	return 0;
}