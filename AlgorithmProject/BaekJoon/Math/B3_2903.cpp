#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	// 0부터 귀납적으로 대입해서 패턴찾기
	cout << (int)pow((int)pow(2, N) + 1, 2);

	return 0;
}