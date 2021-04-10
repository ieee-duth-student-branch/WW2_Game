#ifndef Unit_H
#define Unit_H
#include <iostream>
using namespace std;

class Unit {
    private:
         string unitRank;
         int soldiers;
         int lvl;
         int exp;
         bool special;
    public:
    	friend class Player;
    	friend class Scenario;
        Unit();
        string GetUnitRank() const {return unitRank;};
        int GetSoldiers() const {return soldiers;};
        int GetLvl() const {return lvl;};
        bool GetSpecial() const {return special;};
        void SetSpecial(bool in_special){special=in_special;};
        int AddSoldiers(int num_soldiers);
        void AddExp(int x);
        void TrainNewUnit(string s);
        
        
};


Unit::Unit()
{
    unitRank="None";
}

int Unit::AddSoldiers(int num_soldiers)
{
    if(unitRank=="battalion")
    {
        if(num_soldiers>1000)
            soldiers=1000;
        else
            soldiers=num_soldiers;
    }
    else if(unitRank=="brigade")
    {
        if(num_soldiers>5000)
            soldiers=5000;
        else
            soldiers=num_soldiers;
    }
    else if(unitRank=="division")
    {
        if(num_soldiers>20000)
            soldiers=20000;
        else
            soldiers=num_soldiers;
    }
    else if(unitRank=="corps")
    {
        if(num_soldiers>50000)
            soldiers=50000;
        else
            soldiers=num_soldiers;
    }
    else if(unitRank=="tanks")
    {
        if(num_soldiers>10)
            soldiers=10;
        else
            soldiers=num_soldiers;
    }
    
    return soldiers;
}

void Unit::AddExp(int x)
{
    exp+=x;
    
    if(exp>=0 && exp<=49)
        lvl=1;
    else if(exp>=50 && exp<=99)
        lvl=2;
    else if(exp>=100 && exp<=199)
        lvl=3;
    else if(exp>=200 && exp<=399)
        lvl=4;
    else if(exp>400)
        lvl=5;
}

void Unit::TrainNewUnit(string s)
{
    unitRank=s;
    exp=0;
    lvl=1;
    special=false;
    
    if(unitRank=="battalion")
        soldiers=500;
    else if(unitRank=="brigade")
        soldiers=2500;
    else if(unitRank=="division")
        soldiers=10000;
    else if(unitRank=="corps")
        soldiers=25000;
    else if(unitRank=="tanks")
        soldiers=5;
}

#endif


