#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()

{
    int t,n;
    cin>> t;
    string ch="Timur";
    sort(ch.begin(),ch.end());
    //cout<< ch<<endl;
    for(int i=0;i<t;i++)
    {
        cin>> n;
        string ch2;
        cin>> ch2;
        sort(ch2.begin(),ch2.end());
        if(ch==ch2)
        {
            cout<< "YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}
