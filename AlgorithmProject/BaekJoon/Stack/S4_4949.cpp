#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
		string input;
		getline(cin, input);
		
		// string의 size()와 length()는 둘다 요소의 개수를 반환함
		// 다른 컨테이너들과의 일관성을 위해 size()를 넣은것
		if (input[0] == '.' && input.size() == 1)
		{
			break;
		}

		stack<char> s;
		for (char c : input)
		{
			// 여는 괄호는 무조건 push
			if (c == '(' || c == '[')
			{
				s.push(c);
			}
			else if (c == ')')
			{
				// 닫는 괄호일 때, 스택의 top에 여는괄호가 없다면 false
				// top 하기 전에 empty 체크해야함
				if (!s.empty() && s.top() == '(')
				{
					s.pop();
				}
				else
				{
					goto no;
				}
			}
			else if (c == ']')
			{
				if (!s.empty() && s.top() == '[')
				{
					s.pop();
				}
				else
				{
					goto no;
				}
			}
		}

		if (s.empty())
		{
			cout << "yes" << '\n';
		}
		else
		{
		no:
			cout << "no" << '\n';
		}

	}


	return 0;
}