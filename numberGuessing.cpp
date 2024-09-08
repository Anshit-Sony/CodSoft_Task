#include<iostream>
#include <cstdlib>  
#include <ctime>
using namespace std;

void guessGame(){
    cout<<"Guessing Game.\n" << endl;
    int number_to_guess=rand()%100+1;
    cout<<number_to_guess;
    int numberGuessed;
    while(true){
        cout<<"Guess any number between 1-100 : ";
        cin>>numberGuessed;
        if(numberGuessed>number_to_guess){
            cout<<"Guess lower."<<endl;
        }
        else if(numberGuessed<number_to_guess){
            cout<<"Guess Higher."<<endl;
        }
        else{
            cout<<"Wow! You have guessed correct."<<endl;
            break;;
        }
    }
    return;
}

int main(){
    srand(time(0)); 
    guessGame();
    while(true){
        cout<<"Do you want to play again(press 0 to 'quit): ";
        int opt;
        cin>>opt;
        if(opt==0) break;
        else guessGame();
    }
    return 0;
}