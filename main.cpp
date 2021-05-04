#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "game_state.h"
#include "card.h"
#include <string>
#include <sstream>

using namespace std;

/**
 * Function to clear the terminal by inserting many new line characters.
 */
void clearTerminal();

/**
 * Function to populate the deck with cards.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
void buildDeck(vector<Card*>& deck);

/**
 * Function to shuffle the deck.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 */
 void shuffleDeck(vector<Card*>&);

/**
 * Function to draw a card from the deck to either the hand or discard pile.
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param target A vector representing the structure that the card being drawn 
 * from the deck is being drawn to. This can be either a hand or the discard
 * pile
 */
void drawCards(vector<Card*>& deck, vector<Card*>& target, int);

/**
 * Function to draw 7 cards to each player's hand at the beginning of the game.
 * 
 * @param deck A vector reference of Card pointers representing the deck.
 * @param hands A vector of vector of Card pointers representing each player 
 * and their hands. The indicies of the first vector represents a player, and 
 * the indicies of the vector at that index is each individual card within the
 * player's hand.
 */
void populateHands(vector<Card*>& deck, vector<vector<Card*>>& hands);

/** 
 * Renders the cards in he hand vector passed.
 * 
 * @param hand A vector containing Card pointers
 */
void renderHand(vector<Card*> hand);

/**
 * Renders the top card of the passed discard vector.
 * 
 * @param hand A vector containing Card pointers
 */
void renderDiscard(vector<Card*>);

/**
 * Passed references to the deck, hand, and discard vectors and a reference to 
 * the game state. This function will resolve the turn for the current player
 * (whose index is stored in the game state). TakeTurn will query the user for
 * input, draw cards if the previous card was a draw 2 card, or skip the current
 * players turn (see numCardsToPlay in GameState).
 * 
 * @param deck A vector reference of Card pointers representing the deck
 * @param hand A vector reference of Card pointers representing a single player's hand
 * @param discard A vector reference of Card pointers representing the discard pile
 * @param gameState A reference of the game state object
 */
bool takeTurn(vector<Card*>& deck, vector<Card*>& hand, vector<Card*>& discard, GameState& gameState);

bool gameOn(vector<Card*> &hand){
   
    if (hand.size()==0){
        return false;
    }
    else {
    return true;
    }
}

bool gameOver(vector<Card*> &hand){
    
    cout<<"Cards in hand: "<< hand.size()<<endl;
    
    if (hand.size()>0){
        return false;
    }
    else {
        return true;
    }
}

int main(){
    int num_players=2;//Need input validation, greater than 2. bring in as string 
    cout<<"How many people playing?"<<endl;
    cin>>num_players;
    srand(time(0));
    bool noWinner=true;
    GameState gameState(num_players);
    vector<Card*> deck;
    vector<Card*> discard;
    
    vector<vector<Card*>> hands(num_players);
    
    buildDeck(deck);
    shuffleDeck(deck);
    populateHands(deck, hands);
    drawCards(deck, discard, 1);
 
 
 
 
 
 
 
 ////////////////////////////////////////////////////////////////////////////////   
    while(noWinner){
        noWinner=takeTurn(deck, hands.at(gameState.currentPlayerIndex), discard, gameState);
    }
    
    return 0;
}
////////////////////////////////////////////////////////////////////////////////




int getUserInput(){
        #include<iostream>
//#include<limits>
using namespace std;

string str;
cin>>str;
for (int i = 0; i < str.length(); i++){
   if (isdigit(str[i]) == false){
      return -1;
   }
}
return stoi(str);

}


bool deckEmpty(vector<Card*> &deck){
    if (deck.size()<5){
        cout<<"Shuffeling deck"<<endl;
        return true;
    }
    else 
        return false;
}

