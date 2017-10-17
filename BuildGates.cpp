//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <cmath>

using namespace std;
char path[1000];
bool mat[2015][2015];
int rs=0, rl=0, ys=0, yl=0, rc=0, yc=0;
int total=-1;

void floodfill(int row, int col)
{
    if(row<0 || col<0 || row>abs(rl-rs)+5 || col>abs(yl-ys)+5 || mat[row][col])
        return;
    mat[row][col]=true;
    floodfill(row+1, col);
    floodfill(row-1, col);
    floodfill(row, col+1);
    floodfill(row, col-1);
}

int main()
{
    int n;
    int i, j;
    bool a=false, b=false, c=false, d=false;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> path[i];
        if(path[i]=='N')
            rc-=2, a=true;
        else if(path[i]=='S')
            rc+=2, b=true;
        else if(path[i]=='E')
            yc+=2, c=true;
        else if(path[i]=='W')
            yc-=2, d=true;
        if(rc<rs)
            rs=rc;
        if(rc>rl)
            rl=rc;
        if(yc<ys)
            ys=yc;
        if(yc>yl)
            yl=yc;
    }
    rc=abs(rs), yc=abs(ys);
    mat[rc+1][yc+1]=true;
    
    for(i=0;i<n;i++){
        int x=0, y=0;
        if(path[i]=='N')
            x=-1;
        if(path[i]=='S')
            x=1;
        if(path[i]=='E')
            y=1;
        if(path[i]=='W')
            y=-1;
        for(j=0;j<2;j++){
            rc+=x, yc+=y;
            mat[rc+1][yc+1]=true;
        }
    }
    if(!a || !b || !c || !d){
        cout << "0" << endl;
        return 0;
    }
    for(i=0;i<=abs(rl-rs)+2;i++){
        for(j=0;j<=abs(yl-ys)+2;j++){
            if(!mat[i][j]){
                floodfill(i, j);
                total++;
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}
