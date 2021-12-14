#include<iostream>
#include<vector>
using namespace std;

int n = 1; 
int key = 0; 
struct node
{
    vector<node> children;
    int value;
    //int key; 
    //looks for key with value 
    int CheckKey(int target_value)
    {
        if(target_value == value) return key;  
        for(int i = 0; i < children.size(); i++)
        {
            key++; 
            int k = children[i].CheckKey(target_value);
            if(k >-1) return k; 
        }
        return -1; 
    }
    bool InputNode(int k, int v)
    {
        //cout << key;
        if(k == key)
        {
             
            node c;
            c.value = v;
            children.push_back(c);
            //cout << "I have " << children.size()<<" children\n";
            return true; 
        }
        for(int i = 0; i < children.size(); i++)
        {
            key++;
            if(children[i].InputNode(k,v)) return true;
        }
        return false; 
    }
};
 

int main()
{
   int v;
   cin >> v; 
   node root;
   root.value = v;

   while(true)
   {
        key = 0;
        int x;
        cin >> x;
        //input node
        if(x == 1)
        {
            int k, y;
            cin >> k >> y; 
            bool success = root.InputNode(k,y);
            if(success) cout << "done";
            else cout << "error";
        }
        //look for the smallest key of the value
        if(x == 2)
        {
            int v;
            cin >> v;
            int k = root.CheckKey(v);
            cout << "I am at node: "<<k;
        }
        cout<<"\n";
   }
}