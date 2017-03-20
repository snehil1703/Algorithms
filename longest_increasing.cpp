//
//  longest_increasing.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/4/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector <int> > temp2d;
vector<bool> temp;

int maxval=-1,maxpos=-1;

int permute(int j,int tcount,bool &chk)
{
    int i,x=j,y,k,l=0;
    
    while(l<temp2d[j].size())
    {
        cout<<"\n\n j: "<<j<<" l: "<<l;
        k=temp2d[j][l];
        cout<<"\n k: "<<k;
        if(k==j)
        {
            if(maxval<tcount)
            {
                maxval=tcount;
                for(i=0;i<temp.size();i++)
                    temp[i]=false;
                temp[k]=true;
            }
            break;
        }
        y=permute(k,tcount+1,chk);
        if(chk)
        {
            temp[j]=true;
            chk=false;
        }
        if(y<x)
            x=y;
        l++;
    }
    return x;
}
int main()
{
    vector<int> ns;
    int n,s,i,j,count=0;
    bool z=false;
    cout<<"\n Enter size of the array: ";
    cin>>n;
    temp2d.resize(n);
    cout<<"\n Enter the array: ";
    while(n>0)
    {
        cin>>s;
        ns.push_back(s);
        temp.push_back(false);
        n--;
    }
    n=(int)ns.size();
    temp2d[0].push_back(count);
    maxval=1;
    maxpos=0;
    for(i=1;i<n;i++)
    {
        j=i-1;
        while(j>=0)
        {
            if(ns[j]<=ns[i])
            {
                temp2d[i].push_back(j);
 /*             
                do
                {
                    k=(int)temp2d[j].size()-1;
                    if(temp2d[j][k]==j)
                        break;
                    j=temp2d[j][k];
                }while(1);
   */
                cout<<"\n\n Permuting position: "<<i;
                j=permute(j,1,z);
            }
            j--;
        }
        if(temp2d[i].size()==0)
        {
            count++;
            temp2d[i].push_back(count);
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<"\n "<<ns[i]<<": ";
        for(j=0;j<temp2d[i].size();j++)
            cout<<temp2d[i][j]<<" ";
    }
    cout<<"\n\n";
    for(i=0;i<temp.size();i++)
        cout<<temp[i]<<" ";
    cout<<"\n";
    return 0;
}