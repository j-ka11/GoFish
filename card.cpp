//
// Created by chris_d0m8an5 on 11/4/2018.
//

//
// Created by chris_d0m8an5 on 11/4/2018.
//
#include <iostream>
#include <string>
#include "deck.h"
using namespace std;


Card::Card()
{
    myRank=1;
    mySuit=spades;
}

Card::Card(int rank, Suit s)
{
    myRank=rank;
    mySuit=s;

}
string Card::toString() const
{
    string finString= rankString(getRank())+suitString(this->mySuit);///not going to work
    return finString;

}

bool Card::sameSuitAs(const Card& c) const
{
    if((this->mySuit)==(c.mySuit))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int  Card::getRank() const
{
    return myRank;
}

Card::Suit Card::getSuit() const{
    return mySuit;
}

string Card::suitString(Suit s) const
{
    if(s==spades)
    {
        return "Spades";
    }
    else if(s==hearts)
    {
        return "Hearts";
    }
    else if(s==clubs)
    {
        return "Clubs";
    }
    else if(s==diamonds)
    {
        return "Diamonds";
    }
    else
    {
        return "problem with suitString";
    }

}

string Card::rankString(int r) const
{
    string cardLetterRanks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string rank;
    rank = cardLetterRanks[r - 1];
    return rank;
}

bool Card::operator == (const Card& rhs) const
{
    if(((this->myRank)==(rhs.myRank))&&((this->mySuit)==(rhs.mySuit)))
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool Card::operator != (const Card& rhs) const
{
    if(((this->myRank)==(rhs.myRank))&&((this->mySuit)==(rhs.mySuit)))
    {
        return false;
    }
    else
    {
        return true;
    }

}

ostream& operator << (ostream& out, const Card& c){
    cout << c.rankString(c.getRank()) << " of " << c.suitString(c.getSuit()) << endl;
}