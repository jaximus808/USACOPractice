#include<iostream>

using namespace std;

//will be multi dimensional
int map[50][50];
int h; //y
int w; //x

void fill(int curX, int curY, int target_color, int color)
{
    if(curX < 0 || curX > w || curY> h || curY < 0)
    {
        return; 
    }
    //if we're not on our color function return 
    if(map[curY][curX] != target_color) return;


    //current square must be our color target
    map[curY][curX] = color;
    //now look in 4 dimensions
    fill(curX +1, curY, target_color, color); //right
    fill(curX -1, curY, target_color, color); //left
    fill(curX, curY+1, target_color, color); //up
    fill(curX, curY-1, target_color, color); //south

}

void fill(int startX, int startY, int color)
{
    int target_color = map[startY][startX];
    fill(startX, startY, target_color, color);
}

void display()
{
    for(int i = 0; i < h;i++)
    {
        for(int y = 0; y < w; y++)
        {
            cout << map[i][y] << " ";
        }
        cout <<"\n";
    }
}

int main()
{
    cin >> h>> w;
    //user can input a x and y pos and color(int) to and fill 
    for(int i = 0; i < h;i++)
    {
        for(int y = 0; y < w; y++)
        {
            int n = 0;
            cin >> n;
            map[i][y] = n;
        }
    }
    while(true)
    {
        int x;
        cin >> x;
        //fill  
        if(x == 1)
        {
            int sX, sY, col;
            cin >> sX>> sY>> col;
            fill(sX, sY,col);
        }
        else if(x == 2 ) //replace an "island"
        {

        }
        else if(x == 3) // print the islands
        {
            display();
        }
    }
}