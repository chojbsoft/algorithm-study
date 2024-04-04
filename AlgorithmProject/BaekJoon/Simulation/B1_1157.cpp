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

	// �׻� �Է��� �ּ�, �ִ� �����ϱ�
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
		// '0'�� 48, 'A'�� 65, 'a'�� 97
		if (str[i] >= 'a')
		{
			str[i] -= 32;
		}

		m[str[i]]++;
	}

	// map �����̳ʴ� �ڵ������̰�, ó�� ���� �ÿ� ���� ��Ģ�� Ű �����θ� ������
	// sort �Լ��� ����� �����̳ʴ� ���� ���� �ݺ��ڰ� �־���ϴµ�, map���� ����� ���� �ݺ���
		// auto it = m.begin() + 2; �̷� ���� �ȵ�
	// ���� vector�� �Űܼ� sort Ȱ��
	vector<pair<char, int>> v;
	v.reserve(m.size());
	for (auto& p : m)
	{
		v.push_back(p);
	}

	// Predicate �� �Լ� �����ؼ� �ֱ�
	sort(v.begin(), v.end(), comp);

	auto it = v.begin();
	char ans = it->first;
	
	// ���� �����ڰ� ���� �����ں��� �켱������ ���� ������ ��ȣ
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