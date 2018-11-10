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
    Card returned1 = removeCardFromHand(c1);
    Card returned2 = removeCardFromHand(c2);
    return;
}

Card Player::getFirstCardInHand() {
    return myHand.at(0);
}

Card Player::getLastCardInHand() {
    return myHand.back();
}

void Player::moveCardToBack() {
    myHand.push_back(myHand.at(0));
    removeCardFromHand(myHand.at(0));
}

void Player::checkHandForBook()
{
    bool foundBook = false;
    if(myHand.size()>1) {
        for (int i = 0; i < (myHand.size() - 1); i++) {
            for (int j = i + 1; j < myHand.size(); j++) {
                if (myHand.at(i) == myHand.at(j)) {
                    Card firstCard = myHand.at(i);
                    Card secondCard = myHand.at(j);
                    bookCards(firstCard, secondCard);
                    foundBook = true;
                    return;
                }
            }
        }
    }
    return ;
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

int Player::numRankInHand(int r) const {
    int counter = 0;
    for(int i = 0;i<myHand.size();i++){
        if(myHand.at(i).getRank() == r){
            counter++;
        }
    }
    return counter;
}

Card Player::removeCardFromHand(Card c)
{
  for (int i=0;i<myHand.size();i++)
  {
    if(myHand.at(i)==c)
    {
        Card returnCard = myHand.at(i);
        myHand.erase(myHand.begin() + i);
        return returnCard;
    }

  }
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
  Card c1, c2;
  string cardString;
  string finalString="Books: \n";
    for(int i=0;i<(myBook.size() - 1);i = i + 2)
    {
      c1=myBook.at(i);
      c2 = myBook.at(i + 1);
      cardString=c1.toString() + " " + c2.toString() + " "+"\n";
      finalString = finalString + cardString + " ";
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

bool Player::sameRankInHand(Card c) const
{
  for(int i=0;i<myHand.size();i++)
  {
    if(myHand.at(i)==c)
    {
      return true;
    }
  }
  return false;

}
