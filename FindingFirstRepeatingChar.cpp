//
//  hackerrank_srishti.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 3/14/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string findFirstRepeatingChar(string s)
{
    string t="";
    int pos,temppos;
    pos=(int)s.length()+1;
    for(int i=0;i<s.length();i++)
    {
        if((int)(t.find_first_of(s[i]))==-1)
        {
            t.append(1,s[i]);
        }
        else
        {
            temppos=(int)(t.find_first_of(s[i]));
            if(temppos<pos)
                pos=temppos;
        }
    }
    if(pos==s.length()+1)
        return "0";
    else
    {
        string temp="";
        temp.append(1,t[pos]);
        return temp;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string res;
    string _s;
    getline(cin,_s);
    
    res=findFirstRepeatingChar(_s);
    
    cout<<res<<endl;
    return 0;
}