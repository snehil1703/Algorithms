//
//  quicksort_random_q_t.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/17/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct qt
{
    int q,t;
};

qt part_custom(vector <int> &A,int p,int r)
{
    qt temp;
    
    int x=A[r],i=p-1,k;
    for(int j=p;j<r;j++)
    {
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
        while(A[beg]<A[i])
            beg++;
        while(A[end]==A[i])
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
    cout<<"\n Array currently: ";
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    
    return temp;
}

qt randomized_partition_custom(vector <int> &A,int p,int r)
{
    int i,k;
    i=rand()%(r-p+1)+p;
    k=A[r];
    A[r]=A[i];
    A[i]=k;
    cout<<"\n New 'r': "<<i;
    cout<<"\n Element at the END: "<<A[r];
    return part_custom(A,p,r);
}

void randomized_quicksort_custom(vector <int> &A,int p,int r)
{
    if(p<r)
    {
        cout<<"\n\n Array currently: ";
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";
        cout<<"\n p: "<<p<<" r: "<<r;
        qt temp=randomized_partition_custom(A,p,r);
        cout<<"\n\n RECURSION: p: "<<p<<" r: "<<r<<" q: "<<temp.q<<" t: "<<temp.t;
        randomized_quicksort_custom(A,p,(temp.q)-1);
        randomized_quicksort_custom(A,(temp.t)+1,r);
    }
}

int main()
{
    srand(time(NULL));
    vector <int> A;
    int n,s;
    cout<<"\n Enter size: ";
    cin>>s;
    cout<<"\n Enter the array: ";
    for(int i=0;i<s;i++)
    {
        cin>>n;
        A.push_back(n);
    }
    randomized_quicksort_custom(A,0,s-1);
    cout<<"\n\n";
    for(int i=0;i<200;i++)
        cout<<"-";
    cout<<"\n\n SORTED Array in ASCENDING Order: ";
    for(int i=0;i<s;i++)
        cout<<A[i]<<" ";
    cout<<endl<<endl;
    return 0;
}