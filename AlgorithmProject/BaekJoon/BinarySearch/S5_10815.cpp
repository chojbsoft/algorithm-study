#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 재귀함수는 inline키워드 붙여도 inline화 안됨
bool binary_search(vector<int>& v, int left, int right, int target)
{
	if (left > right)
	{
		return false;
	}

	int middle = (left + right) / 2;
	if (target == v[middle])
	{
		return true;
	}

	if (target < v[middle])
	{
		return binary_search(v, left, middle - 1, target);
	}
	else
	{
		return binary_search(v, middle + 1, right, target);
	}
}

int main()
{
	// 입출력이 많은 경우 꼭 해주기
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	// 미리 최대값으로 공간 확보해놔서 복사 비용 줄이기
	vector<int> v;
	v.reserve(500000);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		if (binary_search(v, 0, v.size()-1, temp))
		{
			cout << 1 << ' ';
		}
		else
		{
			cout << 0 << ' ';
		}
	}

	return 0;
}