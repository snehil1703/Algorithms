//
//  strassen.cpp
//  Algo - Sem 1
//
//  Created by Snehil Vishwakarma on 12/9/15.
//  Copyright © 2015 Indiana University Bloomington. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long int N,lol;
int K;
vector<int> n;
vector<int> s;
int cntr=0,tot=0;

long int fact (int temp)
{
    if(temp>0)
        return temp* (fact(temp-1));
    return 1;
}

void tower(int ct,long int sum)
{
    if(ct<K && sum<N)
    {
        s[ct]++;
        sum+=n[ct];
        tot++;
        if(sum==N)
        {
            int j;
            lol=fact(tot);
            for(j=0;j<K;j++)
            {
                if(s[j]>1)
                    lol=lol/(fact(s[j]));
            }
            cntr+=lol;
        }
        if(sum<N)
        {
            tower(ct,sum);
            tower(ct+1,sum);
            
        }
        s[ct]--;
        sum-=n[ct];
        tot--;
        if(s[ct]==0)
            tower(ct+1,sum);
    }
}

int main()
{
    int x,y,z;
    cin>>N>>K;
    for(x=0;x<K;x++)
    {
        cin>>y;
        for(z=0;z<n.size();z++)
        {
            if(n[z]<y)
                break;
        }
        n.insert(n.begin()+z,y);
        s.insert(s.begin()+z,0);
    }
    tower(0,0);
    cout<<"\n Time taken: "<<(cntr*2);
    cout<<"\n";
    return 0;
}


