#include <iostream>
#include <stdlib.h>
#include <random>
#include <ctime>

using namespace std; 

namespace randGen {
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}
int another_attempt(); 

int level_beginner(int min, int max){
    int slot_one, slot_two, slot_three;

    uniform_int_distribution<> gen{min, max};
    slot_one = gen(randGen::mersenne);
    slot_two = gen(randGen::mersenne);
    slot_three = gen(randGen::mersenne);
    cout<<"\n===============================================================\n";
    cout<<slot_one<<"\t\t\t"<<slot_two<<"\t\t\t"<<slot_three;
    cout<<"\n===============================================================\n";
    if((slot_one == slot_two) || (slot_one == slot_three) || (slot_two == slot_three) ){
        if((slot_one == slot_two) && (slot_one == slot_three)){
            cout<<"\nCONGRATULATIONS!!!!\n";
            cout<<"YOU JUST WON A MILLION EUROS!!\n";
            exit(0);
        }
        cout<<"\nYou almost had it mate, better luck next time!\n";
        another_attempt();
    }

    cout<<"\nYou were nowhere near winning!\n";
    another_attempt();
}

int another_attempt(){
    char choice; 

    cout<<"Would you like to play one more time (y/n)?\n";
        cin>>choice;
        if(choice == 'y'){
            level_beginner(1, 3);
        } 
}

int level_intermediate(){

}
int level_expert(){

}
int level_legendary(){

}

int main(){
    int selection; 
    cout<<"\n===============================================================\n";
    cout<<"Welcome to Jackpot!!!\n";
    cout<<"===============================================================\n\n";
    cout<<"There are four levels\n"; 
    cout<<"1. Beginner\n";
    cout<<"2. Intermediate\n";
    cout<<"3. Expert\n";
    cout<<"4. Legendary\n";
    cout<<"Please enter the level you wish to play: \n";
    cin>>selection;

    switch (selection){
        case 1: level_beginner(1, 3);
                break;
        case 2: level_intermediate();
                break;
        case 3: level_expert();
                break;
        case 4: level_legendary();
                break;
        default:
                cout<<"Not a valid option\n";
                break;
    }
    cout<<"Thank you for your participation!";
}