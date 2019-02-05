#include <iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib>

using namespace std;

char bored[6][7];
char xbored[6][7];
int choice ;

void showMainMenu()
{
        clear();
        system("mode 30,25");
        cout<<"******************************"<<endl;
        cout<<"* *       WIN'IN FOUR      * *"<<endl;
        cout<<"******************************"<<endl;
        cout<<endl<<endl;
        cout<<"     Welcome...               "<<endl;
        cout<<endl;
        cout<<"   Press 1 to play 1 vs 1     "<<endl;
        cout<<"   Press 2 to show about us   "<<endl;
        cout<<"   Press 3 to show rules      "<<endl;
        cout<<"   Press 4 to exit the game   "<<endl;
        cout<<endl<<endl<<endl;
        cout<<"   Put your Choice Here :";
        choice=getch();
        cout<<endl;
        cout<<"******************************"<<endl;
}

void clear()
{
    for(int i=0 ; i<6 ; i++)
        for(int j=0; j<7 ; j++)
            { bored[i][j]=0; xbored[i][j]=0; }
}

void print()
{
    cout<<endl<<endl;
    for(int i=0 ; i<6 ; i++)
        {
            cout<<"     ";
            for(int j=0; j<7 ; j++)
                cout<<"|    "<<bored[i][j]<<"    ";
            cout<<"|"<<endl;

            cout<<"     ";
            for(int z=0 ; z<7 ; z++)
                cout<<"|         ";
            cout<<"|"<<endl;

            cout<<"      ";
            for(int i=0 ;i<69 ; i++)
            cout<<"-";
            cout<<endl;

            if(i!=5)
            {
                cout<<"     ";
                for(int z=0 ; z<7 ; z++)
                    cout<<"|         ";
                cout<<"|"<<endl;
            }
            if(i == 5)
            {
                cout<<"     ";
                for(int z=0 ; z<7 ; z++)
                    cout<<"    "<<z+1<<"     ";
            }
        }
}
bool add(int cols,int player)
{
    cols--;
    for(int i=5 ; i>=0 ; i--)
    {
        if(bored[i][cols]==0)
        {
            if(player == 1)
                bored[i][cols]='X';
            else
                bored[i][cols]='O';
            return true;
        }
    }
    return false;
}

int win()
{
    for(int i=0 ; i<6 ; i++)
        for(int j=0 ; j<4 ; j++)
            if( ((bored[i][j]==bored[i][j+1]) && (bored[i][j+1]==bored[i][j+2]) && (bored[i][j+2]==bored[i][j+3])) && bored[i][j]!=0)
                {
                    if(bored[i][j]=='X')
                        return 1;
                    if(bored[i][j]=='O')
                        return 2;
                }

    for(int j=0; j<7 ; j++)
        for(int i=0 ; i<3 ; i++)
            if( ((bored[i][j]==bored[i+1][j]) && (bored[i+1][j]==bored[i+2][j]) && (bored[i+2][j]==bored[i+3][j])) && bored[i][j]!=0)
                {
                    if(bored[i][j]=='X')
                        return 1;
                    if(bored[i][j]=='O')
                        return 2;
                }

    for(int i=0 ; i<3 ; i++)
        for(int j=3 ; j<6 ; j++)
            if( ((bored[i][j]==bored[i+1][j-1]) && (bored[i+1][j-1]==bored[i+2][j-2]) && (bored[i+2][j-2]==bored[i+3][j-3])) && bored[i][j]!=0)
                {
                    if(bored[i][j]=='X')
                        return 1;
                    if(bored[i][j]=='O')
                        return 2;
                }

    for(int i=0 ; i<3 ; i++)
        for(int j=0 ; j<4 ; j++)
            if( ((bored[i][j]==bored[i+1][j+1]) && (bored[i+1][j+1]==bored[i+2][j+2]) && (bored[i+2][j+2]==bored[i+3][j+3])) && bored[i][j]!=0)
                {
                    if(bored[i][j]=='X')
                        return 1;
                    if(bored[i][j]=='O')
                        return 2;
                }
    return 0;
}

