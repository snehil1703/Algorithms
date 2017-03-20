//
//  palindrome_dynamic.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 4/12/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string palindrome_dynamic(string n,int s,int e,string **v)
{
    if(v[s][e]!="")
        return v[s][e];
    if(s<e)
    {
        if(n.at(s)==n.at(e))
        {
            v[s][e]=n.at(s)+palindrome_dynamic(n,s+1,e-1,v)+n.at(e);
            return v[s][e];
        }
        else
        {
            string n1=palindrome_dynamic(n,s+1,e,v);
            string n2=palindrome_dynamic(n,s,e-1,v);
            if(n1.length()>n2.length())
                return n1;
            return n2;
        }
    }
    else if(s==e)
        return n.substr(s,1);
    else
        return "";
}

int main()
{
    string n;
    cout<<"\n Input a string: ";
    cin>>n;
    string **v=new string*[(int)n.length()];
    for(int i=0;i<(int)n.length();i++)
    {
        v[i]=new string[(int)n.length()];
        v[i][i]=n.substr(i,1);
        //cout<<"\n\nLine "<<i<<":";
        //for(int j=0;j<(int)n.length();j++)
          //  cout<<"\n"<<v[i][j];
    }
    cout<<"\n Longest palindrome in the string: "<<palindrome_dynamic(n,0,(int)n.length()-1,v)<<endl;
    for(int i=0;i<(int)n.length();i++)
    {
        cout<<"\n\nLine "<<i<<":";
        for(int j=0;j<(int)n.length();j++)
          cout<<"\n"<<v[i][j];
        delete []v[i];
    }
    cout<<"\n";
    return 0;
}
