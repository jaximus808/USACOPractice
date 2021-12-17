#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

unordered_map<string, vector<string>> AssocationTree;

void BFS(string root)
{
    vector<string> visited; 
    vector<string> current;
    current.push_back(root); 
    while(current.size() > 0)
    {
        string cur = current[current.size() - 1];
        current.pop_back();
        if(find(visited.begin(), visited.end(), cur) == visited.end())
        {
            cout<<cur; 
            for(int i = 0; i < AssocationTree[cur].size(); i++)
            {
                current.push_back(AssocationTree[cur][i]);
            }
            visited.push_back(cur); 
        }
    }
}
void DFS(string root)
{
    vector<string> visited; 
    vector<string> current;
    current.push_back(root); 
    while(current.size() > 0)
    {
        string cur = current[current.size() - 1];
        current.pop_back();
        if(find(visited.begin(), visited.end(), cur) == visited.end())
        {
            cout<<cur; 
            for(int i = 0; i < AssocationTree[cur].size(); i++)
            {
                current.push_back(AssocationTree[cur][i]);
            }
            visited.push_back(cur); 
        }
    }
}

int main()
{
    while(true)
    {
        int x;
        cin >> x;
        //insert node 
        if(x == 1)
        {
            string l;
            cin >> l;
            if(AssocationTree.find(l) != AssocationTree.end())
            {
                cout <<"node exists already";
            }
            else 
            {
                vector<string> init; 
                AssocationTree[l] = init;
            }
        }
        //create connection 
        else if(x == 2)
        {
            //how many connections to make
            int n; 
            string l;
            cin >> l; 
            cin >> n;
            if(AssocationTree.find(l) == AssocationTree.end())
            {
                cout << "node does not exist";
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    string con;
                    cin >> con; 
                    if(find(AssocationTree.begin(), AssocationTree.end(), con) == AssocationTree.end())
                    {
                        AssocationTree[l].push_back(con); 
                    }
                }
            }
        }
        else if(x == 3)
        {
            string l;
            cin >> l; 
            BFS(l);
        }
        else if(x==4)
        {
            string l;
            cin >> l; 
            DFS(l);
        }
    }
}