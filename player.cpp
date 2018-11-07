//
// Created by chris_d0m8an5 on 11/4/2018.
//
#include "player.h"
Player()
{
  myName="newPlayer";
}

void addCard(Card c)
{
  myHand.push_back(c);
}

void bookCards(Card c1, Card c2)
{
    myBook.push_back(c1);
    myBook.push_back(c2);

}

bool checkHandForBook(Card &c1, Card &c2)
{

}

bool rankInHand(Card c) const
{
  for (int i =0;i<myHand.size();i++)
  {
    if(myHand.at(i).getRank()==c.getRank())
    {
      return true;
    }
  }
  return false;

}

Card chooseCardFromHand() const
{
    return myHand.at(0);

}

Card removeCardFromHand(Card c)
{
  for (int i=0;i<myHand.size();i++)
  {
    if(myHand.at(i)==c)
    {
      myHand.erase(i,i+1);
      return c;
    }

  }
  cout<<"did not remove specified card from hand";


}

string showHand() const
{
  Card c;
  string cardString;
  string finalString;
    for(int i=0;i<myHand.size();i++)
    {
      c=myHand.at(i);
      cardstring=c.toString();
      finalString=finalString+" "+cardString;

    }
    return finalString;

}

string showBooks() const
{
  Card c;
  string cardString;
  string finalString;
    for(int i=0;i<myBook.size();i++)
    {
      c=myBook.at(i);
      cardstring=c.toString();
      finalString=finalString+" "+cardString;

    }
    return finalString;

}

int getHandSize() const
{
 return myHand.size();

}

int getBookSize() const
{
  return myBook.size();

}

bool checkHandForPair(Card &c1, Card &c2)
{


}

bool sameRankInHand(Card c) const
{
  for(int i=0;i<myHand.size();i++)
  {
    if(myHand.at(i).getRank()==c.getRank())
    {
      return true;
    }
  }
  return false;

}
