//
//  segregate_binary.cpp
//  Trees
//
//  Created by Snehil Vishwakarma on 12/2/15.
//  Copyright © 2015 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int *ns;
    int n,s,n1,s1;
    cout<<"\n Enter size: ";
    cin>>n;
    ns=new int(n);
    cout<<"\n Enter array elements: ";
    for(s=0;s<n;s++)
        cin>>ns[s];
    s=0;
    n1=n;
    n=n-1;
    while(s<n)
    {
        while(ns[s]==0)
            s++;
        while(ns[n]==1)
            n--;
        if(s<n)
        {
            s1=ns[n];
            ns[n]=ns[s];
            ns[s]=s1;
        }
        s++;
        n--;
    }
    cout<<"\n";
    for(s=0;s<n1;s++)
        cout<<ns[s]<<" ";
    delete []ns;
    return 0;
}