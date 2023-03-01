#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int rollDie()
{
    srand(time(0));
    int roll;
    roll = rand()%(6) + 1;

    return roll;
}

void arrayCreate(int* arr1, int* arr2, int const &n)
{
    int i=0;
    int x = rollDie();
    
    while (i<=n-1)
    {
        *(arr1+i) = i+x;
        *(arr2+i) = i+x;
        i++;
    }
}

void arrayPrint(int* arr, int const &n)
{
    int i=0;
    cout<<"[ ";

    while (i<=n-2)
    {
        cout<<*(arr+i)<<", ";
        i++;
    }
    cout<<*(arr+i)<<" ]"<<endl;
}

void negPrevent(int* arr, int const &n)
{
    int i=0;
    while (i<=n-1)
    {
        if (*(arr+i) <= 0)
        {
            *(arr+i) = 0;
        }
        i++;
    }
}

bool checkDeath(int* arr, int const &n)
{
    int i=0;
    while (i<=n-1)
    {
        if (*(arr+i) != 0)
        {
            return false;
        }
        else
        {
            i++;
        }
    }
    return true;
}

void instakill(int* arrOpp, int* arrSelf, int const &n)
{
    int iOpp = 0;
    int iSelf = 0;

    cout<<"Choose target index: ";
    cin>>iOpp;
    while (*(arrOpp + iOpp) == 0 || iOpp >= n)
    {
        cout<<"Target not valid, choose another element: ";
        cin>>iOpp;
    }

    cout<<"Choose your sacrifice: ";
    cin>>iSelf;
    while (*(arrSelf + iSelf) == 0 || iSelf >= n)
    {
        cout<<"Sacrifice not valid, choose another element: ";
        cin>>iSelf;
    }

    *(arrOpp + iOpp) = 0;
    *(arrSelf + iSelf) = 0;
}

void multiDamage(int *arr, int const &i, int &x)
{
    int y = rollDie();
    cout<<"The bonus rolled: "<<y<<endl;
    x = x*y;
    cout<<"Critical damage: "<<x<<endl;
    *(arr+i) -= x;
}

void carpetBomb(int *arr, int const &n)
{
    int i = 0;
    while (i<=n-1)
    {
        *(arr+i) -=  3;
        i++;
    }
    cout<<"Bombs Away!"<<endl;
}

void equivalence(int* arrOpp, int* arrSelf, int const &n, int const &x)
{
    int i = 0;
    while (i<=n-1)
    {
        if (*(arrSelf+i) != 0)
        {
            *(arrSelf+i) -= x/2;
        }

        if (*(arrOpp+i) != 0)
        {
            *(arrOpp+i) -= x;
        }
        i++;
    }
    cout<<"Equivalence Achieved."<<endl;
}

void attack(int *arr, int &x, int const &n, int const &bonus, int* arrSelf, int const &round)
{
    int i=0;
    cout<<endl<<"Choose the index where you want to attack: ";
    cin>>i;

    while (*(arr+i)==0 || i>=n || i<0) 
    {
        if (*(arr+i)==0)
        {
            cout<<"Choose another index, this is already destroyed: ";
        }
        else
        {
            cout<<"Choose another index, this index does not exist in this array: ";
        }    
        cin>>i;
    }
    
    x = rollDie();

    cout<<endl<<"--------------------------------------------- Your roll is: "<<x<<" ---------------------------------------------"<<endl<<endl;

    if (bonus%3 == x%3 || round >=7)
    {
        cout<<"You got a critical roll! Choose your bonus: "<<endl<<"No Bonus (0): Continue with your original roll."<<endl<<"Kamikaze (1): Terminate any one of the opponent's elements at the cost of one of your own."<<endl;
        cout<<"Multi-Damage (2): You get another roll, which is multiplied with your current roll for a damage bonus."<<endl;
        cout<<"Carpet Bomb (3): Every element of your opponent is damaged by 3."<<endl;
        cout<<"Equivalence (4): Every element of your opponent is damaged by "<<x<<" in exchange of damaging all of your elements by "<<x/2<<'.'<<endl;

        int crit = 0;
        cin>>crit;
        cout<<endl;

        if (crit == 0)
        {
            cout<<"No bonus chosen."<<endl;
            *(arr+i) = *(arr+i) - x;
        }
        else if (crit == 1)
        {
            instakill(arr, arrSelf, n);
        }
        else if (crit == 2)
        {
            multiDamage(arr, i, x);
        }
        else if (crit == 3)
        {
            carpetBomb(arr, n);
        }
        else if (crit == 4)
        {
            equivalence(arr, arrSelf, n, x);
        }
        else
        {
            cout<<"Invalid bonus chosen, dealing normal roll damage."<<endl;
            *(arr+i) = *(arr+i) - x;
        }    
    }
    else
    {
        *(arr+i) = *(arr+i) - x;
    }
    
    negPrevent(arr, n);
    negPrevent(arrSelf, n);
    
    cout<<endl;
}

