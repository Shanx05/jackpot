#include <iostream>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <chrono>
#include <unistd.h>
#include "../headers/headerfiles.hpp"

namespace randGen {
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int generateRandNum(int min, int max){
    int slot_one, slot_two, slot_three;
    
    std::uniform_int_distribution<> gen{min, max};
    slot_one = gen(randGen::mersenne);
    slot_two = gen(randGen::mersenne);
    slot_three = gen(randGen::mersenne);
    std::cout<<"Generating the numbers...\n";
    sleep(1);
    std::cout<<"\n===============================================================\n";
    std::cout<<slot_one<<"\t\t\t"<<slot_two<<"\t\t\t"<<slot_three;
    std::cout<<"\n===============================================================\n";
    if((slot_one == slot_two) || (slot_one == slot_three) || (slot_two == slot_three) ){
        if((slot_one == slot_two) && (slot_one == slot_three)){
            std::cout<<"\nCONGRATULATIONS!!!!\n";
            std::cout<<"YOU JUST WON A MILLION EUROS!!\n";
            exit(0);
        }
        std::cout<<"\nYou almost had it mate, better luck next time!\n";
        another_attempt(min, max);
    }

    std::cout<<"\nYou were nowhere near winning!\n";
    another_attempt(min, max);
}

int another_attempt(int min, int max){
    char choice; 

    std::cout<<"Would you like to play one more time (y/n)?\n";
        std::cin>>choice;
        if(choice == 'y'){
            generateRandNum(min, max);
        } 
}

int main(){
    int selection; 
    std::cout<<"\n===============================================================\n";
    std::cout<<"Welcome to Jackpot!!!\n";
    std::cout<<"===============================================================\n\n";
    std::cout<<"There are four levels:\n"; 
    std::cout<<"1. Beginner\n";
    std::cout<<"2. Intermediate\n";
    std::cout<<"3. Expert\n";
    std::cout<<"4. Legendary\n\n";
    std::cout<<"Please enter the level you wish to play: \n";
    std::cin>>selection;
    

    switch (selection){
        case 1: generateRandNum(1, 3);
                break;
        case 2: std::cout<<"That's the spirit!!\n";
                generateRandNum(1, 7);
                break;
        case 3: std::cout<<"It ain't that easy mate!!\n";
                generateRandNum(1, 50);
                break;
        case 4: std::cout<<"So you think you can defeat the computer? Meh!!\n"; 
                generateRandNum(1, 100);
                break;
        default:
                std::cout<<"Not a valid option\n";
                break;
    }
    std::cout<<"Thank you for your participation!\n";
}