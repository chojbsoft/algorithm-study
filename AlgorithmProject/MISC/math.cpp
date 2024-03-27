#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>

using namespace std;

// 최대 공약수
// 유클리드 호제법 이용
// 특정 수와 0의 최대 공약수는 특정 수라는 걸 이용한 방법
// a와 b의 최대공약수는 b와 a%b의 최대공약수와 같음
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

// 최소 공배수
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

// 소수 확인
// 2부터 타겟의 제곱근까지(포함) 나눠지는지 확인
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

// 소수 모두 구하기
// 에라토스테네스의 체
// 2부터 n까지 자기자신을 제외한 모든 배수를 제거
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

// n진수 변환
// 0이 되기 전까지 N으로 나눈 나머지의 역순
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

// 16진수 변환은 아스키코드 신경쓰기
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
// 반환하고 싶을때는, 파라미터로 반환받아야, 레퍼런스 변수로 반환받아서 복사 비용 줄일 수 있음
// 기본 반환형으로 반환받으면, 레퍼런스 변수를 사용할 수 없음
// 지역변수의 레퍼런스를 반환해봤자 소멸되기 때문
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