#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	string input;
	for (int i = 0; i < T; i++)
	{
		stack<int> s;
		cin >> input;
		int size = input.size();
		for (int j = 0; j < size; j++)
		{
			char target = input[j];

			// top이 여는 괄호이고, 다음이 닫는 괄호 일때는 push없이 pop
			if (!s.empty() && s.top() == '(' && target == ')')
			{
				s.pop();
			}
			else
			{
				s.push(input[j]);
			}
		}

		if (s.size() != 0)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
		}

	}

	return 0;
}