//File: A2_S5_20220139_7.cpp
//purpose: arrange domino
//Author: Remon raafat nassif
//Section: S5
//ID: 20220139
//TA: Eng/Maya
//Date: 27 Oct 2023
#include<iostream>
#include<vector>

using namespace std;

struct domino
{
	int leftdomino;
	int rightdomino;
};
void test(vector<domino>v)
{
	vector<domino>vt(v);
	for (int i = 0; i < vt.size(); i++)
	{
		bool t = true;
		for (int j = 0; j < vt.size(); j++)
		{
			if ((vt[i].leftdomino == vt[j].rightdomino) && i != j)
			{
				t = false;
				break;
			}
		}
		if (t)
		{
			swap(vt[0], vt[i]);
		}
	}
	for (int i = 0; i < vt.size()-1; i++)
	{
		for (int j = i + 1 ; j < vt.size(); j++)
		{
			if (vt[i].rightdomino == vt[j].leftdomino && vt[i].rightdomino == vt[j].rightdomino && i != j)
			{
				swap(vt[i + 1], vt[j]);
				break;
			}
			else if (vt[i].rightdomino == vt[j].leftdomino && i != j)
			{
				swap(vt[i + 1], vt[j]);
				
			}
		}
	}
	bool t = true;
	for (int i = 0; i < vt.size() - 1; i++)
	{
		
		if (vt[i].rightdomino != vt[i + 1].leftdomino) t = false;
	}
	if (t) {
		cout << "True" << endl;
		for (int i = 0; i < vt.size(); i++)
		{
			cout << vt[i].leftdomino << " | " << vt[i].rightdomino;
			if (i != vt.size() - 1) cout << " - ";

		}
	}
	else cout << "False" << endl;
}
void menu()
{
	vector<domino>v;
	int n; cout << "Enter maximum number : "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ld; cout << "Enter left part of domino " << i + 1 << " : "; cin >> ld;
		int rd; cout << "Enter right part of domino " << i + 1 << " : "; cin >> rd;
		if (ld < 0 || ld>6 || rd > 6 || rd < 0)
		{
			cout << "Invalid number ( please enter a number between 0 , 6 )" << endl;
			menu();
			break;
		}
		domino d; d.leftdomino = ld; d.rightdomino = rd;
		for (auto k : v)
		{
			if ((k.leftdomino == d.leftdomino && k.rightdomino == d.rightdomino)
				|| k.leftdomino == d.rightdomino && k.rightdomino == d.leftdomino) {
				cout << "reapeted domino " << endl;
				menu();
				break;
			}
		}
		v.push_back(d);
	}
	test(v);
}

int main()
{
	menu();
	return 0;
}
