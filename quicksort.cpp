//
//  quicksort.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/17/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct qt
{
    int q,t;
};

qt part(vector <int> &A,int p,int r)
{
    qt temp;
    
    int x=A[r],i=p-1,k;
    cout<<"\n PART! p: "<<p<<" r: "<<r;
    for(int j=p;j<r;j++)
    {
        //cout<<"\n j: "<<j<<" i: "<<i;
        if(A[j]<=x)
        {
            i++;
            k=A[i];
            A[i]=A[j];
            A[j]=k;
        }
    }
    i++;
    k=A[i];
    A[i]=A[r];
    A[r]=k;
    
    k=p;
    int beg=p,end=i-1;
    while(beg<end)
    {
        while(A[beg]<x)
            beg++;
        while(A[end]==x)
            end--;
        k=end+1;
        if(beg<end)
        {
            k=A[beg];
            A[beg]=A[end];
            A[end]=k;
            k=end;
        }
        beg++;
        end--;
    }
    
    temp.q=k;
    temp.t=i;
    
    cout<<"\n q: "<<temp.q<<" t: "<<temp.t;
    cout<<"\n Corrected Array: ";
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    
    return temp;
}

void quicksort(vector <int> &A,int p,int r)
{
    if(p<r)
    {
        cout<<"\n\n Array: ";
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";
        qt temp=part(A,p,r);
        //cout<<"\n QUICK RECUR! p: "<<p<<" r: "<<r<<" q: "<<q;
        char ch=getchar();
        quicksort(A,p,(temp.q)-1);
        quicksort(A,(temp.t)+1,r);
    }
}

int main()
{
    vector <int> A;
    int n,s;
    cout<<"\n Enter size: ";
    cin>>s;
    for(int i=0;i<s;i++)
    {
        cin>>n;
        A.push_back(n);
    }
    quicksort(A,0,s-1);
    cout<<"\n\n Sorted Array: ";
    for(int i=0;i<s;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}