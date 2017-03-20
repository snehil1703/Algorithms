//
//  palin_dyna_best.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 4/11/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string palindrome_dynamic(string n,int s,int e,string **v) //Top - down Dynamic Programming
{
    if(v[s][e]!="" && s<=e) //Memoization
        return v[s][e];
    if(s<e) //If not found in Auxillary, then recurse
    {
        if(n.at(s)==n.at(e))
        {
            v[s][e]=n.at(s)+palindrome_dynamic(n,s+1,e-1,v)+n.at(e);    //Found part of palindrome, so recurse
            return v[s][e];
        }
        else
        {
            v[s][e-1]=palindrome_dynamic(n,s,e-1,v);    //Multiple Recursion part 1
            v[s+1][e]=palindrome_dynamic(n,s+1,e,v);    //Multiple Recursion part 2
            if(v[s][e-1].length()>v[s+1][e].length())   //Accept the bigger palindrome in length
                return v[s][e-1];
            return v[s+1][e];
        }
    }
    else if(s==e)   //If not found in Auxillary, then record
    {
        v[s][e]=n.at(s);
        return v[s][e];
    }
    return "";      //Out of temporary bound, return null
}

string palindrome_max(string n)
{
    string **v=new string*[(int)n.length()]; //Auxillary Storage
    for(int i=0;i<(int)n.length();i++)
    {
        v[i]=new string[(int)n.length()];
    }
    string ans=palindrome_dynamic(n,0,(int)n.length()-1,v);
    for(int i=0;i<(int)n.length();i++)
        delete []v[i];
    return ans;
}

int main()
{
    string n;
    cout<<"\n Input a string: ";
    cin>>n;
    cout<<"\n Longest palindrome in the string: "<<palindrome_max(n)<<endl;
    cout<<"\n";
    return 0;
}
