#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string& s)
{
	vector<string> v;
	while (true)
	{
		size_t idx{ s.find(" ") };
		if (idx == string::npos)
		{
			break;
		}

		string sub = s.substr(0, idx);
		v.push_back(sub);
		s.erase(0, idx + 1);
	}
	v.push_back(s);

	return v;
}

int main()
{
	string s = "string split test";
	vector<string> v = split(s);
	cout << v[1];
	return 0;
}