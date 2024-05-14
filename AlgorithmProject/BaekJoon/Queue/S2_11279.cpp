#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int N;
	cin >> N;

	// 우선순위 큐는 내부적으로 벡터 기반 최대 힙으로 구현되어 있음
	// 삽입할 때마다 hipify로 swap됨
	priority_queue<unsigned int> q;
	for (int i = 0; i < N; i++)
	{
		int in;
		cin >> in;
		if (in)
		{
			int remain = N - i - 1;
			if (q.size() > remain)
			{

			}

			q.push(in);
		}
		else
		{
			if (!q.empty())
			{
				cout << q.top() << '\n';
				q.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}