#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<float> v;
	v.reserve(N);

	double Max{};
	double Input{};
	for (int i = 0; i < N; i++)
	{
		cin >> Input;
		if (Input > Max)
		{
			Max = Input;
		}

		v.push_back(Input);
	}

	double Sum{};
	for (int i = 0; i < N; i++)
	{
		Sum += v[i] / Max * 100;
	}

	cout << Sum / N;

	return 0;
}