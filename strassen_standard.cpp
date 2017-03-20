//
//  strassen_standard.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/8/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct matrix //2.1 - Data structure for matrix
{
    float *ns;
    int r,c;
};

void input(matrix &temp) //Prerequisite - INPUT values of a MATRIX (Row Major)
{
    cout<<"\n Enter the number of rows: ";
    cin>>temp.r;
    cout<<"\n Enter the number of columns: ";
    cin>>temp.c;
    temp.ns=new float[temp.r*temp.c];
    cout<<"\n Enter the Matrix values: ";
    for(int i=0;i<temp.r;i++)
    {
        for(int j=0;j<temp.c;j++)
            cin>>temp.ns[(i*temp.c)+j];
    }
}

void display(matrix temp) //Additional - DISPLAY values of a MATRIX
{
    cout<<"\n\n Number of rows and columns: "<<temp.r<<" "<<temp.c<<" respectively\n";
    for(int i=0;i<temp.r;i++)
    {
        cout<<"\n Row "<<(i+1)<<": ";
        for(int j=0;j<temp.c;j++)
            cout<<temp.ns[(i*temp.c)+j]<<" ";
    }
}

matrix random_matrix(int ns) //2.2 - Generating a square matrix of random numbers
{
    matrix temp;
    temp.r=ns;
    temp.c=ns;
    temp.ns=new float[temp.r*temp.c];
    srand48(time(NULL));
    for(int i=0;i<temp.r;i++)
    {
        for(int j=0;j<temp.c;j++)
            temp.ns[(i*temp.c)+j]=rand();
    }
    return temp;
}

