// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myFile and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void winner(const Player& p1, const Player& p2, ofstream& myFile);



int main( )
{
    ofstream myFile;
    myFile.open("gofish_results.txt");
    int numCards = 7;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    //myFile << d.printDeck();
    d.shuffle();
    myFile << "\n\nDeck was just shuffled" << endl;
    //myFile << d.printDeck();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    myFile << p1.getName() <<" has : " << p1.showHand() << endl;
    myFile << p2.getName() <<" has : " << p2.showHand() << endl;
    //myFile<<p1.getName()<<" asks for: "<<p1.chooseCardFromHand();
    for(int i = 0;i < 3;i++){
        p1.checkHandForBook();
        p2.checkHandForBook();
    }

    while((p1.getBookSize() + p2.getBookSize()) < 52){
        if((p1.getHandSize() == 1) | (p2.getHandSize() == 1)){
            int g = 0;
            g++;
        }
        //player 1's turn
        myFile << p1.getName() << " asks: Do you have any ";
        bool hasRank;
        if(p1.getHandSize() != 0){
            Card p1Card = p1.getFirstCardInHand();
            string p1Rank = p1Card.rankString(p1Card.getRank());
            myFile << p1Rank << "'s ?" << endl;
            //player 2 searches for card asked
            hasRank = p2.rankInHand(p1Card);
            if(!hasRank){
                myFile << p2.getName() << " says: GoFish" << endl;
                //now player 1 draws from the deck
                Card printedCard = d.dealCard();
                p1.addCard(printedCard);
                //now move player 1's hand to the back
                p1.moveCardToBack();
                myFile << p1.getName() << " draws a " << printedCard.rankString(printedCard.getRank()) << " of "<< printedCard.suitString(printedCard.getSuit()) << endl;
            }else {
                int numRanks = p2.numRankInHand(p1Card.getRank());
                if (numRanks == 1) {
                    myFile << p2.getName() << " says: Yes. I have one " << p1Card.rankString(p1Card.getRank()) << endl;
                } else {
                    myFile << p2.getName() << " says: Yes. I have " << numRanks << " "
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
        myFile << p1.getName() <<" has : " << p1.showHand() << endl;
        myFile << p2.getName() <<" has : " << p2.showHand() << endl;
        myFile<<p1.getName()<<" has "<<(p1.getBookSize())/2<<" books."<<endl;
        myFile<<p2.getName()<<" has "<<(p2.getBookSize())/2<<" books."<<endl;
        myFile << "\n\n";

        //Player 2's Turn
        if(p2.getHandSize() != 0) {
            myFile << p2.getName() << " asks: Do you have any ";
            Card p2Card = p2.getFirstCardInHand();
            string p2Rank = p2Card.rankString(p2Card.getRank());
            myFile << p2Rank << "'s ?" << endl;
            //player 1 searches for card asked
            hasRank = p1.rankInHand(p2Card);
            if (!hasRank) {
                myFile << p1.getName() << " says: GoFish" << endl;
                //now player 2 draws from the deck
                Card printedCard = d.dealCard();
                p2.addCard(printedCard);
                //now move player 2's hand to the back
                p2.moveCardToBack();
                myFile << p2.getName() << " draws a " << printedCard.rankString(printedCard.getRank()) << " of " << printedCard.suitString(printedCard.getSuit()) << endl;
            } else {
                int numRanks = p1.numRankInHand(p2Card.getRank());
                if (numRanks == 1) {
                    myFile << p1.getName() << " says: Yes. I have one " << p2Card.rankString(p2Card.getRank()) << endl;
                } else {
                    myFile << p1.getName() << " says: Yes. I have " << numRanks << " "
                         << p2Card.rankString(p2Card.getRank()) << "'s" << endl;
                }
                //move the card(s) to player 2's hand
                for (int i = 0; i < numRanks; i++) {
                    p2.addCard(p1.removeCardFromHand(p2Card));
                    p2.checkHandForBook();
                }
            }
        }else{
            p2.addCard(d.dealCard());
        }
        p2.checkHandForBook();
        myFile << p1.getName() <<" has : " << p1.showHand() << endl;
        myFile << p2.getName() <<" has : " << p2.showHand() << endl;
        myFile<<p1.getName()<<" has "<<(p1.getBookSize())/2<<" books."<<endl;
        myFile<<p2.getName()<<" has "<<(p2.getBookSize())/2<<" books."<<endl;

        myFile << "\n\n";
    }
    myFile << "\n";
    winner(p1, p2, myFile);
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

void winner(const Player& p1, const Player& p2, ofstream& myFile){
    Player winner;
    Player loser;
    myFile<<p1.getName()<<" has "<<(p1.getBookSize())/2<<" books."<<endl;
    myFile<<p2.getName()<<" has "<<(p2.getBookSize())/2<<" books."<<endl;
    if(p1.getBookSize() > p2.getBookSize()){
        winner = p1;
        loser =p2;
    }else if(p1.getBookSize() < p2.getBookSize()){
        winner = p2;
        loser =p1;
    }else{
        myFile << "There was a tie!" << endl;
        myFile<<p1.getName()<<"'s "<<p1.showBooks()<<endl;
        myFile<<p2.getName()<<"'s "<<p2.showBooks()<<endl;
        return;
    }
    myFile << "The winner is " << winner.getName()<<" with this many books: "<<(winner.getBookSize())/2 << "\n\n";
    myFile<< winner.getName()<<"'s "<< winner.showBooks()<<endl;
    myFile << "The loser is "<< loser.getName()<<" with this many books: "<<(loser.getBookSize())/2 << endl;
    myFile<< loser.getName()<<"'s "<< loser.showBooks()<<endl;
    myFile<<"File is closing";
    myFile.close();
}
   



