//
// Created by chris_d0m8an5 on 11/4/2018.
//

//
// Created by chris_d0m8an5 on 11/4/2018.
//
#include <iostream>
#include <string>
using namespace std;


Card()
{
    myRank=1;
    mySuit=spades;
}

Card(int rank, Suit s)
{
    myRank=rank;
    mySuit=s;

}
string toString() const
{
    string finString= rankString(getRank())+suitString(this->mySuit);///not going to work
    return finString;

}

bool sameSuitAs(const Card& c) const
{
    if((this->mySuit)==(c->mySuit))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int  getRank() const
{
    return myRank;
}

string suitString(Suit s) const
{
    if(s==spades)
    {
        return "s";
    }
    else if(s==hearts)
    {
        return "h";
    }
    else if(s==clubs)
    {
        return "c";
    }
    else if(s==diamonds)
    {
        return "d";
    }
    else
    {
        return "problem with suitString";
    }

}

string rankString(int r) const
{
    char cardLetterRanks[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"}
    char *ptrletter=charLettterRanks;
    r=r-1;
    ptrletter=ptrletter+r;
    return *ptrletter;
}

bool operator == (const Card& rhs) const
{
    if(((this->myRank)==(rhs->myRank))&&((this->mySuit)==(rhs->mySuit)))
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool operator != (const Card& rhs) const
{
    if(((this->myRank)==(rhs->myRank))&&((this->mySuit)==(rhs->mySuit)))
    {
        return false;
    }
    else
    {
        return true;
    }

}