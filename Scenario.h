#ifndef Scenario_H
#define Scenario_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "Unit.h"


using namespace std;

static const int size1=3;
static const int size2=2;



class Scenario {
    private:
        int baseIncome;
        Player player;
        Player ai[size1];
        int incomeIncrease[size1];
        string terrain[size1];
        int availableEnemies[size2];
        int victories;
    public:
        Scenario(string side,int money,int income);
        void AddEnemy(int position,int money,int income,Unit units[10]);
        void PrintPlayerState();
        void printEnemies();
        void makeMove();
};



Scenario::Scenario(string side,int money,int income)
{
    int random_terrain;
    player.money=money;
    baseIncome=income;
    player.side=side;
    
    if (side=="Axis")
    {
        for (int i=0;i<size1;i++)
            ai[i].side="Alies";
    }
    else
    {
        for (int i=0;i<size1;i++)
            ai[i].side="Axis";
    }
    
    for (int i=0;i<size1;i++)
    {
        random_terrain=rand()%4;
        switch(random_terrain)
        {
            case 0:
                terrain[i]="High Ground";
                continue;
            case 1:
                terrain[i]="Plains";
                continue;
            case 2:
                terrain[i]="Snowy";
                continue;
            case 3:
                terrain[i]="Forest";
                continue;
        }
    }
}

void Scenario::AddEnemy(int position,int money,int income,Unit units[10])
{
    if (position<size1)
    {
        ai[position].money=money;
        for (int i=0;i<10;i++)
        {
            ai[position].units[i]=units[i];
        }
        incomeIncrease[position]=income;
    }
    else
    {
        cout<<"Cannot create an enemy at the given position (out of bounds)"<<endl;
    }
}

void Scenario::PrintPlayerState()
{
    cout<<"Player's money:"<<player.money<<std::endl;
    for (int i=0;i<10;i++)
    {
        cout<<"***********************************************************"<<endl;
        cout<<"Unit "<<i<<":"<<endl;
        cout<<"Rank: "<<player.units[i].unitRank<<endl;
        cout<<"Soldiers: "<<player.units[i].soldiers<<endl;
        cout<<"Level: "<<player.units[i].lvl<<endl;
        cout<<"Experience: "<<player.units[i].exp<<endl;
        cout<<"Special: "<<player.units[i].special<<endl;
    }
    cout<<"***********************************************************"<<endl;
}

#endif

