#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    string s;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        cin>> s;
        if(s.size()==2)
            cout<< s[1]<<endl;
        else
        {
            sort(s.begin(),s.end());
            cout<<s[0]<<endl;
        }
    }
}
