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
        string cur = current[0];
        //cout << "dick: "<<cur;
        current.erase(current.begin());
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
                break;
            }
            else
            {
                for(int i = 0; i < n; i++)
                {
                    string con;
                    cin >> con; 
                    if(find(AssocationTree[l].begin(), AssocationTree[l].end(), con) == AssocationTree[l].end())
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
        else if(x == 4)
        {
            string l;
            cin >> l; 
            DFS(l);
        }
    }
}
// 1 a
// 1 b 
// 1 c
// 1 d
// 1 e
// 1 g
// 1 z
// 1 x
// 1 y
// 1 q
// 1 u
// 2 a 2 b c
// 2 b 2 d e
// 2 e 1 g
// 2 g 1 z
// 2 c 1 x 
// 2 x 2 y q 
// 2 q 1 u
// 2 u 1 y
