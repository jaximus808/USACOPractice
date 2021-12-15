#include<iostream>

using namespace std;

int* presum(int *arr, int n)
{
    int *summed = new int(n);
    summed[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        summed[i] = arr[i]+summed[i-1]; 
    }
    return summed;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] =x;
    }
    int *prefixed = presum(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<prefixed[i]<<" ";
    }
    cout << "\n";
    

    return 0; 
}