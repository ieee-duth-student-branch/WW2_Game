#ifndef Player_H
#define Player_H
#include <iostream>
#include <string>
#include "Unit.h"
#include "Scenario.h"

using namespace std;

class Player {
    private:
        int money;
        Unit units[10];
        string side;
    public:
        friend class Scenario;
        int GetMoney() const {return money;};
        void SetMoney(int in_money) {money=in_money;};
        string GetSide() const {return side;};
        void SetSide(string in_side) {side=in_side;};
        Unit GetUnit(int n) const;
        void BuySpecial(int position);
        void TrainNewUnit(string rank);
        void AddSoldiers(int num_soldiers,int position);
};

Unit Player::GetUnit(int n) const
{
    if (n<10 && n>=0)
    {
        return units[n];
    }
    else
    {
        cout<<"This unit does not exist (out of bounds)"<<endl;
    }
}

void Player::BuySpecial(int position)
{
    if(position<10 && position>=0)
    {
        if(!units[position].special)
        {
            units[position].special=true;
            money-=100*(units[position].lvl+5);
        }
    }
}

void Player::TrainNewUnit(string rank)
{
    int i=0;
    
    while(i<10)
    {
        if(units[i].unitRank=="None")
            break;
        i++;
    }
    
    if(i<10)
    {
        if(rank=="battalion")
        {
            if(money-300>=0)      
            {
                money-=300;
                units[i].TrainNewUnit(rank);
            }
        }
        else if(rank=="brigade")
        {
            if(money-2000>=0)
            {
                money-=2000;
                units[i].TrainNewUnit(rank);
            }
        }
        else if(rank=="division")
        {
            if(money-8000>=0)
            {
                money-=8000;
                units[i].TrainNewUnit(rank);
            }
        }
        else if(rank=="corps")
        {
            if(money-25000>=0)
            {
                money-=25000;
                units[i].TrainNewUnit(rank);
            }
        }
        else if(rank=="tanks")
        {
            if(money-800>=0)
            {
                money-=800;
                units[i].TrainNewUnit(rank);
            }
        }
    }
}

void Player::AddSoldiers(int num_soldiers,int position)
{
    int cost;
    
    if(position>=0 && position<10)
    {
        if(units[position].unitRank=="battalion" || units[position].unitRank=="brigade")
        {
            cost=num_soldiers*units[position].lvl;
            
            if(money-cost<0 && money>=units[position].lvl)
            {
                while(money-cost<0)
                {
                    num_soldiers--;
                    cost=num_soldiers*units[position].lvl;
                }
                
                units[position].AddSoldiers(num_soldiers);
                money-=cost;
            }
            else if(money-cost>=0)
            {
                units[position].AddSoldiers(num_soldiers);
                money-=cost; 
            }
        }
        else if(units[position].unitRank=="division" || units[position].unitRank=="corps")
        {
            cost=num_soldiers*(units[position].lvl+1);
            
            if(money-cost<0 && money>=(units[position].lvl+1))
            {
                while(money-cost<0)
                {
                    num_soldiers--;
                    cost=num_soldiers*(units[position].lvl+1);
                }
                
                units[position].AddSoldiers(num_soldiers);
                money-=cost;
            }
            else if(money-cost>=0)
            {
                units[position].AddSoldiers(num_soldiers);
                money-=cost; 
            }           
        }
        else if(units[position].unitRank=="tanks")
        {
            cost=num_soldiers*100*(units[position].lvl+1);
            
            if(money-cost<0 && money>=100*(units[position].lvl+1))
            {
                while(money-cost<0)
                {
                    num_soldiers--;
                    cost=num_soldiers*100*(units[position].lvl+1);
                }
                
                units[position].AddSoldiers(num_soldiers);
                money-=cost;
            }
            else if(money-cost>=0)
            {
                units[position].AddSoldiers(num_soldiers);
                money-=cost; 
            }      
        }
    }
}

#endif

