//File: A2_S5_20221099_4.cpp
//purpose: print prime numbers from 2 to N
//Author: Remon raafat nassif
//Section: S5
//ID: 20220139
//TA: Eng/Maya
//Date: 30 Oct 2023
#include <iostream>
#include <vector>

using namespace std;

void  thesieveofEratosthenes();

int main()
{
    thesieveofEratosthenes();
    return 0;
}

void  thesieveofEratosthenes()
{
    int n;
    cout << "Enter the maximum number : ";
    cin >> n;
    vector<int> prime;
    for (int i = 2; i <= n; i++)
    {
        prime.push_back(i);
    }
    for (auto k : prime)
        cout << k << " ";
    cout << "\n************************************\n";
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = 0; j < prime.size(); j++)
        {
            if (prime[j] % i == 0 && prime[j] != i)
            {
                prime[j] = 0;
            }
        }
        for (auto k : prime)
        {
            if (k != 0) cout << k << " ";
        }
        cout << "\n************************************\n";

    }

}
