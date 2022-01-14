#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int tmp = N / 5;
	int tmp2 = N / 25;
	int tmp3 = N / 125;
	cout << tmp + tmp2 + tmp3;
}