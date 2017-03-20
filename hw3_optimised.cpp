//
//  hw3_optimised.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/9/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include<time.h>
#include <sys/time.h>

using namespace std;

struct matrix //2.1 - Data structure for matrix
{
    float **ns;
    int r,c;
};

void input(matrix &temp) //Prerequisite - INPUT values of a MATRIX (Row Major)
{
    cout<<"\n Enter the number of rows: ";
    cin>>temp.r;
    cout<<"\n Enter the number of columns: ";
    cin>>temp.c;
    temp.ns=new float*[temp.r];
    cout<<"\n Enter the Matrix values: ";
    for(int i=0;i<temp.r;i++)
    {
        temp.ns[i]=new float[temp.c];
        for(int j=0;j<temp.c;j++)
            cin>>temp.ns[i][j];
    }
}

void display(matrix &temp) //Additional - DISPLAY values of a MATRIX
{
    //cout<<"\n\n Number of rows and columns: "<<temp.r<<" "<<temp.c<<" respectively\n";
    for(int x=0;x<temp.r;x++)
    {
        cout<<"\n Row "<<(x+1)<<": ";
        for(int y=0;y<temp.c;y++)
            cout<<temp.ns[x][y]<<" ";
    }
}

matrix random_matrix(int ns) //2.2 - Generating a square matrix of random numbers
{
    matrix temp;
    temp.r=ns;
    temp.c=ns;
    temp.ns=new float*[temp.r];
    srand48(time(NULL));
    for(int i=0;i<temp.r;i++)
    {
        temp.ns[i]=new float[temp.c];
        for(int j=0;j<temp.c;j++)
            temp.ns[i][j]=static_cast <float>(rand()) / (static_cast <float>(RAND_MAX/55))*powf(-1,rand()%2);
    }
    return temp;
}

matrix standard(matrix n,matrix s) //2.3 - STANDARD matrix multiplication function
{
    matrix v;
    v.r=n.r;
    v.c=s.c;
    v.ns=new float*[v.r];
    for(int i=0;i<v.r;i++)
    {
        v.ns[i]=new float[v.c];
        for(int j=0;j<v.c;j++)
        {
            v.ns[i][j]=0;
            for(int k=0;k<n.c;k++) //LIMIT of this loop can even be "s.r"
                v.ns[i][j]+=(n.ns[i][k]*s.ns[k][j]);
        }
    }
    return v;
}

float **add(float **n,float **s,int y) //Function to add 2 matrices
{
    float **ns=new float*[y];
    for(int i=0;i<y;i++)
    {
        ns[i]=new float[y];
        for(int j=0;j<y;j++)
        {
            ns[i][j]=n[i][j]+s[i][j];
        }
    }
    return ns;
}

float **sub(float **n,float **s,int y) //Function to subtract one matrix from the other
{
    float **ns=new float*[y];
    for(int i=0;i<y;i++)
    {
        ns[i]=new float[y];
        for(int j=0;j<y;j++)
        {
            ns[i][j]=n[i][j]-s[i][j];
        }
    }
    return ns;
}

float **part(float **ns,int y,int begx,int begy) //Matrix partition function
{
    float **temp=new float*[y/2];
    for(int i=begx;i<((y/2)+begx);i++)
    {
        temp[i-begx]=new float[y/2];
        for(int j=begy;j<((y/2)+begy);j++)
        {
            temp[i-begx][j-begy]=ns[i][j];
        }
    }
    return temp;
}

float **divideandconquer(float **n,float **s,int y) //2.3 - DIVIDE & CONQUER matrix multiplication function
{
    float **vv;
    vv=new float*[y];
    for(int i=0;i<y;i++)
        vv[i]=new float[y];
    if(y==1)
        vv[0][0]=n[0][0]*s[0][0];
    else
    {
        float **n00,**n01,**n10,**n11,**s00,**s01,**s10,**s11,**ns00,**ns01,**ns10,**ns11;
        n00=part(n,y,0,0);
        n01=part(n,y,0,y/2);
        n10=part(n,y,y/2,0);
        n11=part(n,y,y/2,y/2);
        s00=part(s,y,0,0);
        s01=part(s,y,0,y/2);
        s10=part(s,y,y/2,0);
        s11=part(s,y,y/2,y/2);
        ns00=add(divideandconquer(n00,s00,y/2),divideandconquer(n01,s10,y/2),y/2);
        ns01=add(divideandconquer(n00,s01,y/2),divideandconquer(n01,s11,y/2),y/2);
        ns10=add(divideandconquer(n10,s00,y/2),divideandconquer(n11,s10,y/2),y/2);
        ns11=add(divideandconquer(n10,s01,y/2),divideandconquer(n11,s11,y/2),y/2);
        for(int i=0;i<(y/2);i++)
        {
            for(int j=0;j<(y/2);j++)
            {
                vv[i][j]=ns00[i][j];
                vv[i][j+(y/2)]=ns01[i][j];
                vv[i+(y/2)][j]=ns10[i][j];
                vv[i+(y/2)][j+(y/2)]=ns11[i][j];
            }
        }
    }
    return vv;
}

