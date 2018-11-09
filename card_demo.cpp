// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void winner(const Player& p1, const Player& p2);



int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.printDeck();
    d.shuffle();
    cout << "\n\nDeck was just shuffled" << endl;
    d.printDeck();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    //cout<<p1.getName()<<" asks for: "<<p1.chooseCardFromHand();

    while((p1.getBookSize() + p2.getBookSize()) < 52){

        //player 1's turn
        cout << p1.getName() << " asks: Do you have any ";
        bool hasRank;
        if(p1.getHandSize() != 0){
            Card p1Card = p1.getFirstCardInHand();
            string p1Rank = p1Card.rankString(p1Card.getRank());
            cout << p1Rank << "'s ?" << endl;
            //player 2 searches for card asked
            hasRank = p2.rankInHand(p1Card);
            if(!hasRank){
                cout << p2.getName() << " says: GoFish" << endl;
                //now player 1 draws from the deck
                p1.addCard(d.dealCard());
                //now move player 1's hand to the back
                p1.moveCardToBack();
                Card printedCard = p1.getLastCardInHand();
                cout << p1.getName() << " draws a " << printedCard.rankString(printedCard.getRank()) << " of "<< printedCard.suitString(printedCard.getSuit()) << endl;
            }else {
                int numRanks = p2.numRankInHand(p1Card.getRank());
                if (numRanks == 1) {
                    cout << p2.getName() << " says: Yes. I have one " << p1Card.rankString(p1Card.getRank()) << endl;
                } else {
                    cout << p2.getName() << " says: Yes. I have " << numRanks << " "
                         << p1Card.rankString(p1Card.getRank()) << "'s" << endl;
                }
                //move the card(s) to player 1's hand
                for (int i = 0; i < numRanks; i++) {
                    p1.addCard(p2.removeCardFromHand(p1Card));
                }
            }
        }else{
            p1.addCard(d.dealCard());
        }
        p1.checkHandForBook();
        cout << p1.getName() <<" has : " << p1.showHand() << endl;
        cout << p2.getName() <<" has : " << p2.showHand() << endl;
        cout << "\n\n";

        //Player 2's Turn
        if(p2.getHandSize() != 0) {
            cout << p2.getName() << " asks: Do you have any ";
            Card p2Card = p2.getFirstCardInHand();
            string p2Rank = p2Card.rankString(p2Card.getRank());
            cout << p2Rank << "'s ?" << endl;
            //player 1 searches for card asked
            hasRank = p1.rankInHand(p2Card);
            if (!hasRank) {
                cout << p1.getName() << " says: GoFish" << endl;
                //now player 2 draws from the deck
                p2.addCard(d.dealCard());
                //now move player 2's hand to the back
                p2.moveCardToBack();
                Card printedCard = p2.getLastCardInHand();
                cout << p2.getName() << " draws a " << printedCard.rankString(printedCard.getRank()) << " of "
                     << printedCard.suitString(printedCard.getSuit()) << endl;
            } else {
                int numRanks = p1.numRankInHand(p2Card.getRank());
                if (numRanks == 1) {
                    cout << p1.getName() << " says: Yes. I have one " << p2Card.rankString(p2Card.getRank()) << endl;
                } else {
                    cout << p1.getName() << " says: Yes. I have " << numRanks << " "
                         << p2Card.rankString(p2Card.getRank()) << "'s" << endl;
                }
                //move the card(s) to player 2's hand
                for (int i = 0; i < numRanks; i++) {
                    p2.addCard(p1.removeCardFromHand(p2Card));
                }
            }
        }else{
            p2.addCard(d.dealCard());
        }
        p2.checkHandForBook();
        cout << p1.getName() <<" has : " << p1.showHand() << endl;
        cout << p2.getName() <<" has : " << p2.showHand() << endl;
        cout << "\n\n";
    }
    cout << "\n";
    winner(p1, p2);
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

void winner(const Player& p1, const Player& p2){
    Player winner;
    cout<<p1.getName()<<" has "<<p1.getBookSize()<<" books."<<endl;
    cout<<p2.getName()<<" has "<<p2.getBookSize()<<" books."<<endl;
    if(p1.getBookSize() > p2.getBookSize()){
        winner = p1;
    }else if(p1.getBookSize() < p2.getBookSize()){
        winner = p2;
    }else{
        cout << "There was a tie!" << endl;
        return;
    }
    cout << "The winner is " << winner.getName();
    cout<< p1.getName()<<" "<<
}
   



