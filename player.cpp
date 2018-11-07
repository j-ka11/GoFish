//
// Created by chris_d0m8an5 on 11/4/2018.
//
#include "player.h"
using namespace std;
Player::Player()
{
  myName="newPlayer";
}

void Player::addCard(Card c)
{
  myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2)
{
    myBook.push_back(c1);
    myBook.push_back(c2);

}

bool Player::checkHandForBook(Card &c1, Card &c2)
{

}

bool Player::rankInHand(Card c) const
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

Card Player::chooseCardFromHand() const
{
    return myHand.at(0);

}

Card Player::removeCardFromHand(Card c)
{
  for (int i=0;i<myHand.size();i++)
  {
    if(myHand.at(i)==c)
    {
      myHand.erase(myHand.begin() + i);
      return c;
    }

  }
  cout<<"did not remove specified card from hand";


}

string Player::showHand() const
{
  Card c;
  string cardString;
  string finalString;
    for(int i=0;i<myHand.size();i++)
    {
      c=myHand.at(i);
      cardString=c.toString();
      finalString=finalString+" "+cardString;

    }
    return finalString;

}

string Player::showBooks() const
{
  Card c;
  string cardString;
  string finalString;
    for(int i=0;i<myBook.size();i++)
    {
      c=myBook.at(i);
      cardString=c.toString();
      finalString=finalString+" "+cardString;

    }
    return finalString;

}

int Player::getHandSize() const
{
 return myHand.size();

}

int Player::getBookSize() const
{
  return myBook.size();

}

bool Player::checkHandForPair(Card &c1, Card &c2)
{


}

bool Player::sameRankInHand(Card c) const
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
