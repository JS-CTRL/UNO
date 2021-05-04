#include "card.h"
#include <iostream>

int getUserInputWild(){
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


Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

SkipCard::SkipCard(Color c, Special s) {
    setColor(c);
    setNumber(s);
}

WildCard::WildCard(Color c, Special s) {
    setColor(c);
    setNumber(s);
}

ReverseCard::ReverseCard(Color c, Special s) {
    setColor(c);
    setNumber(s);
}

Draw2Card::Draw2Card(Color c, Special s) {
    setColor(c);
    setNumber(s);
}

WildDraw4Card::WildDraw4Card(Color c, Special s) {
    setColor(c);
    setNumber(s);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}



string SkipCard::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
      
        case 3: return "|           |";           
        case 4: return "|   Skip    |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}//end SkipCard::render

string Draw2Card::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
      
        case 3: return "|           |";           
        case 4: return "|   Draw 2  |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}//end Draw2Card::render

string ReverseCard::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
      
        case 3: return "|  <--      |";           
        case 4: return "|  Reverse  |";
        case 5: return "|     -->   |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}//end ReverseCard::render

string WildCard::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|  R_B_G_Y  |";
                break;
            break;
            }
      
        case 3: return "|           |";           
        case 4: return "|   Wild    |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}//end WildCard::render




string WildDraw4Card::render(int line) const{
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|  R_B_G_Y  |";
                break;
            break;
            }
      
        case 3: return "|           |";           
        case 4: return "|   Wild    |";
        case 5: return "|           |";
        case 6: return "|  Draw 4   |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}//end WildCard::render

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.skipTurn=false;
        return true;
    } else {
        return false;
    }
}

bool SkipCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.skipTurn=true;
        return true;
    } else {
        return false;
    }
}

bool Draw2Card::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.numCardsToDraw=2;
        gameState.skipTurn=false;
        return true;
    } else {
        return false;
    }
}


bool ReverseCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        gameState.skipTurn=false;
        if (gameState.turnDirection==RIGHT){gameState.turnDirection=LEFT;}
        else if (gameState.turnDirection==LEFT) {gameState.turnDirection=RIGHT;}
        return true;
    } else {
        return false;
    }
}




bool WildCard::play(Card* discard, GameState &gameState) {
    int colorIn=-1;
    cout<<"Pick a color:"<<endl;
    cout<<"0: Red"<<endl;
    cout<<"1: Blue"<<endl;
    cout<<"2: Green"<<endl;
    cout<<"3: Yellow"<<endl;

        
    colorIn=getUserInputWild();
        
    while ((colorIn<0) || (colorIn>3)){
        cout <<endl<< "Invalid entry!" << endl;
        cout << "Pick a color" << endl;
        cout<<"0: Red"<<endl;
        cout<<"1: Blue"<<endl;
        cout<<"2: Green"<<endl;
        cout<<"3: Yellow"<<endl;
        colorIn=getUserInputWild();
    }
    
    setColor((Color)colorIn);
    //discard->setColor((Color)colorIn);
    //discard->setColor(BLUE);
    //cout<<"discard color" <<discard->getColor()<<endl;
    gameState.skipTurn=false;
    return true;
    
}


bool WildDraw4Card::play(Card* discard, GameState &gameState) {
    int colorIn=-1;
    cout<<"Pick a color:"<<endl;
    cout<<"0: Red"<<endl;
    cout<<"1: Blue"<<endl;
    cout<<"2: Green"<<endl;
    cout<<"3: Yellow"<<endl;
    colorIn=getUserInputWild();
        
    while ((colorIn<0) || (colorIn>3)){
        cout <<endl<< "Invalid entry!" << endl;
        cout << "Pick a color" << endl;
        cout<<"0: Red"<<endl;
        cout<<"1: Blue"<<endl;
        cout<<"2: Green"<<endl;
        cout<<"3: Yellow"<<endl;
        colorIn=getUserInputWild();
    }
    
    setColor((Color)colorIn);
    gameState.numCardsToDraw=4;
    //discard->setColor((Color)colorIn);
    //discard->setColor(BLUE);
    //cout<<"discard color" <<discard->getColor()<<endl;
    gameState.skipTurn=false;
    return true;
    
}