#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string str, bomb;
	cin >> str >> bomb;

	stack<char> s;
	int strSize = str.size();
	int bombSize = bomb.size();
	for (int i = 0; i < strSize; i++)
	{
		char c = str[i];
		s.push(c);

		// 폭발 문자열의 길이만큼 미리 캐싱해 놓는 최적화 방식은 연속 폭발까진 구현 못함
		// 따라서 마지막 문자만 확인해서, 그때마다 폭발 문자열 길이만큼 비교
		if (c == bomb[bombSize - 1])
		{
			bool flag = false;
			stack<char> temp;
			for (int j = 0; j < bombSize; j++)
			{
				if (!s.empty() && s.top() == bomb[bombSize - 1 - j])
				{
					flag = true;
					temp.push(s.top());
					s.pop();
				}
				else
				{
					flag = false;
					break;
				}
			}

			if (!flag)
			{
				while (!temp.empty())
				{
					s.push(temp.top());
					temp.pop();
				}
			}
		}
	}

	if (s.empty())
	{
		cout << "FRULA";
	}
	else
	{
		stack<char> temp;
		while (!s.empty())
		{
			temp.push(s.top());
			s.pop();
		}

		while (!temp.empty())
		{
			cout << temp.top();
			temp.pop();
		}
	}

	return 0;
}