#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>

using namespace std;

// �ִ� �����
// ��Ŭ���� ȣ���� �̿�
// Ư�� ���� 0�� �ִ� ������� Ư�� ����� �� �̿��� ���
// a�� b�� �ִ������� b�� a%b�� �ִ������� ����
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

// �ּ� �����
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// �Ҽ� Ȯ��
// 2���� Ÿ���� �����ٱ���(����) ���������� Ȯ��
bool isPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}

	int end = sqrt(num);
	for (int i = 2; i <= end; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

// �Ҽ� ��� ���ϱ�
// �����佺�׳׽��� ü
// 2���� n���� �ڱ��ڽ��� ������ ��� ����� ����
vector<int> era(int n)
{
	vector<int> res;
	res.reserve(n / 2);
	vector<bool> boolVec(true, n + 1);
	res.reserve(n / 2);

	for (int i = 2; i <= n; i++)
	{
		if (!boolVec[i])
		{
			continue;
		}

		for (int j = i * 2; j <= n; j += i)
		{
			boolVec[j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (boolVec[i])
		{
			res.push_back(i);
		}
	}

	return res;
}

// n���� ��ȯ
// 0�� �Ǳ� ������ N���� ���� �������� ����
vector<int> toBinary(int num)
{
	vector<int> res;
	while (1)
	{
		if (num == 0)
		{
			break;
		}
		res.push_back(num % 2);
		num = num / 2;
	}
	reverse(res.begin(), res.end());

	return res;
}

// 16���� ��ȯ�� �ƽ�Ű�ڵ� �Ű澲��
vector<char> toHex(int num)
{
	vector<char> res;
	while (1)
	{
		if (num == 0)
		{
			break;
		}
		auto val = num % 16;
		if (val < 10)
		{
			res.push_back(val + 48);
		}
		else
		{
			res.push_back(val + 55);
		}
		num = num / 16;
	}
	reverse(res.begin(), res.end());

	return res;
}

// Rotate
// ��ȯ�ϰ� ��������, �Ķ���ͷ� ��ȯ�޾ƾ�, ���۷��� ������ ��ȯ�޾Ƽ� ���� ��� ���� �� ����
// �⺻ ��ȯ������ ��ȯ������, ���۷��� ������ ����� �� ����
// ���������� ���۷����� ��ȯ�غ��� �Ҹ�Ǳ� ����
void rotate90(int row, int col, vector<vector<int>>& v, vector<vector<int>>& v2)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			v2[j][row - i - 1] = v[i][j];
		}
	}
}

void DoRotate90()
{
	int row = 3;
	int col = 2;

	vector<vector<int>> v;
	v.resize(row);
	for (int i = 0; i < row; i++)
	{
		v[i].resize(col);
	}
	v[0][0] = 3;
	v[2][1] = 2;


	vector<vector<int>> v2;
	v2.resize(col);
	for (int i = 0; i < col; i++)
	{
		v2[i].resize(row);
	}

	rotate90(3, 2, v, v2);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << v2[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	
	return 0;
}