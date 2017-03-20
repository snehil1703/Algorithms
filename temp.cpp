//
//  temp.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 2/25/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include<iostream>
#include<conio>
#include<graphics.h>
#include<fstream.h>
#include<stdio.h>
#include<bios.h>
#include<ctype.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
char b[9][7]={" PawN "," RooK ","KnighT","BishoP",
    "QueeN "," KinG ","BishoP","KnighT"," RooK "};
int a[8][8],p,p2,player=1,count=0;
int Valid(int,int,int,int);
int Valid_Check_Move(int,int,int,int);
void Front_Page();
void Copyright();
void Instructions();
void Draw_Board();
int Position(float,float);
void Co_Ordinates(int,int,int &,int &);
int King_Check(int,int,int,int);
int King_Check_Move();
int King_Castle(int,int,int,int);
int King_Mate();
int main()
{
    if(count==0)
    {
        count++;
        Front_Page();
    }
    Draw_Board();
    int i,k=1,sx,sy,dx,dy,j,csx,csy,cdx,cdy,pa,l1,m1,l2,m2;
    char t[20],pc[7],pr[7];
    while(King_Mate()!=3)
    {
        setcolor(BLACK);
        for(i=1;i<=3;i++)
        {
            gotoxy(1,i);
            cout<<"                                 ";
        }
        for(i=3;i<=10;i++)
        {
            gotoxy(1,i);
            cout<<"              ";
        }
        gotoxy(1,1);
    z1:
        if(player==1)
        {
            setcolor(BLACK);
            outtextxy(50,5,"PLAYER 2 !!!");
            setcolor(GREEN);
            outtextxy(50,5,"PLAYER 1 !!!");
        }
        else
        {
            setcolor(BLACK);
            outtextxy(50,5,"PLAYER 1 !!!");
            setcolor(GREEN);
            outtextxy(50,5,"PLAYER 2 !!!");
        }
        setcolor(RED);
        gotoxy(1,1);
        outtextxy(1,15,"Input source coordinates : ");
        gotoxy(30,2);
        char ch;
        cin>>ch;
        sy=ch-64;
        cin>>ch;
        sx=ch-48;
        outtextxy(1,35,"Input destination coordinates : ");
        gotoxy(30,3);
        cin>>ch;
        dy=ch-64;
        cin>>ch;
        dx=ch-48;
        //cout<<sx<<sy<<dx<<dy;
        //getch();
        sx--;
        sy--;
        dx--;
        dy--;
        sx=7-sx;
        dx=7-dx;
        k=Valid(sx,sy,dx,dy);
        /*itoa(k,t,10);
         setcolor(GREEN);
         outtextxy(50,40,t);
         itoa(p,t,10);
         outtextxy(50,50,t);
         itoa(p2,t,10);
         outtextxy(150,50,t);
         getch();*/
        if(player==1)
        {
            if(p>=1 && p<=9)
                setcolor(WHITE);
            else
            {
                outtextxy(50,100,"It's Player 1's Chance...");
                goto z1;
            }
        }
        else if(player==2)
        {
            if(p>=10 && p<=18)
                setcolor(BLACK);
            else
            {
                outtextxy(50,100,"It's Player 2's Chance...");
                goto z1;
            }
        }
        if(k==2)
        {
            if(player==2)
            {
                if(dy==2)
                {
                    Co_Ordinates(0,4,l2,m2);
                    Co_Ordinates(0,0,l1,m1);
                    a[0][2]=a[0][4];
                    a[0][3]=a[0][0];
                    a[0][4]=0;
                    a[0][0]=0;
                    setcolor(LIGHTGRAY);
                    outtextxy(l2,m2,b[5]);
                    setcolor(LIGHTGRAY);
                    outtextxy(l1,m1,b[1]);
                    Co_Ordinates(0,3,l2,m2);
                    Co_Ordinates(0,2,l1,m1);
                    setcolor(BLACK);
                    outtextxy(l2,m2,b[1]);
                    outtextxy(l1,m1,b[5]);
                    player=1;
                }
                else if(dy==6)
                {
                    Co_Ordinates(0,4,l2,m2);
                    Co_Ordinates(0,7,l1,m1);
                    a[0][6]=a[0][4];
                    a[0][5]=a[0][7];
                    a[0][4]=0;
                    a[0][7]=0;
                    setcolor(LIGHTGRAY);
                    outtextxy(l2,m2,b[5]);
                    setcolor(DARKGRAY);
                    outtextxy(l1,m1,b[1]);
                    Co_Ordinates(0,6,l2,m2);
                    Co_Ordinates(0,5,l1,m1);
                    setcolor(BLACK);
                    outtextxy(l2,m2,b[5]);
                    outtextxy(l1,m1,b[1]);
                    player=1;
                }
            }
            else if(player==1)
            {
                if(dy==2)
                {
                    Co_Ordinates(7,4,l2,m2);
                    Co_Ordinates(7,0,l1,m1);
                    a[7][2]=a[7][4];
                    a[7][3]=a[7][0];
                    a[7][4]=0;
                    a[7][0]=0;
                    setcolor(DARKGRAY);
                    outtextxy(l2,m2,b[5]);
                    setcolor(DARKGRAY);
                    outtextxy(l1,m1,b[1]);
                    Co_Ordinates(7,3,l2,m2);
                    Co_Ordinates(7,2,l1,m1);
                    setcolor(WHITE);
                    outtextxy(l2,m2,b[1]);
                    outtextxy(l1,m1,b[5]);
                    player=2;
                }
                else if(dy==6)
                {
                    Co_Ordinates(7,4,l2,m2);
                    Co_Ordinates(7,7,l1,m1);
                    a[7][6]=a[7][4];
                    a[7][5]=a[7][7];
                    a[7][4]=0;
                    a[7][7]=0;
                    setcolor(DARKGRAY);
                    outtextxy(l2,m2,b[5]);
                    setcolor(LIGHTGRAY);
                    outtextxy(l1,m1,b[1]);
                    Co_Ordinates(7,6,l2,m2);
                    Co_Ordinates(7,5,l1,m1);
                    setcolor(WHITE);
                    outtextxy(l2,m2,b[5]);
                    outtextxy(l1,m1,b[1]);
                    player=2;
                }
            }
        }
        else if(k==1)
        {
            a[dx][dy]=a[sx][sy];
            a[sx][sy]=0;
            Co_Ordinates(sx,sy,csx,csy);
            Co_Ordinates(dx,dy,cdx,cdy);
            if(p==9 || p==10)
                strcpy(pc,b[0]);
            else if(p==1 || p==8 || p==11 || p==18)
                strcpy(pc,b[1]);
            else if(p==2 || p==7 || p==12 || p==17)
                strcpy(pc,b[2]);
            else if(p==3 || p==6 || p==13 || p==16)
                strcpy(pc,b[3]);
            else if(p==4 || p==14)
                strcpy(pc,b[4]);
            else if(p==5 || p==15)
                strcpy(pc,b[5]);
            if(p2==9 || p2==10)
                strcpy(pr,b[0]);
            else if(p2==1 || p2==8 || p2==11 || p2==18)
                strcpy(pr,b[1]);
            else if(p2==2 || p2==7 || p2==12 || p2==17)
                strcpy(pr,b[2]);
            else if(p2==3 || p2==6 || p2==13 || p2==16)
                strcpy(pr,b[3]);
            else if(p2==4 || p2==14)
                strcpy(pr,b[4]);
            else if(p2==5 || p2==15)
                strcpy(pr,b[5]);
            else if(p2==0)
                strcpy(pr,pc);
            if((sx+sy)%2==0)
            {
                setcolor(LIGHTGRAY);
                outtextxy(csx,csy,pc);
            }
            else
            {
                setcolor(DARKGRAY);
                outtextxy(csx,csy,pc);
            }
            if((dx+dy)%2==0)
            {
                setcolor(LIGHTGRAY);
                outtextxy(cdx,cdy,pr);
            }
            else
            {
                setcolor(DARKGRAY);
                outtextxy(cdx,cdy,pr);
            }
            if(player==2)
            {
                setcolor(BLACK);
                outtextxy(cdx,cdy,pc);
                player=1;
            }
            else
            {
                setcolor(WHITE);
                outtextxy(cdx,cdy,pc);
                player=2;
            }
        }
        else
        {
            cout<<" Invalid!!! ";
            getch();
        }
    }
    cout<<"Check And Mate!!! Player "<<player<<" Loses!!!";
    if(player==1)
        player=2;
    else if(player==2)
        player=1;
    cout<<"Player "<<player<<" Wins!!!";
    getch();
    cleardevice();
    closegraph();
    return 0;
}
int Valid(int sx, int sy, int dx, int dy)
{
    int sum=0,i,j,c=0;
    p=a[sx][sy];
    p2=a[dx][dy];
    if(King_Check_Move()==1)
    {
        if(p!=5 && p!=15)
            return -1;
        else
            return 1;
    }
    else if(p==p2)
        return -1;
    else if(p==0)
        return -1;
    else if(p==10)
    {
        if((dx-sx)>2 || (dy-sy)>1)
            return -1;
        else
        {
            if(dx==sx+1 && dy==sy && p2==0)
                return 1;
            else if(dx==sx+2 && dy==sy && sx==1 && p2==0 && a[dx-1][dy]==0)
                return 1;
            else if(dy==0)
            {
                if(dx==sx+1 && dy==sy-1 && (p2>=1 && p2<=9 && p2!=5))
                    return 1;
                else
                    return -1;
            }
            else if(dy==7)
            {
                if(dx==sx+1 && dy==sy+1 && (p2>=1 && p2<=9 && p2!=5))
                    return 1;
                else
                    return -1;
            }
            else if(dy!=0 && dy!=7)
            {
                if(dx==sx+1 && (dy==sy-1 || dy==sy+1) && (p2>=1 && p2<=9 && p2!=5))
                    return 1;
            }
            return -1;
        }
    }
    else if(p==9)
    {
        if(((sx-dx)>2) || ((sy-dy)>2))
            return -1;
        else
        {
            if(dx==sx-1 && dy==sy && p2==0)
                return 1;
            else if(dx==sx-2 && dy==sy && p2==0 && sx==6 && a[dx+1][dy]==0)
                return 1;
            else if(dy==0)
            {
                if(dx==sx-1 && dy==sy-1 && (p2>=10 && p2<=18 && p2!=15))
                    return 1;
                else
                    return -1;
            }
            else if(dy==7)
            {
                if(dx==sx-1 && dy==sy+1 && (p2>=10 && p2<=18 && p2!=15))
                    return 1;
                else
                    return -1;
            }
            else if(dy!=0 && dy!=7)
            {
                if(dx==sx-1 && (dy==sy-1 || dy==sy+1) && (p2>=10 && p2<=18 && p2!=15))
                    return 1;
            }
            return -1;
        }
    }
    else if(p==1 || p==8 || p==11 || p==18)
    {
        sum=0;
        c=0;
        if(dx==sx && dy>sy)
        {
            for(i=sy+1;i<dy;i++)
                sum+=a[dx][i];
            c=1;
        }
        else if(dx==sx && dy<sy)
        {
            for(i=sy-1;i>dy;i--)
                sum+=a[dx][i];
            c=1;
        }
        else if(dy==sy && dx>sx)
        {
            for(i=sx+1;i<dx;i++)
                sum+=a[i][dy];
            c=1;
        }
        else if(dy==sy && dx<sx)
        {
            for(i=sx-1;i>dx;i--)
                sum+=a[i][dy];
            c=1;
        }
        if(c==1)
        {
            if(p==1 || p==8)
            {
                if(sum==0 && ((p2>=10 && p2<=18 && p2!=15) || p2==0))
                    return 1;
                else
                    return -1;
            }
            else if(p==11 || p==18)
            {
                if(sum==0 && ((p2>=1 && p2<=9 && p2!=5) || p2==0))
                    return 1;
                else
                    return -1;
            }
        }
        else
            return -1;
    }
    else if(p==3 || p==6 || p==13 || p==16)
    {
        sum=0;
        c=0;
        if(dx>sx)
        {
            if(dy>sy)
            {
                if((dx-sx)==(dy-sy))
                {
                    for(i=sx+1,j=sy+1;i<dx;i++,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else
            {
                if((dx-sx)==(sy-dy))
                {
                    for(i=sx+1,j=sy-1;i<dx;i++,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        else if(sx>dx)
        {
            if(dy>sy)
            {
                if((sx-dx)==(dy-sy))
                {
                    for(i=sx-1,j=sy+1;i>dx;i--,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else
            {
                if((sx-dx)==(sy-dy))
                {
                    for(i=sx-1,j=sy-1;i>dx;i--,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        if(c==1)
        {
            if(p==3 || p==6)
            {
                if(sum==0 && ((p2>=10 && p2<=18 && p2!=15) || p2==0))
                    return 1;
            }
            if(p==13 || p==16)
            {
                if(sum==0 && ((p2>=1 && p2<=9 && p2!=5) || p2==0))
                    return 1;
            }
            else
                return -1;
        }
    }
    else if(p==2 || p==7 || p==12 || p==17)
    {
        if((p==2 || p==7) && (p2==0 || (p2>=10 && p2<=18 && p2!=15)))
        {
            if(dx==sx+1 && dy==sy+2)
                return 1;
            else if(dx==sx+1 && dy==sy-2)
                return 1;
            else if(dx==sx-1 && dy==sy+2)
                return 1;
            else if(dx==sx-1 && dy==sy-2)
                return 1;
            else if(dx==sx+2 && dy==sy+1)
                return 1;
            else if(dx==sx+2 && dy==sy-1)
                return 1;
            else if(dx==sx-2 && dy==sy+1)
                return 1;
            else if(dx==sx-2 && dy==sy-1)
                return 1;
            else
                return -1;
        }
        if((p==12 || p==17) && (p2==0 || (p2>=1 && p2<=9 && p2!=5)))
        {
            if(dx==sx+1 && dy==sy+2)
                return 1;
            else if(dx==sx+1 && dy==sy-2)
                return 1;
            else if(dx==sx-1 && dy==sy+2)
                return 1;
            else if(dx==sx-1 && dy==sy-2)
                return 1;
            else if(dx==sx+2 && dy==sy+1)
                return 1;
            else if(dx==sx+2 && dy==sy-1)
                return 1;
            else if(dx==sx-2 && dy==sy+1)
                return 1;
            else if(dx==sx-2 && dy==sy-1)
                return 1;
            else
                return -1;
        }
    }
    else if(p==4 || p==14)
    {
        sum=0;
        c=0;
        if(dx==sx && dy>sy)
        {
            for(i=sy+1;i<dy;i++)
                sum+=a[dx][i];
            c=1;
        }
        else if(dx==sx && dy<sy)
        {
            for(i=sy-1;i>dy;i--)
                sum+=a[dx][i];
            c=1;
        }
        else if(dy==sy && dx>sx)
        {
            for(i=sx+1;i<dx;i++)
                sum+=a[i][dy];
            c=1;
        }
        else if(dy==sy && dx<sx)
        {
            for(i=sx-1;i>dx;i--)
                sum+=a[i][dy];
            c=1;
        }
        else if(dx>sx)
        {
            if(dy>sy)
            {
                if((dx-sx)==(dy-sy))
                {
                    for(i=sx+1,j=sy+1;i<dx;i++,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else if(sy>dy)
            {
                if((dx-sx)==(sy-dy))
                {
                    for(i=sx+1,j=sy-1;i<dx;i++,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        else if(sx>dx)
        {
            if(dy>sy)
            {
                if((sx-dx)==(dy-sy))
                {
                    for(i=sx-1,j=sy+1;i>dx;i--,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else if(sy>dy)
            {
                if((sx-dx)==(sy-dy))
                {
                    for(i=sx-1,j=sy-1;i>dx;i--,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        if(c==1)
        {
            if(p==4)
            {
                if(sum==0 && ((p2>=10 && p2<=18 && p2!=15) || p2==0))
                    return 1;
                else
                    return -1;
            }
            if(p==14)
            {
                if(sum==0 && ((p2>=1 && p2<=9 && p2!=5) || p2==0))
                    return 1;
                else
                    return -1;
            }
        }
        else
            return -1;
    }
    else if(p==5)
    {
        if(((dy-sy==1 && dx==sx) || (sy-dy==1 && dx==sx) || (dy==sy && dx-sx==1) || (dy==sy && sx-dx==1) || (dy==sy+1 && dx==sx+1) || (dy==sy-1 && dx==sx+1) || (dy==sy+1 && dx==sx-1) || (dy==sy-1 && dx==sx-1)) && ((p2==0) || (p2>=10 && p2<=18 && p2!=15)))
        {
            if(King_Check(sx,sy,dx,dy)==-1)
                return 1;
            if(King_Check(sx,sy,dx,dy)==1)
                return -1;
        }
        else if(King_Castle(sx,sy,dx,dy)==1)
            return 2;
        else if(King_Castle(sx,sy,dx,dy)==-1)
            return -1;
    }
    else if(p==15)
    {
        if(((dy-sy==1 && dx==sx) || (sy-dy==1 && dx==sx) || (dy==sy && dx-sx==1) || (dy==sy && sx-dx==1) || (dy==sy+1 && dx==sx+1) || (dy==sy-1 && dx==sx+1) || (dy==sy+1 && dx==sx-1) || (dy==sy-1 && dx==sx-1)) && ((p2==0) || (p2>=1 && p2<=9 && p2!=5)))
        {
            if(King_Check(sx,sy,dx,dy)==-1)
                return 1;
            if(King_Check(sx,sy,dx,dy)==1)
                return -1;
        }
        else if(King_Castle(sx,sy,dx,dy)==1)
            return 2;
        else if(King_Castle(sx,sy,dx,dy)==-1)
            return -1;
    }
    else
        return -1;
}
void Front_Page()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"y:\\tcc");
    cleardevice();
    setbkcolor(BLUE);
    setcolor(GREEN);
    int p;
    outtextxy(20,50,"*^@!      CHESS - O - MANIAC      !@^*");
    outtextxy(20,100,"Developed By :- Snehil Vishwakarma");
    outtextxy(20,150,"Guided By :- Ms.Jaspal Vishwakarma");
    outtextxy(40,200,"1. Copyright Of The Game");
    outtextxy(40,250,"2. Game Instructions");
    outtextxy(40,300,"3. Play Game(Multiplayer)");
    outtextxy(40,350,"4. Exit Game");
s:
    cin>>p;
    if(p==1)
        Copyright();
    else if(p==2)
        Instructions();
    else if(p==3)
        main();
    else if(p==4)
        exit(0);
    else
    {
        cout<<"\n Invalid!!! Re-Enter!";
        goto s;
    }
    getch();
    cleardevice();
    closegraph();
}
void Copyright()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"y:\\tcc");
    cleardevice();
    setcolor(RED);
    outtextxy(40,100,"Copyright. All rights reserved.");
    outtextxy(40,200,"Any infringemnt or use without permission will lead to legal action!");
    outtextxy(40,300,"ENJOY THE GAME!!! Press Enter to Continue!!!");
    getch();
    cleardevice();
    closegraph();
    Front_Page();
}
void Instructions()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"y:\\tcc");
    cleardevice();
    setbkcolor(GREEN);
    setcolor(RED);
    outtextxy(40,100,"Copyright. All rights reserved.");
    outtextxy(40,200,"Any infringemnt or use without permission will lead to legal action!");
    outtextxy(40,300,"ENJOY THE GAME!!! Press Enter to Continue!!!");
    getch();
    cleardevice();
    closegraph();
    Front_Page();
}
void Draw_Board()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"y:\\tcc");
    cleardevice();
    setcolor(RED);
    int k=48,l,j;
    for(float i=0;i<=8;i++)
    {
        line(200,48+(i*k),584,48+(i*k));
        line(200+(i*k),48,200+(i*k),432);
    }
    for(j=0;j<8;j++)
    {
        for(l=0;l<8;l++)
        {
            if((j+l+1)%2==0)
            {
                setfillstyle(1,DARKGRAY);
                floodfill(224+(j*k),72+(l*k),RED);
            }
            else if((j+l)%2==0)
            {
                setfillstyle(1,LIGHTGRAY);
                floodfill(224+(j*k),72+(l*k),RED);
            }
        }
    }
    settextstyle(2,HORIZ_DIR,4);
    for(j=0;j<8;j++)
    {
        setcolor(WHITE);
        outtextxy(208+(j*k),356,b[0]);
        setcolor(BLACK);
        outtextxy(208+(j*k),116,b[0]);
        setcolor(WHITE);
        outtextxy(208+(j*k),404,b[j+1]);
        setcolor(BLACK);
        outtextxy(208+(j*k),68,b[j+1]);
    }
    setcolor(WHITE);
    char c[8][2]={"A","B","C","D","E","F","G","H"};
    for(j=0;j<8;j++)
        outtextxy(224+(j*k),440,c[j]);
    char d[8][2]={"8","7","6","5","4","3","2","1"};
    for(j=0;j<8;j++)
        outtextxy(592,68+(j*k),d[j]);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(i==6)
                a[i][j]=9;
            else if(i==1)
                a[i][j]=10;
            else if(i==7)
                a[i][j]=j+1;
            else if(i==0)
                a[i][j]=11+j;
            else
                a[i][j]=0;
        }
    }
}
int Position(float x,float y)
{
    float g,h;
    g=(x-200)/48;
    h=(y-48)/48;
    if(g<=1)
        g=1;
    else if(g<=2)
        g=2;
    else if(g<=3)
        g=3;
    else if(g<=4)
        g=4;
    else if(g<=5)
        g=5;
    else if(g<=6)
        g=6;
    else if(g<=7)
        g=7;
    else if(g<=8)
        g=8;
    if(h<=1)
        h=1;
    else if(h<=2)
        h=2;
    else if(h<=3)
        h=3;
    else if(h<=4)
        h=4;
    else if(h<=5)
        h=5;
    else if(h<=6)
        h=6;
    else if(h<=7)
        h=7;
    else if(h<=8)
        h=8;
    return (g*10)+h;
}
void Co_Ordinates(int x,int y,int &cox,int &coy)
{
    coy=((x+1)*48)+20;
    cox=((y)*48)+208;
}
int King_Check(int sx,int sy,int dx,int dy)
{
    int s=0,i,j;
    if(p==5 && ((p2==0) || (p2>=10 && p2<=18 && p2!=15)))
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(a[i][j]>=10 && a[i][j]<=18)
                    if(Valid(i,j,dx,dy)>=1)
                        s++;
            }
        }
    }
    else if(p==15 && ((p2==0) || (p2>=10 && p2<=18 && p2!=15)))
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(a[i][j] >=1 && a[i][j]<=9)
                    if(Valid(i,j,dx,dy)>=1)
                        s++;
            }
        }
    }
    if(s==0)
        return 1;
    else
        return -1;
}
int King_Castle(int sx, int sy, int dx, int dy)
{
    if(p==15)
    {
        if(sx==0 && sy==4 && dx==0 && ((dy==2 && a[0][1]==0 && a[0][2]==0 && a[0][3]==0 && a[0][0]==11) || (dy==6 && a[0][5]==0 && a[0][6]==0 && a[0][7]==18)))
            return 1;
        else
            return -1;
    }
    else if(p==5)
    {
        if(sx==7 && sy==4 && dx==7 && ((dy==2 && a[7][1]==0 && a[7][2]==0 && a[7][3]==0 && a[7][0]==1) || (dy==6 && a[7][5]==0 && a[7][6]==0 && a[7][7]==8)))
            return 1;
        else
            return -1;
    }
}
int King_Check_Move()
{
    int s=0,ix,iy,jx,jy,q,w;
    if(player==1)
    {
        for(ix=0;ix<8;ix++)
        {
            for(iy=0;iy<8;iy++)
            {
                if(a[ix][iy]==5)
                {
                    q=ix;
                    w=iy;
                }
            }
        }
        for(jx=0;jx<8;jx++)
        {
            for(jy=0;jy<8;jy++)
            {
                if(a[jx][jy]>=10 && a[jx][jy]<=18)
                    if(Valid_Check_Move(jx,jy,q,w)>=1)
                    {
                        s++;
                    }
            }
        }
    }
    else if(player==2)
    {
        for(ix=0;ix<8;ix++)
        {
            for(iy=0;iy<8;iy++)
            {
                if(a[ix][iy]==15)
                {
                    q=ix;
                    w=iy;
                }
            }
        }
        for(jx=0;jx<8;jx++)
        {
            for(jy=0;jy<8;jy++)
            {
                if(a[jx][jy]>=1 && a[jx][jy]<=9)
                    if (Valid_Check_Move(jx,jy,q,w)>=1)
                        s++;
            }
        }
    }
    if(s==0)
        return -1;
    else
        return 1;
}
int King_Mate()
{
    int s=0,ix,iy,jx,jy,q,w,i,j;
    if(player==1)
    {
        for(ix=0;ix<8;ix++)
       	{
            for(iy=0;iy<8;iy++)
            {
                if(a[ix][iy]==5)
                {
                    q=ix;
                    w=iy;
                }
            }
        }
        for(ix=q-1;ix<=(q+1);ix++)
        {
            for(iy=w-1;iy<=(w+1);iy++)
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        if(a[i][j]>=10 && a[i][j]<=18)
                            if(Valid(i,j,ix,iy)==1)
                                s++;
                    }
                }
            }
        }
    }
    if(player==2)
    {
        for(ix=0;ix<8;ix++)
        {
            for(iy=0;iy<8;iy++)
            {
                if(a[ix][iy]==15)
                {
                    q=ix;
                   	w=iy;
                }
            }
        }
        for(ix=q-1;ix<=(q+1);ix++)
        {
            for(iy=w-1;iy<=(w+1);iy++)
            {
                for(i=0;i<8;i++)
                {
                    for(j=0;j<8;j++)
                    {
                        if(a[i][j]>=1 && a[i][j]<=9)
                            if(Valid(i,j,ix,iy)==1)
                                s++;
                    }
                }
            }
        }
    }
    cout<<s;
    if(s>=9)
       	return 3;
    else
       	return -1;
}
int Valid_Check_Move(int sx, int sy, int dx, int dy)
{
    int p=a[sx][sy];
    int p2=a[dx][dy];
    int sum=0,i,j,c=0;
    if(p==p2)
        return -1;
    else if(p==0)
        return -1;
    else if(p==10)
    {
        if((dx-sx)>2 || (dy-sy)>1)
            return -1;
        else
        {
            if(dx==sx+1 && dy==sy && p2==0)
                return 1;
            else if(dx==sx+2 && dy==sy && sx==1 && p2==0 && a[dx-1][dy]==0)
                return 1;
            else if(dy==0)
            {
                if(dx==sx+1 && dy==sy-1 && (p2>=1 && p2<=9))
                    return 1;
                else
                    return -1;
            }
            else if(dy==7)
            {
                if(dx==sx+1 && dy==sy+1 && (p2>=1 && p2<=9))
                    return 1;
                else
                    return -1;
            }
            else if(dy!=0 && dy!=7)
            {
                if(dx==sx+1 && (dy==sy-1 || dy==sy+1) && (p2>=1 && p2<=9))
                    return 1;
                else
                    return -1;
            }
            return -1;
        }
    }
    else if(p==9)
    {
        if(((sx-dx)>2) || ((sy-dy)>2))
        {
            return -1;
        }
        else
        {
            if(dx==sx-1 && dy==sy && p2==0)
                return 1;
            else if(dx==sx-2 && dy==sy && p2==0 && sx==6 && a[dx+1][dy]==0)
                return 1;
            else if(dy==0)
            {
                if(dx==sx-1 && dy==sy-1 && (p2>=10 && p2<=18))
                    return 1;
                else
                    return -1;
            }
            else if(dy==7)
            {
                if(dx==sx-1 && dy==sy+1 && (p2>=10 && p2<=18))
                    return 1;
                else
                    return -1;
            }
            else if(dy!=0 && dy!=7)
            {
                if(dx==sx-1 && (dy==sy-1 || dy==sy+1) && (p2>=10 && p2<=18))
                    return 1;
                else
                    return -1;
            }
            return -1;
        }
    }
    else if(p==1 || p==8 || p==11 || p==18)
    {
        sum=0;
        c=0;
        if(dx==sx && dy>sy)
        {
            for(i=sy+1;i<dy;i++)
                sum+=a[dx][i];
            c=1;
        }
        else if(dx==sx && dy<sy)
        {
            for(i=sy-1;i>dy;i--)
                sum+=a[dx][i];
            c=1;
        }
        else if(dy==sy && dx>sx)
        {
            for(i=sx+1;i<dx;i++)
                sum+=a[i][dy];
            c=1;
        }
        else if(dy==sy && dx<sx)
        {
            for(i=sx-1;i>dx;i--)
                sum+=a[i][dy];
            c=1;
        }
        if(c==1)
        {
            if(p==1 || p==8)
            {
                if(sum==0 && ((p2>=10 && p2<=18) || p2==0))
                    return 1;
                else
                    return -1;
            }
            else if(p==11 || p==18)
            {
                if(sum==0 && ((p2>=1 && p2<=9) || p2==0))
                    return 1;
                else
                    return -1;
            }
        }
        else
            return -1;
    }
    else if(p==3 || p==6 || p==13 || p==16)
    {
        sum=0;
        c=0;
        if(dx>sx)
        {
            if(dy>sy)
            {
                if((dx-sx)==(dy-sy))
                {
                    for(i=sx+1,j=sy+1;i<dx;i++,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else
            {
                if((dx-sx)==(sy-dy))
                {
                    for(i=sx+1,j=sy-1;i<dx;i++,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        else if(sx>dx)
        {
            if(dy>sy)
            {
                if((sx-dx)==(dy-sy))
                {
                    for(i=sx-1,j=sy+1;i>dx;i--,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else
            {
                if((sx-dx)==(sy-dy))
                {
                    for(i=sx-1,j=sy-1;i>dx;i--,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        if(c==1)
        {
            if(p==3 || p==6)
            {
                if(sum==0 && ((p2>=10 && p2<=18) || p2==0))
                    return 1;
                else
                    return -1;
            }
            if(p==13 || p==16)
            {
                if(sum==0 && ((p2>=1 && p2<=9) || p2==0))
                    return 1;
                else
                    return -1;
            }
            else
                return -1;
        }
        else
            return -1;
    }
    else if(p==2 || p==7 || p==12 || p==17)
    {
        if((p==2 || p==7) && (p2==0 || (p2>=10 && p2<=18)))
        {
            if(dx==sx+1 && dy==sy+2)
                return 1;
            else if(dx==sx+1 && dy==sy-2)
                return 1;
            else if(dx==sx-1 && dy==sy+2)
                return 1;
            else if(dx==sx-1 && dy==sy-2)
                return 1;
            else if(dx==sx+2 && dy==sy+1)
                return 1;
            else if(dx==sx+2 && dy==sy-1)
                return 1;
            else if(dx==sx-2 && dy==sy+1)
                return 1;
            else if(dx==sx-2 && dy==sy-1)
                return 1;
            else
                return -1;
        }
        if((p==12 || p==17) && (p2==0 || (p2>=1 && p2<=9)))
        {
            if(dx==sx+1 && dy==sy+2)
                return 1;
            else if(dx==sx+1 && dy==sy-2)
                return 1;
            else if(dx==sx-1 && dy==sy+2)
                return 1;
            else if(dx==sx-1 && dy==sy-2)
                return 1;
            else if(dx==sx+2 && dy==sy+1)
                return 1;
            else if(dx==sx+2 && dy==sy-1)
                return 1;
            else if(dx==sx-2 && dy==sy+1)
                return 1;
            else if(dx==sx-2 && dy==sy-1)
                return 1;
            else
                return -1;
        }
    }
    else if(p==4 || p==14)
    {
        sum=0;
        c=0;
        if(dx==sx && dy>sy)
        {
            for(i=sy+1;i<dy;i++)
                sum+=a[dx][i];
            c=1;
        }
        else if(dx==sx && dy<sy)
        {
            for(i=sy-1;i>dy;i--)
                sum+=a[dx][i];
            c=1;
        }
        else if(dy==sy && dx>sx)
        {
            for(i=sx+1;i<dx;i++)
                sum+=a[i][dy];
            c=1;
        }
        else if(dy==sy && dx<sx)
        {
            for(i=sx-1;i>dx;i--)
                sum+=a[i][dy];
            c=1;
        }
        else if(dx>sx)
        {
            if(dy>sy)
            {
                if((dx-sx)==(dy-sy))
                {
                    for(i=sx+1,j=sy+1;i<dx;i++,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else if(sy>dy)
            {
                if((dx-sx)==(sy-dy))
                {
                    for(i=sx+1,j=sy-1;i<dx;i++,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        else if(sx>dx)
        {
            if(dy>sy)
            {
                if((sx-dx)==(dy-sy))
                {
                    for(i=sx-1,j=sy+1;i>dx;i--,j++)
                        sum+=a[i][j];
                    c=1;
                }
            }
            else if(sy>dy)
            {
                if((sx-dx)==(sy-dy))
                {
                    for(i=sx-1,j=sy-1;i>dx;i--,j--)
                        sum+=a[i][j];
                    c=1;
                }
            }
        }
        if(c==1)
        {
            if(p==4)
            {
                if(sum==0 && ((p2>=10 && p2<=18) || p2==0))
                    return 1;
                else
                    return -1;
            }
            if(p==14)
            {
                if(sum==0 && ((p2>=1 && p2<=9) || p2==0))
                    return 1;
                else
                    return -1;
            }
        }
        else
            return -1;
    }
    else if(p==5)
    {
        if((	(dy-sy==1 && dx==sx) || (sy-dy==1 && dx==sx) ||
            (dy==sy && dx-sx==1) || (dy==sy && sx-dx==1) ||
            (dy==sy+1 && dx==sx+1) || (dy==sy-1 && dx==sx+1) ||
            (dy==sy+1 && dx==sx-1) || (dy==sy-1 && dx==sx-1) )
           &&((p2==0) || (p2>=10 && p2<=18) ))
        {
            return 1;
        }
        else
            return -1;
    }
    else if(p==15)
    {
        if((	(dy-sy==1 && dx==sx) || (sy-dy==1 && dx==sx) ||
            (dy==sy && dx-sx==1) || (dy==sy && sx-dx==1) ||
            (dy==sy+1 && dx==sx+1) || (dy==sy-1 && dx==sx+1) ||
            (dy==sy+1 && dx==sx-1) || (dy==sy-1 && dx==sx-1))
           &&((p2==0) || (p2>=1 && p2<=9)))
        {
            return 1;
        }
        else
            return -1;
    }
    else
        return -1;
}

void instructions()
{
    
}