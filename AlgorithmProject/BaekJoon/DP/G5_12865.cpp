#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, K;
vector<int> W;
vector<int> V;
int mx = INT_MIN;

int dp[101][100001];

void dfs(int idx, int weight, int value)
{
	if (idx == N)
	{
		if (value > mx)
		{
			mx = value;
		}

		return;
	}

	// 현재 idx에서 같은 weight 경로를 왔었다면, 어차피 결과도 똑같으니 백트래킹?
	// 하지만 현재 idx에서 같은 weight여도 가치가 다를 수 있고, 이때까지의 가치의 최대값이 어차피 최대가 됨
	// 따라서 현재 value가 기록이 있는 dp보다 적거나 같을 때는 백트래킹
	if (dp[idx][weight] == 0 || value > dp[idx][weight])
	{
		dp[idx][weight] = value;
	}
	else
	{
		return;
	}

	// 안 넣을 경우와 넣을 경우로 2^n번의 모든 경우를 dfs
	// 안 넣을 경우
	dfs(idx + 1, weight, value);

	// 넣을 경우
	if (weight + W[idx] <= K)
	{
		dfs(idx + 1, weight + W[idx], value + V[idx]);
	}
}

int main()
{
	cin >> N >> K;

	W.resize(N);
	V.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> W[i] >> V[i];
	}

	dfs(0, 0, 0);

	cout << mx;

	return 0;
}