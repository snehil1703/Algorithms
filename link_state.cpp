//
//  link_state.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 4/19/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

vector <string> src;
vector <vector <string> > des;
vector <vector <double> > cost;

void print_data()
{
    for(int i=0;i<src.size();i++)
    {
        cout<<"\n src: "<<src[i];
        cout<<" des & cost: ";
        for(int j=0;j<des[i].size();j++)
            cout<<des[i][j]<<","<<cost[i][j]<<" ";
    }
}

void add_data(string beg,string end,int val)
{
    int i;
    for(i=0;i<src.size();i++)
    {
        if(beg.compare(src[i])==0)
            break;
    }
    if(i==src.size())
    {
        src.push_back(beg);
        vector <string> t1(1,end);
        vector <double> t2(1,val);
        des.push_back(t1);
        cost.push_back(t2);
    }
    else
    {
        int j;
        for(j=0;j<des[i].size();j++)
        {
            if(end.compare(des[i][j])==0)
                break;
        }
        if(j==des[i].size())
        {
            des[i].push_back(end);
            cost[i].push_back(val);
        }
        else
        {
            if(val<cost[i][j])
                val=cost[i][j];
        }
    }
}

/*
Input File format: source_node destination_node cost
Graph is undirected
*/
void input(string file_path)
{
    ifstream in;
    in.open(file_path);
    if(in.is_open())
    {
        string beg,end,temp;
        double val;
        while(!in.eof())
        {
            getline(in, beg, ' ');
            getline(in, end, ' ');
            getline(in, temp, '\n');
            val=stod(temp);
            add_data(beg,end,val);
            add_data(end,beg,val);
        }
        //print_data();
    }
    else
    {
        cout<<"\n Error opening file! Invalid path/file name\n";
        exit(0);
    }
    in.close();
}

vector<string> node;
vector<string> prev_node;
vector<double> fcost;

void link_state(int pos)
{

}

int main()
{
    cout<<"\n Input the path of the file: ";
    string file_path;
    getline(cin,file_path);
    input(file_path);
    cout<<"\n Enter source node: ";
    string s;
    getline(cin,s);
    int i;
    for(i=0;i<src.size();i++)
    {
        if(s.compare(src[i])==0)
            break;
    }
    if(i==src.size())
        cout<<"\n\n No such SOURCE NODE named '"<<s<<"' exists!\n";
    else
    {
        node.push_back(src[i]);
        prev_node.push_back(src[i]);
        fcost.push_back(0);
        for(int j=0;j<des[i].size();j++)
        {
            node.push_back(des[i][j]);
            prev_node.push_back(src[i]);
            fcost.push_back(cost[i][j]);
        }
        link_state(1);
    }
    cout<<"\n";
    return 0;
}