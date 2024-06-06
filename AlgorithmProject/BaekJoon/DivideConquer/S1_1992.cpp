#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> v;
int N;

void partition(int rowStart, int rowEnd, int colStart, int colEnd)
{
	if (rowStart == rowEnd)
	{
		std::cout << v[rowStart][colStart];
		return;
	}

	int num = v[rowStart][colStart];
	bool flag = true;
	for (int i = rowStart; i <= rowEnd; i++)
	{
		for (int j = colStart; j <= colEnd; j++)
		{
			if (v[i][j] != num)
			{
				flag = false;
				break;
			}
		}

		if (!flag)
		{
			break;
		}
	}

	if (flag)
	{
		std::cout << num;
		return;
	}

	// 퀵소트처럼 정복한 뒤 분할
	int rowMid = (rowStart + rowEnd) / 2;
	int colMid = (colStart + colEnd) / 2;

	std::cout << '(';
	partition(rowStart, rowMid, colStart, colMid);
	partition(rowStart, rowMid, colMid + 1, colEnd);
	partition(rowMid + 1, rowEnd, colStart, colMid);
	partition(rowMid + 1, rowEnd, colMid + 1, colEnd);
	std::cout << ')';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	// 2차원 배열일 때 inner까지 resize
	v.resize(N);
	for (vector<int>& inner : v)
	{
		inner.resize(N);
	}

	for (int i = 0; i < N; i++)
	{
		// cin.get()은 버퍼의 개행까지 받기 때문에 비워주기
		cin.get();
		for (int j = 0; j < N; j++)
		{
			// cin.get()은 char형으로 입력 받기 때문에 보정
			v[i][j] = cin.get() - '0';
		}
	}

	partition(0, N - 1, 0, N - 1);

	return 0;
}