float **strassen(float **n,float **s,int y) //2.4 - STRASSEN matrix multiplication function
{
    float **sv;
    sv=new float*[y];
    for(int i=0;i<y;i++)
        sv[i]=new float[y];
    if(y==1)
        sv[0][0]=n[0][0]*s[0][0];
    else
    {
        float **n00,**n01,**n10,**n11,**s00,**s01,**s10,**s11;
        n00=part(n,y,0,0);
        n01=part(n,y,0,y/2);
        n10=part(n,y,y/2,0);
        n11=part(n,y,y/2,y/2);
        s00=part(s,y,0,0);
        s01=part(s,y,0,y/2);
        s10=part(s,y,y/2,0);
        s11=part(s,y,y/2,y/2);
        float **p1,**p2,**p3,**p4,**p5,**p6,**p7;
        p1=strassen(n00,sub(s01,s11,y/2),y/2);
        p2=strassen(add(n00,n01,y/2),s11,y/2);
        p3=strassen(add(n10,n11,y/2),s00,y/2);
        p4=strassen(n11,sub(s10,s00,y/2),y/2);
        p5=strassen(add(n00,n11,y/2),add(s00,s11,y/2),y/2);
        p6=strassen(sub(n01,n11,y/2),add(s10,s11,y/2),y/2);
        p7=strassen(sub(n00,n10,y/2),add(s00,s01,y/2),y/2);
        for(int i=0;i<(y/2);i++)
        {
            for(int j=0;j<(y/2);j++)
            {
                sv[i][j]=p5[i][j]+p4[i][j]-p2[i][j]+p6[i][j];
                sv[i][j+(y/2)]=p1[i][j]+p2[i][j];
                sv[i+(y/2)][j]=p3[i][j]+p4[i][j];
                sv[i+(y/2)][j+(y/2)]=p5[i][j]+p1[i][j]-p3[i][j]-p7[i][j];
            }
        }
    }
    return sv;
}

int main() //MAIN function
{
    struct timeval tvbeg,tvend;
    double standard_diff,divideconquer_diff,strassen_diff;
    matrix n,s;
    //cout<<"\n Input Matrix 1";
    //input(n);
    //cout<<"\n\n Input Matrix 2";
    //input(s);
    
    int sn;
    cout<<"\n Enter the size of your matrices: ";
    cin>>sn;
    n=random_matrix(sn);
    s=random_matrix(sn);
    
    cout<<"\n\n Matrix 1";
    //display(n);
    cout<<"\n\n Matrix 2";
    //display(s);
    
    if(n.c==s.r)
    {
        //STANDARD call
        
        gettimeofday(&tvbeg,NULL);
        matrix nv=standard(n,s);
        gettimeofday(&tvend,NULL);
        
        standard_diff=((double)(tvend.tv_sec)*1000+(double)(tvend.tv_usec)/1000)-((double)(tvbeg.tv_sec)*1000+(double)(tvbeg.tv_usec)/1000);
        cout<<"\n\n Resultant matrix after STANDARD matrix multiplication: ";
        //display(nv);
        cout<<"\n Time taken: "<<standard_diff<<" mSec";
        
        // (2 parts) DIVIDE & CONQUER and STRASSEN
        
        matrix n1,s1,vv,sv;
        int x,y,i,j;
        
        if(n.r>s.c)
            x=n.r;
        else
            x=s.c;
        y=2;
        while(y<x)
            y=y*2;
        
        n1.r=y;
        n1.c=y;
        n1.ns=new float*[y];
        s1.r=y;
        s1.c=y;
        s1.ns=new float*[y];
        vv.r=y;
        vv.c=y;
        vv.ns=new float*[y];
        sv.r=y;
        sv.c=y;
        sv.ns=new float*[y];
        
        for(i=0;i<y;i++)
        {
            n1.ns[i]=new float[y];
            s1.ns[i]=new float[y];
            vv.ns[i]=new float[y];
            sv.ns[i]=new float[y];
            j=0;
            while(j<y)
            {
                if(i<n.r)
                {
                    if(j<n.c)
                        n1.ns[i][j]=n.ns[i][j];
                    else
                        n1.ns[i][j]=0;
                }
                else
                    n1.ns[i][j]=0;
                if(i<s.r)
                {
                    if(j<s.c)
                        s1.ns[i][j]=s.ns[i][j];
                    else
                        s1.ns[i][j]=0;
                }
                else
                    s1.ns[i][j]=0;
                j++;
            }
        }
        
        //DIVIDE and CONQUER call
        
        gettimeofday(&tvbeg,NULL);
        vv.ns=divideandconquer(n1.ns,s1.ns,y);
        gettimeofday(&tvend,NULL);
        
        vv.r=n.r;
        vv.c=s.c;
        divideconquer_diff=((double)(tvend.tv_sec)*1000+(double)(tvend.tv_usec)/1000)-((double)(tvbeg.tv_sec)*1000+(double)(tvbeg.tv_usec)/1000);
        cout<<"\n\n Resultant matrix after DIVIDE and CONQUER matrix multiplication: ";
        //display(vv);
        cout<<"\n Time taken: "<<divideconquer_diff<<" mSec";
        
        //STRASSEN call
        
        gettimeofday(&tvbeg,NULL);
        sv.ns=strassen(n1.ns,s1.ns,y);
        gettimeofday(&tvend,NULL);
        
        sv.r=n.r;
        sv.c=s.c;
        strassen_diff=((double)(tvend.tv_sec)*1000+(double)(tvend.tv_usec)/1000)-((double)(tvbeg.tv_sec)*1000+(double)(tvbeg.tv_usec)/1000);
        cout<<"\n\n Resultant matrix after STRASSEN matrix multiplication: ";
        //display(sv);
        cout<<"\n Time taken: "<<strassen_diff<<" mSec";
    }
    else
        cout<<"\n\n CANNOT multiply the 2 matrices!";
    cout<<endl<<endl;
    return 0;
}
