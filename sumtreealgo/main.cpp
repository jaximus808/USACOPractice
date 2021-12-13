#include<iostream>

using namespace std;

int n; 
int seg[10000000];

void insert(int curr, int start, int end, int index, int value)
{
    if(index > end || index < start)
    {
        return; 
    }
    if(start == end)
    {
        seg[curr] = value;
        return; 
    }
    //cout << 2*curr + 1 << endl;
    insert(2*curr+1, start, (start+end)/2, index, value);
    insert(2*curr+2, (start+end)/2 +1, end, index, value);
    seg[curr] = seg[2*curr +1] + seg[2*curr+2];
}

void insert(int index, int value)
{
    //cout <<"???";
    insert(0,0, n-1, index,value);
}

//q1 is the begining range and qr is th ending of the range
//add between q1 to q2
int sum(int curr, int start, int end, int q1, int qr)
{
    //if out of range ignore
    if(q1 > end || qr < start) return 0; 
    //if the vertex or parent vertex (which is the sum of the range) is in between the given range
    //then just return because everything under is in the range and we already know the sum
    if(start >= q1 && end <= qr) return seg[curr];
    //this adds the two sides together and returns it
    return sum(2*curr+1, start, (start+end)/2,q1, qr) +sum(2*curr+2, (start+end)/2+1, end,q1, qr);
}

int sum(int q1, int qr)
{
    return sum(0,0, n-1, q1, qr);
}

void printTree()
{
    cout << "new tree array: \n";
    for(int i = 0; i<40; i++)
    {
        cout<<seg[i]<<", ";
    }
    cout<<"\n";
}

int main()
{
    cin >> n; 
    while(true)
    {
        int x; 
        cin >> x; 
        if(x==1)
        {
            
            int ind,val;
            cin>> ind>>val;
            insert(ind,val);
            // cout <<"print";
            //printTree();
        }
        else if(x == 2)
        {
            int beg, end; 
            cin >> beg >> end;
            cout<<sum(beg, end)<<"\n";
        }
    }
}