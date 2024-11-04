#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

class Rules
{
    int points;
    bool isUsed;


    void score(int score)
    {
        if(isUsed != false)
        {
            points = score;
            isUsed = true;
        }
    }
};



// rolls 5 die for random value between 1 to 6.
void intDicerolling(int Dices[])
{
    srand(time(0));
    for(int i = 0; i < 5; i++)
    {
        Dices[i] = rand() % 6 + 1;
        cout << "the value is " << Dices[i] << "for dice"<< i << endl;
    }
    reroll(Dices);
}
// rerolls each die for random value between 1 to 6
void reroll(int Dices[])
{
    int requestedNumber;
    for(int i = 0; i < 5; i++)
    {
        cout << "do you want to reroll dice"<<i+1<< "? 1 = yes, 0 = no";
        cin >> requestedNumber;
        if(requestedNumber == 1)
        {
        Dices[1] = requestedNumber;
        cout << "rerolled die" << (i+1) << " to:" << Dices[i] << endl;
        }
    }
}

void initiliazeDices(int Dices[])
{
    for (int i = 0; i < 5; i++)
    {
        Dices[i] = 0;
    }
}

int main()
{
    int dices[5];
    initiliazeDices(dices);
    int arrNumSpelare[4];
    // number of rules;
    intDicerolling(dices);

    return 0;
}