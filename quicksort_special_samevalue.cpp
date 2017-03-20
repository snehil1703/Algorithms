//
//  quicksort_special_samevalue.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/17/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
 int part(vector <int> &A,int p,int r)
 {
 int x=A[r],i=p-1,k;
 cout<<"\n PART! p: "<<p<<" r: "<<r<<" x: "<<x;
 for(int j=p;j<r;j++)
 {
 cout<<"\n j: "<<j<<" i: "<<i;
 if(A[j]<=x)
 {
 i++;
 k=A[i];
 A[i]=A[j];
 A[j]=k;
 }
 
 }
 k=A[i+1];
 A[i+1]=A[r];
 A[r]=k;
 return (i+1);
 }
 */
int part(vector <int> &A,int p,int r)
{
    int x=A[r],i=p-1,k;
    int counter=0;
    //cout<<"\n PART! p: "<<p<<" r: "<<r<<" x: "<<x;
    for(int j=p;j<r;j++)
    {
        //cout<<"\n j: "<<j<<" i: "<<i;
        if(A[j]<x)
        {
            i++;
            k=A[i];
            A[i]=A[j];
            A[j]=k;
        }
        else if(A[j]==x)
        {
            i++;
            counter++;
        }
        
    }
    k=A[i+1];
    A[i+1]=A[r];
    A[r]=k;
    if(counter==(r-p))
        return ((p+r)/2);
    else
        return (i+1);
}

void quicksort(vector <int> &A,int p,int r)
{
    if(p<r)
    {
        int q=part(A,p,r);
        cout<<"\n QUICK RECUR! p: "<<p<<" r: "<<r<<" q: "<<q;
        char ch=getchar();
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
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
