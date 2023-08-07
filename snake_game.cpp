#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
COORD pos={0,0};
using namespace std;
int score=0;
bool g_over=false;
int h=30;int w=90;
int fx=rand()%h;int fy=rand()%w;
int x=h/2;int y=w/2;
bool eat_f=false;
int tailx[1000],taily[1000];int tail;
enum edirection {stop=0,right,left,up,down};
edirection dir;



// void body(){

//     eat_f=false;
// }

// void snake(){
//     body();
// }








void move(){

    int preX=tailx[0],preY=taily[0]; int pre2X,pre2Y;
    tailx[0]=x;taily[0]=y;
    for(int i=1;i<tail;i++){
        pre2X=tailx[i];
        pre2Y=taily[i];
        tailx[i]=preX;
        taily[i]=preY;
        preX=pre2X;
        preY=pre2Y;
    }


    switch (dir)
    {
        case edirection::right:
        Sleep(10);
            y++;
            break;
        case edirection::left:
        Sleep(10);
            y--;
            break;
        case edirection::up:
        Sleep(50);
            x--;
            break;
        case edirection::down:
        Sleep(50);
            x++;
            break;
        default:
            break;
    }
    
    if(fx==x&&y==fy){
        srand(time(NULL));score++;
        fx=rand()%h,fy=rand()%w;
        while(fx==0||fy==0||fx==h-1||fy==w-1)fx=rand()%h,fy=rand()%w;
        tail++;
        //after genrate random location it again becomes false//so that in next 
        //iteration it not be true//
    }
    //collide with walls//
    if(x==h-1||x==0||y==0||y==w-1){
        g_over=true;
    }//snake collide with itself
    for(int i=0;i<tail;i++){
        if(x==tailx[i] && y==taily[i]){g_over=true;break;}
    }
}

void input(){//here""_kbhit()" ensures is there hit in key or not
     if(_kbhit()==true){//"_getch()" get input a charater from keyboard//
        switch(_getch()){
            case 'd':dir=edirection::right;break;
            case 'a':dir=edirection::left;break;
            case 'w':dir=edirection::up;break;
            case 's':dir=edirection::down;break;
            default:break;
        }
     }
}


void board(){
    //if fruit has been eaten by snake then it becomes true//
    
    for(int i=0;i<h;i++){
        cout<<"\t\t\t\t\t\t";
        for(int j=0;j<w;j++){
            if(i==0||j==0||j==w-1||i==h-1)cout<<"#";
            else if(fx==i&&fy==j)cout<<"F";
            else if(x==i&&y==j)cout<<"@";
            else {
                bool print=false;
                for(int k=0;k<tail;k++){
                    if(tailx[k]==i && taily[k]==j){
                        cout<<"o";print=true;
                    }
                }
                if(print==false)cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"\t\t\t\t\t";
    cout<<"SCORE : "<<score;
}


int main(){

    while(!g_over){
        //system("cls");
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
        board();
        input();
        move();
        //snake();

    }

    //cout<<"\t------------------------------------------GAME OVER :(-------------------------------------------- ";
    cout<<endl;
    cout<<"\t\t Your score is : "<<score;
}