matrix standard(matrix n,matrix s) //2.3 - STANDARD matrix multiplication function
{
    matrix v;
    v.r=n.r;
    v.c=s.c;
    v.ns=new float[v.r*v.c];
    for(int i=0;i<v.r;i++)
    {
        for(int j=0;j<v.c;j++)
        {
            v.ns[(i*v.c)+j]=0;
            for(int k=0;k<n.c;k++) //LIMIT of this loop can even be "s.r"
                v.ns[(i*v.c)+j]+=((n.ns[(i*n.c)+k])*(s.ns[j+(k*s.c)]));
        }
    }
    return v;
}
void add(matrix n1,matrix s1,matrix &vv,int i1,int j1,int i2,int j2)
{
    display(n1);
    display(s1);
    for(int x=i1,u=0;x<=i2;x++,u++)
    {
        for(int y=j1,v=0;y<=j2;y++,v++)
        {
            cout<<"\n"<<n1.ns[(u*n1.c)+v]<<" "<<s1.ns[(u*s1.c)+v];
            vv.ns[(x*vv.c)+y]=n1.ns[(u*n1.c)+v]+s1.ns[(u*s1.c)+v];
            cout<<" "<<vv.ns[(x*vv.c)+y];
        }
    }
    display(vv);
}
matrix divideandconquer(matrix &n,matrix &s,int i1,int j1,int i2,int j2,int x1,int y1,int x2,int y2) //2.3 - DIVIDE & CONQUER matrix multiplication function
{
    matrix vv;
    vv.r=(i2-i1)+1;
    vv.c=(j2-j1)+1;
    vv.ns=new float[vv.r*vv.c];
    
    if((i2-i1)>=1 || (j2-j1)>=1)
    {
        cout<<"\n IF:"<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
        int imid=(i1+i2)/2;
        int jmid=(j1+j2)/2;
        int xmid=(x1+x2)/2;
        int ymid=(y1+y2)/2;
        add(divideandconquer(n,s,i1,j1,imid,jmid,x1,y1,xmid,ymid),divideandconquer(n,s,i1,jmid+1,imid,j2,xmid+1,y1,x2,ymid),vv,i1,j1,imid,jmid);
        add(divideandconquer(n,s,i1,j1,imid,jmid,x1,ymid+1,xmid,y2),divideandconquer(n,s,i1,jmid+1,imid,j2,xmid+1,ymid+1,x2,y2),vv,i1,jmid+1,imid,j2);
        add(divideandconquer(n,s,imid+1,j1,i2,jmid,x1,y1,xmid,ymid),divideandconquer(n,s,imid+1,jmid+1,i2,j2,xmid+1,y1,x2,ymid),vv,imid+1,j1,i2,jmid);
        add(divideandconquer(n,s,imid+1,j1,i2,jmid,x1,ymid+1,xmid,y2),divideandconquer(n,s,imid+1,jmid+1,i2,j2,xmid+1,ymid+1,x2,y2),vv,imid+1,jmid+1,i2,j2);
        //add(divideandconquer(n,s,i1,j1,(i2+1)/2,(j2+1)/2,x1,y1,(x2+1)/2,(y2+1)/2),divideandconquer(n,s,i1,((j2+1)/2)+1,(i2+1)/2,j2,((x2+1)/2)+1,y1,x2,(y2+1)/2),vv,i1,j1,i2/2,j2/2);
        //add(divideandconquer(n,s,i1,j1,(i2+1)/2,(j2+1)/2,x1,((y2+1)/2)+1,(x2+1)/2,y2),divideandconquer(n,s,i1,((j2+1)/2)+1,(i2+1)/2,j2,((x2+1)/2)+1,((y2+1)/2)+1,x2,y2),vv,i1,(j2/2)+1,i2/2,j2);
        //add(divideandconquer(n,s,((i2+1)/2)+1,j1,i2,(j2+1)/2,x1,y1,(x2+1)/2,(y2+1)/2),divideandconquer(n,s,((i2+1)/2)+1,((j2+1)/2)+1,i2,j2,((x2+1)/2)+1,y1,x2,(y2+1)/2),vv,(i2/2)+1,j1,i2,j2/2);
        //add(divideandconquer(n,s,((i2+1)/2)+1,j1,i2,(j2+1)/2,x1,((y2+1)/2)+1,(x2+1)/2,y2),divideandconquer(n,s,((i2+1)/2)+1,((j2+1)/2)+1,i2,j2,((x2+1)/2)+1,((y2+1)/2)+1,x2,y2),vv,(i2/2)+1,(j2/2)+1,i2,j2);
        //add(divideandconquer(n,s,i1,j1,i2/2,j2/2,x1,y1,x2/2,y2/2),divideandconquer(n,s,i1,(j2/2)+1,i2/2,j2,(x2/2)+1,y1,x2,y2/2),vv,i1,j1,i2/2,j2/2);
        //add(divideandconquer(n,s,i1,j1,i2/2,j2/2,x1,(y2/2)+1,x2/2,y2),divideandconquer(n,s,i1,(j2/2)+1,i2/2,j2,(x2/2)+1,(y2/2)+1,x2,y2),vv,i1,(j2/2)+1,i2/2,j2);
        //add(divideandconquer(n,s,(i2/2)+1,j1,i2,j2/2,x1,y1,x2/2,y2/2),divideandconquer(n,s,(i2/2)+1,(j2/2)+1,i2,j2,(x2/2)+1,y1,x2,y2/2),vv,(i2/2)+1,j1,i2,j2/2);
        //add(divideandconquer(n,s,(i2/2)+1,j1,i2,j2/2,x1,(y2/2)+1,x2/2,y2),divideandconquer(n,s,(i2/2)+1,(j2/2)+1,i2,j2,(x2/2)+1,(y2/2)+1,x2,y2),vv,(i2/2)+1,(j2/2)+1,i2,j2);
        //divideandconquer(n,s,vv,i1,j1,i2/2,j2/2);
        //divideandconquer(n,s,vv,(i2/2)+1,j1,i2,j2/2);
        //divideandconquer(n,s,vv,i1,(j2/2)+1,i2/2,j2);
        //divideandconquer(n,s,vv,(i2/2)+1,(j2/2)+1,i2,j2);
    }
    else
    {
        cout<<"\n ELSE:"<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
        vv.ns[0]=n.ns[(i1*n.c)+j1]*s.ns[(x1*s.c)+y1];
        //int A,B,C,D,E,F,G,H;
        
        //A=n.ns[(i1*n.c)+j1];
        //B=n.ns[(i1*n.c)+j2];
        //C=n.ns[(i2*n.c)+j1];
        //D=n.ns[(i2*n.c)+j2];
        //E=s.ns[(i1*s.c)+j1];
        //F=s.ns[(i1*s.c)+j2];
        //G=s.ns[(i2*s.c)+j1];
        //H=s.ns[(i2*s.c)+j2];
        //vv.ns[(i1*vv.c)+j1]=(A*E)+(B*G);
        //vv.ns[(i1*vv.c)+j2]=(A*F)+(B*H);
        //vv.ns[(i2*vv.c)+j1]=(C*E)+(D*G);
        //vv.ns[(i2*vv.c)+j2]=(C*F)+(D*H);
    }
    return vv;
}
/*
void strassen(matrix &n,matrix &s,matrix &sv,int i1,int j1,int i2,int j2) //2.4 - STRASSEN matrix multiplication function
{
    if((i2-i1)>1 || (j2-j1)>1)
    {
        cout<<"\n"<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<i2/2<<" "<<j2/2<<"\n";
        strassen(n,s,sv,i1,j1,i2/2,j2/2);
        strassen(n,s,sv,(i2/2)+1,j1,i2,j2/2);
        strassen(n,s,sv,i1,(j2/2)+1,i2/2,j2);
        strassen(n,s,sv,(i2/2)+1,(j2/2)+1,i2,j2);
    }
    else
    {
        cout<<"\n"<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<"\n";
        int A,B,C,D,E,F,G,H,P[7];
        
        A=n.ns[(i1*n.c)+j1];
        B=n.ns[(i1*n.c)+j2];
        C=n.ns[(i2*n.c)+j1];
        D=n.ns[(i2*n.c)+j2];
        E=s.ns[(i1*s.c)+j1];
        F=s.ns[(i1*s.c)+j2];
        G=s.ns[(i2*s.c)+j1];
        H=s.ns[(i2*s.c)+j2];
        P[0]=A*(F-H);
        P[1]=(A+B)*H;
        P[2]=(C+D)*E;
        P[3]=D*(G-E);
        P[4]=(A+D)*(E+H);
        P[5]=(B-D)*(G+H);
        P[6]=(A-C)*(E+F);
        sv.ns[(i1*sv.c)+j1]=P[4]+P[3]-P[1]+P[5];
        sv.ns[(i1*sv.c)+j2]=P[0]+P[1];
        sv.ns[(i2*sv.c)+j1]=P[2]+P[3];
        sv.ns[(i2*sv.c)+j2]=P[4]+P[0]-P[2]-P[6];
    }
}
*/
void strassen(matrix &n,matrix &s,matrix &sv,int i1,int j1,int i2,int j2) //2.4 - STRASSEN matrix multiplication function
{
    if((i2-i1)>1 || (j2-j1)>1)
    {
        cout<<"\n"<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<i2/2<<" "<<j2/2<<"\n";
        strassen(n,s,sv,i1,j1,i2/2,j2/2);
        strassen(n,s,sv,(i2/2)+1,j1,i2,j2/2);
        strassen(n,s,sv,i1,(j2/2)+1,i2/2,j2);
        strassen(n,s,sv,(i2/2)+1,(j2/2)+1,i2,j2);
    }
    else
    {
        cout<<"\n"<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<"\n";
        int A,B,C,D,E,F,G,H,P[7];
        
        A=n.ns[(i1*n.c)+j1];
        B=n.ns[(i1*n.c)+j2];
        C=n.ns[(i2*n.c)+j1];
        D=n.ns[(i2*n.c)+j2];
        E=s.ns[(i1*s.c)+j1];
        F=s.ns[(i1*s.c)+j2];
        G=s.ns[(i2*s.c)+j1];
        H=s.ns[(i2*s.c)+j2];
        P[0]=A*(F-H);
        P[1]=(A+B)*H;
        P[2]=(C+D)*E;
        P[3]=D*(G-E);
        P[4]=(A+D)*(E+H);
        P[5]=(B-D)*(G+H);
        P[6]=(A-C)*(E+F);
        sv.ns[(i1*sv.c)+j1]=P[4]+P[3]-P[1]+P[5];
        sv.ns[(i1*sv.c)+j2]=P[0]+P[1];
        sv.ns[(i2*sv.c)+j1]=P[2]+P[3];
        sv.ns[(i2*sv.c)+j2]=P[4]+P[0]-P[2]-P[6];
    }
}