int main()
{

Main : bool main=true;
    while(main==true)
    {
        showMainMenu()
        if(choice=='1' || choice=='2' || choice=='3' || choice=='4')
            main=false;
    }
    switch(choice)
    {
    case '1' :
        {
            start : clear();
            system("mode 80,35");
            int player=1;
            while(win() == 0)
            {
                system("cls");
                if(player ==1)
                    cout<<endl<<"   Player 1 Turn ..."<<endl<<endl;
                else
                    cout<<endl<<"   Player 2 Turn ..."<<endl<<endl;

                print();
                cout<<endl;
                bool main2=true;
                int choice2;
                //chose clos
                while(main2==true)
                {
                    cout<<endl<<"   Put your Choice Here :";
                    choice2=getch();
                    if(choice2=='1' || choice2=='2' || choice2=='3' || choice2=='4' || choice2=='5' || choice2=='6' || choice2=='7')
                        main2=false;
                    else
                        {
                            system("cls");
                            if(player ==1)
                                cout<<endl<<"   Player 1 Turn ..."<<endl<<endl;
                            else
                                cout<<endl<<"   Player 2 Turn ..."<<endl<<endl;
                            print();
                            cout<<"\nColumn doesn't exist"<<endl;
                        }

                }
                bool b=add(choice2-48,player);
                if(b==true)
                   {
                    //changing the player
                    if(player ==1)
                        player=2;
                    else
                        player=1;
                   }
                else
                    { cout<<"You can't put here it's full"<<endl; Sleep(500);}
            }
            system("mode 80,30");
            system("cls");
            print();
            Sleep(2000);
            if(win()==1)
            {
                clear();
                system("mode 30,25");
                cout<<"******************************"<<endl<<endl<<endl;
                cout<<endl<<endl;
                cout<<"                              "<<endl;
                cout<<endl;
                cout<<"                              "<<endl;
                cout<<"       Player 1 Won ....      "<<endl;
                cout<<"                              "<<endl;
                cout<<"                              "<<endl;
                cout<<endl<<endl<<endl;
                cout<<" do you want to try again y/n ";
                cout<<endl;
                cout<<"******************************"<<endl;
                char again;
                again=getch();
                if(again=='y')
                    goto start;
                else
                    goto Main;
            }
            if(win()==2)
            {
                clear();
                system("mode 30,25");
                cout<<"******************************"<<endl<<endl<<endl;
                cout<<endl<<endl;
                cout<<"                              "<<endl;
                cout<<endl;
                cout<<"                              "<<endl;
                cout<<"       Player 2 Won ....      "<<endl;
                cout<<"                              "<<endl;
                cout<<"                              "<<endl;
                cout<<endl<<endl<<endl;
                cout<<" do you want to try again y/n ";
                cout<<endl;
                cout<<"******************************"<<endl;
                char again;
                again=getch();
                if(again=='y')
                    goto start;
                else
                    goto Main;

            }
                break;
            }
    case '2' :
        {
            clear();
            system("mode 30,25");
            cout<<"******************************"<<endl;
            cout<<"* *       WIN'IN FOUR      * *"<<endl;
            cout<<"******************************"<<endl;
            cout<<endl<<endl;
            cout<<"   Programmed By..            "<<endl;
            cout<<endl;
            cout<<"       Fadi A.Ashy            "<<endl;
            cout<<"                              "<<endl;
            cout<<"      \"OFFSET Team\"         "<<endl;
            cout<<"                              "<<endl;
            cout<<endl<<endl<<endl;
            cout<<endl;
            cout<<"******************************"<<endl;
            Sleep(2000);
            goto Main;
            break;
        }
    case '3' :
        {
            clear();
            system("mode 30,25");
            cout<<"******************************"<<endl;
            cout<<"* *       WIN'IN FOUR      * *"<<endl;
            cout<<"******************************"<<endl;
            cout<<endl<<endl;
            cout<<"   Simple Rule                "<<endl;
            cout<<endl;
            cout<<"   Just try to put four       "<<endl;
            cout<<"   letters in one line        "<<endl;
            cout<<"   Vertical or horizontal,    "<<endl;
            cout<<"   or diagonal .              "<<endl;
            cout<<endl<<endl;
            cout<<endl;
            cout<<"******************************"<<endl;
            Sleep(3000);
            goto Main;
            break;
            break;
        }
    case '4' :
        {
            return 0;
        }

    }
}