void fortify(int* arr, int const &n)
{
    int i=0;
    while (i<=n-1)
    {
        if (*(arr+i) == 0)
        {
            i++;
        }
        else
        {
            *(arr+i) += 2;
            i++;
        }
    }
    cout<<"Fortification complete."<<endl;
}

void reconstruct(int* arr, int const &n, int const &x)
{
    int i=0;
    cout<<"Choose index of element to be reconstructed: ";
    cin>>i;

    int bug=1;

    while (*(arr+i) != 0 || i>=n)
    {
        cout<<"Element invalid, choose another index: ";
        cin>>i;
        bug++;

        if (bug==7)
        {
            cout<<"Reconstruction failed."<<endl;
            break;
        }
    }

    if (bug != 7)
    {
        *(arr+i) = x;
        cout<<"Reconstruction complete."<<endl;    
    }
}

void replicate(int* arr, int const &n, int const &I)
{
    int i=0;
    cout<<"Choose index of element to add value from: ";
    cin>>i;

    while (*(arr+i) == 0 || i>=n)
    {
        cout<<"Element invalid, choose another index: ";
        cin>>i;
    }

    *(arr+I) += *(arr+i);
    cout<<"Replication complete."<<endl;

    if (i==I)
    {
        cout<<"Special Activation: Self Buff!"<<endl;
    }
}


void defend(int *arr, int &x, int const &n, int const &bonus, int const &round, bool &shroudSwitch)
{
    int i=0;
    cout<<endl<<"Choose the index you want to defend: ";
    cin>>i;

    while (*(arr+i)==0 || i>=n || i<0)
    {
        if (*(arr+i)==0)
        {
            cout<<"Choose another index, this is already destroyed: ";
        }
        else
        {
            cout<<"Choose another index, this index does not exist in this array: ";
        }    
        cin>>i;
    }
    
    x = rollDie();
    cout<<endl<<"--------------------------------------------- Your roll is: "<<x<<" ---------------------------------------------"<<endl<<endl;

    if (bonus%3 == x%3 || round >= 7)
    {
        cout<<"You got a critical roll! Choose your bonus: "<<endl<<"No Bonus (0): Continue with your original roll."<<endl<<"Shroud (1): Makes your array invisible for the next round."<<endl;
        cout<<"Fortify (2): Increase all of your (non-destroyed) array elements by 2."<<endl;
        cout<<"Reconstruct (3): Bring back a destroyed element, it will be reconstructed with your current dice roll value."<<endl;
        cout<<"Replicate (4): Add the value of another element of yours to the element at your current index."<<endl;

        int crit = 0;
        cin>>crit;
        cout<<endl;

        if (crit == 0)
        {
            cout<<"No bonus chosen."<<endl;
            *(arr+i) = *(arr+i) + x;
        }
        else if (crit == 1)
        {
            shroudSwitch = true;
            cout<<"Shroud activated. Will take effect from the next round."<<endl;
        }
        else if (crit == 2)
        {
            fortify(arr, n);
        }
        else if (crit == 3)
        {
            reconstruct(arr, n, x);
        }
        else if (crit == 4)
        {
            replicate(arr, n, i);
        }
        else
        {
            cout<<"Invalid bonus chosen, doing normal roll defense."<<endl;
            *(arr+i) = *(arr+i) + x;
        }
    }
    else
    {
        *(arr+i) = *(arr+i) + x;
    }
}