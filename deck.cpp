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

Deck()           // pristine, sorted deck
{
  unsigned int timeSeed = ((unsigned) time(0));
  srand(timeSeed);
    vector<Suits> allSuits;
    allSuits.push_back(spades);
    allSuits.push_back(hearts);
    allSuits.push_back(diamonds);
    allSuits.push_back(clubs);
    vector<Card> DeckofCards;
    for(vector<Suits>::iterator c=allSuits.begin();allSuits.end()!=c;c++)
    {
        for(int j=1;j<14;j++)
        {
            DeckofCards.push_back(Card(j,*c));
        }
    }
}

void shuffle()
{
  if(DeckofCards.empty()==false)
  {
    for (unsigned i=0; i<myvector.size(); i++)
    {
      int numTraverse = (rand() % DeckofCards.size()) + 1;
      swapping(i,numTraverse);

    }
  }

}
Card dealCard()
{
    Card dealtCard;
    dealtCard=DeckofCards.back()
    DeckofCards.push_back();
    return dealtCard;
}

int  size() const
{
    return DeckofCards.size();
}

void swapping(int orig, int trav)
{
  Card temp =DeckofCards.at(i);
  DeckofCards.at(i)=DeckofCards.at(trav);
  DeckofCards.at(trav)=DeckofCards(temp);
}
