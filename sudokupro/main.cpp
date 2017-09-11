#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

struct SudoMap
{
	int Map[9][9] = { 0 };
};

void Create_Map(int n, struct SudoMap sudomap[])
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

void print(int n, struct SudoMap sudomap[])
{
	ofstream outfile;
	outfile.open("sudoku.txt");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				outfile<< sudomap[i].Map[j][k] << " ";
			}
			outfile << endl;
		}
		outfile<< endl;
	}
	outfile.close();
}

int check(string a1, string a2)
{
	if (a1 == "-c")
	{
		int i;
		for (i = 0; i < a2.size(); i++)
		{
			if (a2[i]<'0' || a2[i]>'9')
			{
				cout << "输入的不是数字，请重新输入" << endl;
				return -1;
			}
		}
		if (i == a2.size())
			return 1;
	}
	else
		return -1;
}

int InPut(string a2)
{
	int num;
	stringstream ss(a2);
	ss >> num;
	return num;
}

int main(int argc,char*argv[])
{
	if (argc != 3)
	{
		cout << "参数数目输入错误，请重新执行" << endl;
		return 0;
	}
	string a1 = argv[1];
	string a2= argv[2];
	if (check(a1, a2) == 1)
	{
		int n = InPut(a2);
		SudoMap * sudomap = new SudoMap[n];
		Create_Map(n, sudomap);
		print(n, sudomap);
		return 0;
	}
	else
		return 0;
}