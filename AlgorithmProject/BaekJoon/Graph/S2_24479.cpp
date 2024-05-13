#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> visited;

// order는 스택이 파괴되어도 유지되어야함으로 참조로 선언
void dfs(int node, int& order)
{
	visited[node] = order;

	for (int& next : v[node])
	{
		if (visited[next] == 0)
		{
			dfs(next, ++order);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, R;
	cin >> N >> M >> R;

	// 인접리스트는 간선의 개수만큼만 메모리를 차지해서, 인접행렬보다 메모리 이점이 많음
	// 인접리스트는 vector<vector<int>> 혹은 vector<int> v[]로 표현
	v.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int first, second;
		cin >> first >> second;

		// 양방향 그래프기 때문에 각각 from으로 넣기
		v[first].push_back(second);
		v[second].push_back(first);
	}

	// 오름 차순으로 정점을 방문한다고 했기 때문에 정렬
	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	int order = 1;
	dfs(R, order);
	for (int i = 1; i <= N; i++)
	{
		cout << visited[i] << '\n';
	}

	return 0;
}