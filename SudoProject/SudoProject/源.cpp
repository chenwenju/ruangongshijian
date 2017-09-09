#include<iostream>
#include<algorithm>
using namespace std;

struct SudoMap
{
	int Map[9][9] = { 0 };
};

void Create_Map(int n,struct SudoMap sudomap[])
{
	for (int k = 0; k < n; k++)
	{
		sudomap[k].Map[0][0] = 1;
	}
	int num[8] = { 2,3,4,5,6,7,8,9 };
	int i = 0;
	do
	{
		for (int j = 1; j <= 8; j++)
		{
			sudomap[i].Map[0][j] = num[j - 1];
		}
		i++;
	} while (next_permutation(num, num + 8) && i < n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sudomap[i].Map[1][j] = sudomap[i].Map[0][(j + 3) % 9];
			sudomap[i].Map[2][j] = sudomap[i].Map[0][(j + 6) % 9];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			for (int j = 3; j < 6; j++)
			{
				sudomap[i].Map[j][k] = sudomap[i].Map[(j - 3)][(k + 1) % 9];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			for (int j = 6; j < 9; j++)
			{
				sudomap[i].Map[j][k] = sudomap[i].Map[(j - 6)][(k + 2) % 9];
			}
		}
	}
}

void print(int n,struct SudoMap sudomap[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				cout << sudomap[i].Map[j][k]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	SudoMap * sudomap = new SudoMap[n];
	Create_Map(n,sudomap);
	print(n,sudomap);
	cin >> n;

}