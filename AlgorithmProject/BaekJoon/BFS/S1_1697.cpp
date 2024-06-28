#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> v;
	v.resize(100001, 0);

	queue<int> q;
	q.push(N);
	int curr = N;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();

		// 도착했다면 종료
		if (curr == K)
		{
			break;
		}

		// 방문 안한 노드만
		// 최소, 최대 경계값 체크
		if (curr > 0 && curr * 2 <= 100000 && !v[curr * 2])
		{
			// 방문 체크겸 깊이 체크
			v[curr * 2] = v[curr] + 1;
			q.push(curr * 2);
		}

		if (curr + 1 <= 100000 && !v[curr + 1])
		{
			v[curr + 1] = v[curr] + 1;
			q.push(curr + 1);
		}

		if (curr - 1 >= 0 && !v[curr - 1])
		{
			v[curr - 1] = v[curr] + 1;
			q.push(curr - 1);
		}
	}

	cout << v[curr];

	return 0;
}