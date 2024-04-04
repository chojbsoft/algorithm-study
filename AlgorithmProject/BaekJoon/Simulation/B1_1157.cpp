#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b)
{
	return a.second > b.second;
}

int main()
{
	string str;
	cin >> str;

	// 항상 입력의 최소, 최대 조심하기
	if (str.size() == 1)
	{
		if (str[0] >= 'a')
		{
			str[0] -= 32;
		}
		cout << str[0];

		return 0;
	}

	unordered_map<char, int> m;
	size_t size = str.size();
	for (int i = 0; i < size; i++)
	{
		// '0'은 48, 'A'는 65, 'a'는 97
		if (str[i] >= 'a')
		{
			str[i] -= 32;
		}

		m[str[i]]++;
	}

	// map 컨테이너는 자동정렬이고, 처음 선언 시에 정렬 규칙은 키 값으로만 가능함
	// sort 함수에 사용할 컨테이너는 임의 접근 반복자가 있어야하는데, map류는 양방향 접근 반복자
		// auto it = m.begin() + 2; 이런 문장 안됨
	// 따라서 vector에 옮겨서 sort 활용
	vector<pair<char, int>> v;
	v.reserve(m.size());
	for (auto& p : m)
	{
		v.push_back(p);
	}

	// Predicate 비교 함수 정의해서 넣기
	sort(v.begin(), v.end(), comp);

	auto it = v.begin();
	char ans = it->first;
	
	// 지정 연산자가 전위 연산자보다 우선순위가 높기 때문에 괄호
	if (it->second == (++it)->second)
	{
		cout << '?';
	}
	else
	{
		cout << ans;
	}
	

	return 0;

}