////////////////////////////////////////////////////////////////////////////////
void clearTerminal(){
    for(int i = 0; i < 100; i++){
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////////
void buildDeck(vector<Card*> &deck){
    // Create Number Cards
    for(int c = RED; c < NUM_COLORS; c++){  
    //for(int c = RED; c < 2; c++){  ///////////////////////////dont forget to delete 
        for(int n = 0; n < 10; n++){
            Card* temp = new NumberCard((Color)c, n);
            deck.push_back(temp);
            deck.push_back(temp);
        }
            Card* temp2 = new ReverseCard((Color)c, REVERSE );
            Card* temp3 = new SkipCard((Color)c, SKIP );
            Card* temp4 = new Draw2Card((Color)c, DRAW2 );
            
            deck.push_back(temp2);
            deck.push_back(temp2);
            deck.push_back(temp3);
            deck.push_back(temp3);
            deck.push_back(temp4);
            deck.push_back(temp4);
            
        }
    Card* temp5 = new WildCard(R_B_G_Y, WILD );
    deck.push_back(temp5);
        Card* temp6 = new WildCard(R_B_G_Y, WILD );
    deck.push_back(temp6);
        Card* temp7 = new WildCard(R_B_G_Y, WILD );
    deck.push_back(temp7);
        Card* temp8 = new WildCard(R_B_G_Y, WILD );
    deck.push_back(temp8);
        Card* temp9 = new WildCard(R_B_G_Y, WILD );
    deck.push_back(temp9);
            Card* temp10 = new WildCard(R_B_G_Y, WILD );
    deck.push_back(temp10);
        Card* temp11 = new WildCard(R_B_G_Y, WILD );
    deck.push_back(temp11);
 
      
            Card* temp12 = new WildDraw4Card(R_B_G_Y_WILD, WILD_DRAW_4 );
    deck.push_back(temp12);
        Card* temp13 = new WildDraw4Card(R_B_G_Y_WILD, WILD_DRAW_4 );
    deck.push_back(temp13);

    }//end build deck
////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////
void shuffleDeck(vector<Card*> &deck){
    for(int i = 0; i < 1000; i++){
        int idx1 = rand() % deck.size();
        int idx2 = rand() % deck.size();
        Card* temp = deck.at(idx1);
        deck.at(idx1) = deck.at(idx2);
        deck.at(idx2) = temp;
    }
}
////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////
void drawCards(vector<Card*> &deck, vector<Card*> &target, int numToDraw){
    for(int i = 0; i < numToDraw; i++){
        if(deck.size() > 0){
            target.push_back(deck.at(deck.size() - 1));
            deck.pop_back();
        } else {
            cout << "WARNING: Deck out of cards" << endl;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////




//Shifts discard pile to deck but leaves the top card in discard
////////////////////////////////////////////////////////////////////////////////
void discard_to_deck(vector<Card*> &deck, vector<Card*> &discard){
    int discardSize=discard.size();
    for(int i = 0; i < discardSize; i++){
        if(discard.size() > 1){
            deck.push_back(discard[0]);
           //discard.pop_front();
           discard.erase(discard.begin());
        } else {
            cout << "Discard added to deck" << endl;
        }//end if/else 
    }//end for loop
}//end discard_to_deck
////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////
void populateHands(vector<Card*> &deck, vector<vector<Card*>> &hands){
    for(int i = 0; i < hands.size(); i++){
        drawCards(deck, hands.at(i), 7);
    }
}
////////////////////////////////////////////////////////////////////////////////








////////////////////////////////////////////////////////////////////////////////
void renderHand(vector<Card*> hand){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                //if (hand.getNumber()==13) {cout<<"doin tha thing"<<endl;hand.Card.setColor(R_B_G_Y);} 
                cout << hand.at(j)->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}
////////////////////////////////////////////////////////////////////////////////







////////////////////////////////////////////////////////////////////////////////
void renderDiscard(vector<Card*> discard){
    //int *temp=&13;
    for(int i = 0; i <= 7; i++){
        cout << discard.at(discard.size() - 1)->render(i) << endl;
    }
   // if (discard.at(discard.size() - 1)==temp){cout<<"ooh its a wild one!"<<endl;}
}
////////////////////////////////////////////////////////////////////////////////









////////////////////////////////////////////////////////////////////////////////
bool takeTurn(vector<Card*> &deck, vector<Card*> &hand, vector<Card*> &discard, GameState &gameState){
    clearTerminal();
    renderDiscard(discard);
    cout << "Player " << gameState.currentPlayerIndex << "'s turn." << endl;
    
    // TODO: Draw cards if necessary (draw 2 card)
    drawCards(deck, hand, gameState.numCardsToDraw);
    gameState.numCardsToDraw = 0; // reset cards to draw back to 0
    
    
    gameOver(hand);
    
    renderHand(hand);
    cout<<endl<<"Deck Card Count: "<<deck.size()<<endl;
    cout<<"Discard Card Count:"<<discard.size()<<endl<<endl;
    if ((discard[0]->getColor()==R_B_G_Y) || (discard[0]->getColor()==R_B_G_Y_WILD)){
        int colorIn=-1;
        cout<<"Started on a wild, pick a color:"<<endl;
        cout<<"0: Red"<<endl;
        cout<<"1: Blue"<<endl;
        cout<<"2: Green"<<endl;
        cout<<"3: Yellow"<<endl;
        
        colorIn=getUserInput();
        
        while ((colorIn<0) || (colorIn>3)){
            cout <<endl<< "Invalid entry!" << endl;
            cout << "Pick a color" << endl;
            cout<<"0: Red"<<endl;
            cout<<"1: Blue"<<endl;
            cout<<"2: Green"<<endl;
            cout<<"3: Yellow"<<endl;
            colorIn=getUserInput();
        }
        
        
        
        
        
        discard[0]->setColor((Color)colorIn);
        clearTerminal();
        renderDiscard(discard);
        cout << "Player " << gameState.currentPlayerIndex << "'s turn." << endl;
        
        // TODO: Draw cards if necessary (draw 2 card)
        drawCards(deck, hand, gameState.numCardsToDraw);
        gameState.numCardsToDraw = 0; // reset cards to draw back to 0
        renderHand(hand);
        cout<<endl<<"Deck Card Count: "<<deck.size()<<endl;
        cout<<"Discard Card Count:"<<discard.size()<<endl<<endl;
    }
    
    // loop for number of cards to play (0 if previously played card was a "skip" or "draw 2")
    if(!gameState.skipTurn){
        // Collect user input
        cout << "What would you like to do?" << endl;
        int i;
        for(i = 0; i < hand.size(); i++){
            cout << i << ": Play Card" << endl;
        }
       cout<< i << ": Draw a Card" << endl;
       
       
       
        int input=-1;
        input=getUserInput();
        
        while ((input<0)|| (input>hand.size())){
            cout <<endl<< "Invalid entry!" << endl;
            cout << "What would you like to do?" << endl;
            int i;
            for(i = 0; i < hand.size(); i++){
            cout << i << ": Play Card" << endl;
            }
            cout<< i << ": Draw a Card" << endl;
            input=getUserInput();
        }
        
       
        // Evaluate user input
        if(input < i){
            // Play card at index input
            if(hand.at(input)->play(discard.at(discard.size()-1), gameState)){
                Card* temp;
                cout<< "user choice "<<temp->getNumber()<<endl;
                if (temp->getNumber()==10){gameState.skipTurn=true;}
                temp = hand.at(input);
                discard.push_back(temp);
                hand.erase(hand.begin() + input); // Remove card in hand at position "input"
            } else {
                cout << "Improper choice" << endl;
                takeTurn(deck, hand, discard, gameState);
                return 1;
            }
        }else if(input == i){
            drawCards(deck, hand, 1);
        }
    }else{
        gameState.skipTurn = false;
    }
    
    // update variables for next turn
    
    if (gameOver(hand)==true){
        clearTerminal();
        for (int i =0; i<20;i++){
        cout<<"Game over: Player "<< gameState.currentPlayerIndex<<" won!"<<endl;
        return 0;//0 means game ends
        }
      
    }
     
    if (deckEmpty(deck)){
        discard_to_deck(deck, discard);
        shuffleDeck(deck);
    }
    gameState.nextTurn();
    return 1;//1 means game keeps going
}
////////////////////////////////////////////////////////////////////////////////