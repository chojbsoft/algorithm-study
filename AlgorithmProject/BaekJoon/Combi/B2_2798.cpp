#include <iostream>
#include <vector>
using namespace std;

// 재귀함수일 때는 전역변수로 상태유지
int N, M;
int mx;
vector<int> v;
vector<int> temp;

void combi(int idx)
{
	if (temp.size() == 3)
	{
		int sum = 0;
		for (int& i : temp)
		{
			sum += i;
		}

		if (sum <= M && sum > mx)
		{
			mx = sum;
		}

		return;
	}

	// 중복 조합이 아니기 때문에, 다음 재귀함수는 다음 인덱스로 호출
	for (int i = idx; i < N; i++)
	{
		temp.push_back(v[i]);
		combi(++idx);
		temp.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	combi(0);
	cout << mx;

	return 0;
}