int main() //MAIN function
{
    matrix n,s;
    cout<<"\n Input Matrix 1";
    //input(n);
    n.r=4;
    n.c=4;
    n.ns=new float[16];
    n.ns[0]=1;
    n.ns[1]=425;
    n.ns[2]=12;
    n.ns[3]=-23;
    n.ns[4]=1;
    n.ns[5]=42;
    n.ns[6]=7;
    n.ns[7]=9;
    n.ns[8]=8;
    n.ns[9]=2;
    n.ns[10]=13;
    n.ns[11]=-5;
    n.ns[12]=10;
    n.ns[13]=20;
    n.ns[14]=30;
    n.ns[15]=40;
    cout<<"\n\n Input Matrix 2";
    //input(s);
    s.r=4;
    s.c=4;
    s.ns=new float[16];
    s.ns[0]=3;
    s.ns[1]=-5;
    s.ns[2]=-7;
    s.ns[3]=19;
    s.ns[4]=0;
    s.ns[5]=91;
    s.ns[6]=57;
    s.ns[7]=16;
    s.ns[8]=12;
    s.ns[9]=32;
    s.ns[10]=43;
    s.ns[11]=-6;
    s.ns[12]=-7;
    s.ns[13]=-1;
    s.ns[14]=-3;
    s.ns[15]=0;
    //display(n);
    //display(s);
    if(n.c==s.r)
    {
        //STANDARD call
        matrix nv=standard(n,s);
        cout<<"\n\n Resultant matrix after STANDARD matrix multiplication: ";
        display(nv);
        
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
        n1.ns=new float[y*y];
        s1.r=y;
        s1.c=y;
        s1.ns=new float[y*y];
        //vv.r=y;
        //vv.c=y;
        //vv.ns=new float[y*y];
        //sv.r=y;
        //sv.c=y;
        //sv.ns=new float[y*y];
        
        for(i=0;i<y;i++)
        {
            j=0;
            while(j<y)
            {
                //vv.ns[(i*vv.c)+j]=0;
                //sv.ns[(i*sv.c)+j]=0;
                if(i<n.r)
                {
                    if(j<n.c)
                        n1.ns[(i*n1.c)+j]=n.ns[(i*n.c)+j];
                    else
                        n1.ns[(i*n1.c)+j]=0;
                }
                else
                    n1.ns[(i*n1.c)+j]=0;
                if(i<s.r)
                {
                    if(j<s.c)
                        s1.ns[(i*s1.c)+j]=s.ns[(i*s.c)+j];
                    else
                        s1.ns[(i*s1.c)+j]=0;
                }
                j++;
            }
        }
        
        display(n1);
        display(s1);
        
        //DIVIDE and CONQUER call
        
        vv=divideandconquer(n,s,0,0,y-1,y-1,0,0,y-1,y-1);
        cout<<"\n\n Resultant matrix after DIVIDE and CONQUER matrix multiplication: ";
        vv.r=n.r;
        vv.c=s.c;
        display(vv);
        
        //STRASSEN call
        
        //sv=strassen(n,s,0,0,y-1,y-1);
        //cout<<"\n\n Resultant matrix after STRASSEN matrix multiplication: ";
        //sv.r=n.r;
        //sv.c=s.c;
        //display(sv);
    }
    else
        cout<<"\n\n CANNOT multiply the 2 matrices!";
    cout<<endl;
    return 0;
}