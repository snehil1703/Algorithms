//
//  2.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/1/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void merge(int *s,int low,int mid,int high)
{
    int *c=new int(high-low+1);
    int x=0,i=low,j=mid+1,k=high;
    while(i<=mid && j<=high)
    {
        if(s[i]<s[j])
        {
            c[x]=s[i];
            x++;
            i++;
        }
        else
        {
            c[x]=s[j];
            x++;
            j++;
        }
    }
    while(i<=mid)
    {
        c[x]=s[i];
        x++;
        i++;
    }
    while(j<=high)
    {
        c[x]=s[j];
        x++;
        j++;
    }
    cout<<"\n\n";
    for(i=low;i<=high;i++)
    {
        //cout<<c[i-low]<<" ";
        s[i]=c[i-low];
        cout<<s[i]<<" ";
    }
    delete []c;
}


void mergesort(int *s,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        cout<<"\nlow: "<<low<<" mid: "<<mid<<" high: "<<high;
        mergesort(s,low,mid);
        mergesort(s,mid+1,high);
        merge(s,low,mid,high);
    }
}

int main()
{
    int n,x,i;
    bool chk=false;
    cout<<"\n Enter size of the set: ";
    cin>>n;
    int *s=new int(n);
    cout<<"\n Enter the set elements: ";
    for(i=0;i<n;i++)
        cin>>s[i];
    cout<<"\n Enter the integer 'x': ";
    cin>>x;
    mergesort(s,0,n-1);
    
    int j=n-1;
    for(i=0;i<n;i++)
        cout<<s[i]<<" ";
    i=0;
    while(i<j)
    {
        cout<<"\n"<<s[i]<<" "<<s[j];
        if(s[i]+s[j]==x)
        {
            chk=true;
            cout<<"\n\n YO! ";
            break;
        }
        else if(s[i]+s[j]<x)
            i++;
        else
            j--;
    }
    if(chk)
        cout<<"\n YES \n";
    else
        cout<<"\n NO \n";
    delete []s;
    return 0;
}

//Describe a O(n lg n)-time algorithm that, given a set S of n integers and another integer x, determines whether or not there exist two elements in S whose sum is exactly x.
