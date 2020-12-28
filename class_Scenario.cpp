#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
#define size1 3 
#define size2 2

using namespace std;

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
    strcpy(player.side,side);
    
    if (strcmp(side,"Axis")==0)
    {
        for (int i=0;i<size1;i++)
            strcpy(ai[i],"Alies");
    }
    else
    {
        for (i=0;i<size1;i++)
            strcpy(ai[i],"Axis");
    }
    
    for (int i=0;i<size1;i++)
    {
        random_terrain=rand()%4;
        switch(random_terrain)
        {
            case 0:
                strcpy(terrain[i],"High Ground");
                continue;
            case 1:
                strcpy(terrain[i],"Plains");
                continue;
            case 2:
                strcpy(terrain[i],"Snowy");
                continue;
            case 3:
                strcpy(terrain[i],"Forest");
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
        cout<<"Rank: "<<units[i].unitRank<<endl;
        cout<<"Soldiers: "<<units[i].soldiers<<endl;
        cout<<"Level: "<<units[i].level<<endl;
        cout<<"Experience"<<units[i].experience<<endl;
        cout<<"Special"<<units[i].special<<endl;
    }
    cout<<"***********************************************************"<<endl;
}












