//greedy algorithm is very dependent on the case but for calculating the 
//least amount of coins needed this is how it would look
#include<iostream>

using namespace std;

int coins[4] = {25, 10, 5, 1};


int main()
{
    int c = 0;
    int x;
    cin >> x;
    while(x >0)
    {
        for(int i = 0; i < 4; i++)
        {
            if(x/coins[i] >= 1)
            {
                x = x - coins[i];
                break;
            }
        }
        c++;
    }
    cout<<c<<"\n";
}