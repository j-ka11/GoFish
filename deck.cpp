//
// Created by chris_d0m8an5 on 11/4/2018.
//

//
// Created by chris_d0m8an5 on 11/4/2018.
//
using namespace std;
#include <vector>
#include <string>

Deck()           // pristine, sorted deck
{
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
    DeckofCards
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