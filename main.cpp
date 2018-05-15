#include <stdio.h>
#include <string>
#include<stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int map[55][55];
int dp[110][55][55];
struct node{
    int x;
    int y;
    node(int x = 0 , int y = 0) : x(x) , y(y) {}
}path[110][55][55];

void cmp(int& x , int& y , int i , int j , int k , long long & tmp){
    if(!k) {
        x = 1;
        y = 1;

        return;
    }
    if(tmp < dp[k][i][j]) {
        tmp = dp[k][i][j];
        x = i;
        y = j;
    }
    return 0;
}
vector<node> xpath;

void findLu(int x , int y , int k) {
    xpath.push_back(node(x , y));
    if(k == 0)
    return 0;
    int x1 = path[k][x][y].x;
    int y1= path[k][x][y].y;
    findLu(x1 , y1 , k - 1);
}



extern "C" {  
    void test(char *var)
    {

    int ncase;
    string s;

    scanf("%d",&ncase);
    while(ncase--)
    {
        int n,m;
        memset(dp,0,sizeof(dp));
        memset(map,0,sizeof(map));
        scanf("%d %d",&m,&n);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&map[i][j]);
        int step=m+n-2;
        xpath.clear();
        for(int i=1;i<=m;i++)
        {

            for(int j=i+1;j<=m;j++)
            for(int k=1;k<step;k++)
                    {
                        long long tmp = -1;
                        int x , y;
                        dp[k][i][j]=max(max(dp[k-1][i-1][j],dp[k-1][i-1][j-1]),
                        max(dp[k-1][i][j],dp[k-1][i][j-1]))+map[i][k-i+2]+map[j][k-j+2];
                        cmp(x ,y , i , j , k - 1 , tmp);
                        cmp(x , y , i - 1 , j - 1  , k - 1  , tmp);
                        cmp(x ,y , i  , j - 1 , k - 1 , tmp);
                        cmp(x ,y , i - 1 , j , k - 1 , tmp);
                        path[k][i][j] = {x , y};
                    }

        }
        long long  tmp = -1;
        int x , y;
        cmp(x ,y , m , m , step - 1 , tmp);
        cmp(x , y , m - 1 , m - 1  , step - 1  , tmp);
        cmp(x ,y , m  , m - 1 , step - 1 , tmp);
        cmp(x ,y , m - 1 , m , step - 1 , tmp);

        path[step][m][m] = {x , y};


        findLu( m , m , m + n - 2);

        int a;
        char v[10];
        a=max(dp[step-1][m][m-1],dp[step-1][m-1][m])+map[m][n];
        itoa(a,v,10);
        s=s+v+" ";
        //cout<<s[0]<<endl;
        int tstep = 1;
        for(int i = xpath.size() - 1 ; i >= 0 ; --i) {
            //cout << xpath[i].x << " " << tstep + 1- xpath[i].x<< endl;
            itoa(xpath[i].x,v,10);s=s+v+",";
            itoa(tstep + 1- xpath[i].x,v,10);s=s+v+" ";


            tstep++;
       }

       for(int i = 1 ; i < xpath.size(); ++i) {
            //cout << xpath[i].y << " " << tstep - 1- xpath[i].y<< endl;
            itoa(xpath[i].y,v,10);s=s+v+",";
            itoa(tstep - 1- xpath[i].y,v,10);s=s+v+" ";
            tstep--;

       }
       s=s+"\n";

    }
    char *cstr = strdup(s.c_str());
    cout<<cstr<<endl;
    strcpy(var,cstr);
}
}  