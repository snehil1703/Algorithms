#include<iostream>
#include<conio.h>

using namespace std;

void strassen(int **d,int **s,int **ds,int i1,int j1,int i2,int j2)
{
	if((i2-i1)>1 || (j2-j1)>1)
	{
		cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<i2/2<<" "<<j2/2<<"\n";
		strassen(d,s,ds,i1,j1,i2/2,j2/2);
		strassen(d,s,ds,(i2/2)+1,j1,i2,j2/2);
		strassen(d,s,ds,i1,(j2/2)+1,i2/2,j2);
		strassen(d,s,ds,(i2/2)+1,(j2/2)+1,i2,j2);
	}
	else
	{
		cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<"\n";
		int A,B,C,D,E,F,G,H,P[7];
		A=d[i1][j1];
		B=d[i1][j2];
		C=d[i2][j1];
		D=d[i2][j2];
		E=s[i1][j1];
		F=s[i1][j2];
		G=s[i2][j1];
		H=s[i2][j2];
		P[0]=A*(F-H); //3
		P[1]=(A+B)*H; //5
		P[2]=(C+D)*E; //2
		P[3]=D*(G-E); //4
		P[4]=(A+D)*(E+H); //1
		P[5]=(B-D)*(G+H);
		P[6]=(A-C)*(E+F);
		ds[i1][j1]=P[4]+P[3]-P[1]+P[5];
		ds[i1][j2]=P[0]+P[1];
		ds[i2][j1]=P[2]+P[3];
		ds[i2][j2]=P[0]+P[4]-P[2]-P[6];
	}
}
int main()
{
	int **d,**s,**ds,n,i,j,r;
	cin>>n;
	r=2;
	while(n>r)
		r=r*2;
	d=new int* [r];
	s=new int* [r];
	ds=new int* [r];
	for(i=0;i<r;i++)
	{
		d[i]=new int[r];
		j=0;
		while(j<r)
		{
			if(i<n)
			{
				if(j<n)
					cin>>d[i][j];
				else
					d[i][j]=0;
			}
			else
				d[i][j]=0;
			j++;
		}
	}
	for(i=0;i<r;i++)
	{
		s[i]=new int[r];
		ds[i]=new int[r];
		j=0;
		while(j<r)
		{
			ds[i][j]=0;
			if(i<n)
			{
				if(j<n)
					cin>>s[i][j];
				else
					s[i][j]=0;
			}
			else
				s[i][j]=0;
			j++;
		}
	}
	strassen(d,s,ds,0,0,r-1,r-1);
	cout<<"\n\n\n\n";
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<ds[i][j]<<" ";
	}
	for(i=0;i<r;i++)
	{
		delete []d[i];
		delete []s[i];
		delete []ds[i];
	}
    return 0;
}