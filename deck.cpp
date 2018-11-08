//
// Created by chris_d0m8an5 on 11/4/2018.
//

//
// Created by chris_d0m8an5 on 11/4/2018.
//
using namespace std;
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "deck.h"

Deck::Deck(){               //pristine, sorted deck
    unsigned int timeSeed = ((unsigned) time(0));
    srand(timeSeed);
    myIndex = 0;
    Card::Suit suitArr[4] = {Card::spades, Card::hearts, Card::diamonds, Card::clubs};
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 13;j++){
            Deck::myCards[myIndex] = Card(j + 1, suitArr[i]);
            myIndex++;
        }
    }
    myIndex--;
}

void Deck::shuffle()
{
  if(isEmpty()==false)
  {
    for (int i=0;i < this->size(); i++)
    {
      int numTraverse = (rand() % this->size());
      swapping(i,numTraverse);

    }
  }

}
Card Deck::dealCard()
{
    Card dealtCard;
    dealtCard=myCards[myIndex];
    myIndex--;
    return dealtCard;
}

int  Deck::size() const
{
    return (myIndex + 1);
}

void Deck::swapping(int orig, int trav)
{
    Card temp = myCards[orig];
    myCards[orig] = myCards[trav];
    myCards[trav] = temp;
}

bool Deck::isEmpty(){
    if(size() == 0){
        return true;
    }
    return false;
}

void Deck::printDeck(){
    for(int i = 0;i < this->size();i++){
        cout << "Card number " << (i + 1) << ": " << myCards[i];
    }
}
