#include <iostream>
#include <cstdlib>
#include <time.h>
#include "baseFunctions.cpp"

using namespace std;

int main()
{
    cout<<endl<<endl<<"--------------------------------------------- Array Battle ---------------------------------------------"<<endl<<endl;

    cout<<"Instructions: "<<endl;
    cout<<"1) Objective of the game is to destroy all elements of the opponent's array."<<endl;
    cout<<"2) An element is destroyed when its value becomes less than or equal to zero. Destroyed elements are represented by 0."<<endl;
    cout<<"3) A player can try to destroy their opponent's array by choosing to attack an element or they can choose to defend their array."<<endl;
    cout<<"4) After choosing the index of an element to Attack/Defend, a dice will be rolled to determine the action's value (1-6)."<<endl;
    cout<<"5) A player has a 11"<<'%'<<" chance to land a critical roll while defending or attacking."<<endl;
    cout<<"6) If they get a critical roll, the player will be given an option to choose from 4 Offensive/Defensive bonuses based on their initial choice, or to continue with their regular roll."<<endl;
    cout<<"7) From Round 7 onwards, every roll will be a critical roll."<<endl;
    cout<<"8) From Round 14 onwards, players will only be able to attack."<<endl<<endl;     
    
    cout<<"Choose your number of starting elements: ";
    int n;                                                                                                                                                                      //pre game stuff
    cin>>n;
    cout<<endl<<endl<<"--------------------------------------------- Game Starting! ---------------------------------------------"<<endl<<endl;

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    arrayCreate(arr1, arr2, n);

    bool death = false;
    int round = 1;
    short winner = 0;

    bool shroud1 = false;
    bool shroud2 = false;
    
    while (death == false)
    {
        cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;

        bool shroud1Switch = false;
        bool shroud2Switch = false;
        
        if (shroud1 == true || shroud2 == true)
        {
            int s=0;
            while (s<=500)
            {
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<"...................................................................................................................................."<<endl;
                s++;
            }
            cout<<endl<<endl<<"Shroud in play for this round. "<<endl;
            
            if (shroud1 == true)
            {
                cout<<"Player 1's array won't be visible. ";
            }
            if (shroud2 == true)
            {
                cout<<"Player 2's array won't be visible. ";
            }
            cout<<endl;
        }

        cout<<endl<<"Round: "<<round<<endl;

        if (round>=7)
        {
            cout<<"Perma-bonuses have been enabled. You will get to choose a bonus for Attack or Defense at every chance now."<<endl;
        }
        else if (round>=14)
        {
            cout<<"Defense has been disabled. Perma-bonuses have been enabled. You will get to choose a bonus for Attack at every chance now."<<endl;
        }


        cout<<"Player Arrays at the beginning of the Round: "<<endl;
        if (shroud1 == false)
        {
            cout<<"Player 1 Array: ";
            arrayPrint(arr1, n);
        }
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        if (shroud2 == false)
        {
            cout<<"Player 2 Array: ";
            arrayPrint(arr2, n);
        }
        cout<<"------------------------------------------------------------------------------------------"<<endl;    
        cout<<endl;

        
        //add round info - round no, bonus for this round
        int bonus = rollDie();
        
        int x1 = 0;
        int x2 = 0;      
        
        short opt = 1;

        cout<<"Player 1's turn to choose: "<<endl;
        cout<<"Attack (1)"<<endl<<"Defense (0 / Any other number)"<<endl;

        cin>>opt;
        cout<<endl;

        if (opt==1)                 // p1 attack
        {
            cout<<"Player 1's turn to attack";
            attack(arr2, x1, n, bonus, arr1, round);

            if (shroud1 == false)
            {
                cout<<"Player 1 Array: ";
                arrayPrint(arr1, n);
            }
            cout<<"------------------------------------------------------------------------------------------"<<endl;
          
            if (shroud2 == false)
            {
                cout<<"Player 2's array after attack: ";
                arrayPrint(arr2, n);
            }
            cout<<"------------------------------------------------------------------------------------------"<<endl;

        }
        else                            // p1 defense
        {
            if (round >= 14)
            {
                cout<<"Defence is disabled, you can only attack now."<<endl;
                cout<<"Player 1's turn to attack";
                attack(arr2, x1, n, bonus, arr1, round);

                if (shroud1 == false)
                {
                    cout<<"Player 1 Array: ";
                    arrayPrint(arr1, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;
                
                if (shroud2 == false)
                {
                    cout<<"Player 2's array after attack: ";
                    arrayPrint(arr2, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;
            }
            else
            {
                cout<<"Player 1's turn to defend";
                defend(arr1, x1, n, bonus, round, shroud1Switch);
                
                if (shroud1 == false)
                {
                    cout<<"Player 1's array after defense: ";
                    arrayPrint(arr1, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;
                
                if (shroud2 == false)
                {
                    cout<<"Player 2 Array: ";
                    arrayPrint(arr2, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;    
                
            }
        }
        cout<<endl<<endl;

        death = checkDeath(arr2, n);        // checking player 2 death
        if (death == true)
        {
            winner = 1;
            break;
        }
        
        cout<<"Player 2's turn to choose: "<<endl;
        cout<<"Attack (1)"<<endl<<"Defense (0 / Any other number)"<<endl;

        cin>>opt;
        cout<<endl;

        if (opt==1)                 //  p2 attack
        {
            cout<<"Player 2's turn to attack";
            attack(arr1, x2, n, bonus, arr2, round);
            
            if (shroud1 == false)
            {
                cout<<"Player 1's array after attack: ";
                arrayPrint(arr1, n);
            }
            cout<<"------------------------------------------------------------------------------------------"<<endl;
            
            if (shroud2 == false)
            {
                cout<<"Player 2 Array: ";
                arrayPrint(arr2, n);
            }
            cout<<"------------------------------------------------------------------------------------------"<<endl;    
                
        }
        else                        // p2 defense
        {
            if (round >= 14)
            {
                cout<<"Defence is disabled, you can only attack now."<<endl;
                cout<<"Player 2's turn to attack";
                attack(arr1, x2, n, bonus, arr2, round);
        
                if (shroud1 == false)
                {
                    cout<<"Player 1's array after attack: ";
                    arrayPrint(arr1, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;
            
                if (shroud2 == false)
                {
                    cout<<"Player 2 Array: ";
                    arrayPrint(arr2, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;    
                

            }
            else
            {
                cout<<"Player 2's turn to defend";
                defend(arr2, x2, n, bonus, round, shroud2Switch);

                if (shroud1 == false)
                {
                    cout<<"Player 1 Array: ";
                    arrayPrint(arr1, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;
                
                if (shroud2 == false)
                {
                    cout<<"Player 2's array after defense: ";
                    arrayPrint(arr2, n);
                }
                cout<<"------------------------------------------------------------------------------------------"<<endl;

            }
        }
        cout<<endl;

        death = checkDeath(arr1, n);        // checking player 1 death
        if (death == true)
        {
            winner = 2;
            break;
        }
        

        round++;

        if (shroud1Switch == true)
        {
            shroud1 = true;
        }
        else
        {
            shroud1 = false;
        }

        if (shroud2Switch == true)
        {
            shroud2 = true;
        }
        else
        {
            shroud2 = false;
        }

        cout<<"Round Over!"<<endl<<endl;     
    }

    cout<<"--------------------------------------------- Game Over! ---------------------------------------------"<<endl<<endl;

    if (winner==1)
    {
        cout<<"Player 1 Won!";
    }
    else
    {
        cout<<"Player 2 Won!";
    }
    cout<<endl<<"Rounds Completed: "<<round<<endl;

    cout<<endl<<"Arrays at the end of the Game: "<<endl;

    cout<<"Player 1 Array: ";
    arrayPrint(arr1, n);
    cout<<"------------------------------------------------------------------------------------------"<<endl;

    cout<<"Player 2 Array: ";
    arrayPrint(arr2, n);
    cout<<"------------------------------------------------------------------------------------------"<<endl;
        
    cout<<endl<<"Array Battle 1.0"<<endl;
    cout<<"Made by Lakkshya Gupta :)"<<endl<<endl;                                                                                                           // post game info - winner name, round no etc
    
    delete []arr1;
    delete []arr2;

    
    return 0;
}