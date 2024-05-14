#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 삼각형의 제일 긴 변의 길이는 남은 두 변의 길이를 더한 것보다 항상 짧아야함
	// 제일 긴 변의 길이가 같거나 커질때는 180도가 넘어간다는 뜻
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v{ a, b, c };
	sort(v.begin(), v.end());
	
	int sum = v[0] + v[1];
	int target = v[2];
	while (target >= sum)
	{
		target--;
	}

	cout << sum + target;

	return 0;
}