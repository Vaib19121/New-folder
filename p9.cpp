#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
void findPrimefactors(unordered_set<int> &s, int n)
{
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
        s.insert(n);
}
int findPrimitive(int n)
{
    unordered_set<int> s;
    if (isPrime(n) == false)
        return -1;
    int phi = n - 1;
    findPrimefactors(s, phi);
    for (int r = 2; r <= phi; r++)
    {
        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (power(r, phi / (*it), n) == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return r;
    }
    return -1;
}

int main()
{
    cout << "Name: Vaibhav Mehar   Sec: B   Roll No: 58   Batch: b2" << endl;
    double P, g, a, b, x, y;
    cout << "Enter the value of P: ";
    cin >> P;
    if (findPrimitive(P) == -1)
        return 0;
    g = findPrimitive(P);
    cout << "The Primitive root of " << P << " Is: " << g << endl;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    double temp = pow(g, a);
    x = fmod(temp, P);
    temp = pow(g, b);
    y = fmod(temp, P);
    double R1, R2;
    double k;
    temp = pow(y, a);
    R1 = fmod(temp, P);
    temp = pow(x, b);
    R2 = fmod(temp, P);
    temp = pow(R2, y);
    k = fmod(temp, P);
    cout << "Value of R1: " << R1 << endl;
    cout << "Value of R2: " << R2 << endl;
    cout << "Value of K: " << k;
    return 0;
}