//
//  palin_dyna_opt.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 4/12/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string palindrome_dynamic(string n,int s,int e,string *v)
{
    cout<<"\n\n STRING: "<<n.substr(s,e-s+1);
    
    if(s<e)
    {
        if(n.at(s)==n.at(e))
        {
            string temp=n.at(s)+palindrome_dynamic(n,s+1,e-1,v)+n.at(e);
            if(temp.length()>v[s].length())
                v[s]=temp;
            cout<<"\n SAME: "<<v[s];
            return v[s];
        }
        else
        {
            string temp1=palindrome_dynamic(n,s,e-1,v);
            cout<<"\n"<<temp1;
            string temp2=palindrome_dynamic(n,s+1,e,v);
            cout<<"\n"<<temp2;
            if(temp1.length()>temp2.length())
                return temp1;
            return temp2;
        }
    }
    else if(s==e && v[s]!="")
        return v[s];
    else if(s==e)
    {
        v[s]=n.substr(s,1);
        cout<<"\n EQUAL: "<<v[s];
        return v[s];
    }
    else
        return "";
}

int main()
{
    string n;
    cout<<"\n Input a string: ";
    cin>>n;
    string *v=new string[(int)n.length()];
    cout<<"\n Longest palindrome in the string: "<<palindrome_dynamic(n,0,(int)n.length()-1,v)<<endl;
    //for(int i=0;i<(int)n.length();i++)
      //  cout<<"\nLine "<<i<<": "<<v[i];
    delete []v;
    cout<<"\n";
    return 0;
}
