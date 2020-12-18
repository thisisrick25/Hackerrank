#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double findMean(int a[], int n);
void sort(int a[], int n);
double findMedian(int a[], int n);
int findMode(int a[], int n);

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << findMean(a, n) << endl;
    cout << findMedian(a, n) << endl;
    cout << findMode(a, n) << endl;

    return 0;
}

double findMean(int a[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return (double)sum / n;
}

double findMedian(int a[], int n)
{
    // First we sort the array
    sort(a, a + n);

    // check for even case
    if (n % 2 != 0)
        return (double)a[n / 2];

    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

void sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int findMode(int a[], int n)
{
    int current = 0; 
    int count = 0;
    int mode = 0;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == current)
            count++;
        else
        {
            count = 1;
            current = a[i];
        }
        if (count > max)
        {
            max = count;
            mode = a[i];
        }
    }
    return mode;
}