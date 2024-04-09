#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
	char temp;
	stack<char> Stack;
	while (cin.get(temp))
	{
		// 공백 입력이 들어오면 break
		// 공백은 0이 아닌 32
		if (temp == ' ')
		{
			break;
		}

		Stack.push(temp);
	}

	int B;
	cin >> B;

	int Sum = 0;
	int Pos = 0;
	while (!Stack.empty())
	{
		int Element = Stack.top();
		if (Element < 65)
		{
			Element -= 48;
		}
		else
		{
			Element = Element - 65 + 10;
		}

		Sum += Element * pow(B, Pos++);
		Stack.pop();
	}
	
	cout << Sum;

	return 0;
}