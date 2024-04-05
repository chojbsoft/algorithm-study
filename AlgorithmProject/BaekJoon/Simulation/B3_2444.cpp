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
			// +=�� push_back, append ȣ���ϴ� ������ �����ε�
			// push_back�� ĳ����
			// append�� ���ڿ�
			temp += ' ';
		}

		ans.insert(0, temp);

		// �������� ������ ����� ���� �������Ƿ� �ȳ���
		//ans += temp;
		
		cout << ans;
		if (i != size - 1)
		{
			cout << '\n';
		}
	}

	return 0;
}