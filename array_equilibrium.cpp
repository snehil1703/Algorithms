//
//  array_equilibrium.cpp
//  Trees
//
//  Created by Snehil Vishwakarma on 11/21/15.
//  Copyright © 2015 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc,char * argv[])
{
    int n,i,j=0,k=0;
    cout<<"\n Enter the array size: ";
    cin>>n;
    int *s=new int[n];
    cout<<"\n Enter the elements: ";
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        j+=s[i];
    }
    if(j%2==1)
        cout<<"\n NO EQUILIBRIUM POINT voila!\n";
    else
    {
        j=j/2;
        for(i=0;i<n;i++)
        {
            k+=s[i];
            if(k!=j)
            {
            }
            else
            {
                break;
            }
        }
        if(i==n)
            cout<<"\n NO EQUILIBRIUM POINT!\n";
        else
        {
            cout<<"\n Equilibrium point exists! \n";
            for(k=0;k<=i;k++)
                cout<<s[k]<<" ";
            cout<<"\nAND\n";
            for(;k<n;k++)
                cout<<s[k]<<" ";
        }
    }
    cout<<"\n";
    delete []s;
    return 0;
}


