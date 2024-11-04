#include <iostream>
using namespace std;

typedef struct rule
{
    int points;
    bool crossed;
} rule;
void bubbleSort(int arr[], int n);
void intDicerolling(int Dices[]);
void initiliazeDices(int Dices[]);
void reroll(int Dices[]);
bool pairCheck(int input[]);
int chance(int input[]);

int main()
{
    int dices[5];
    initiliazeDices(dices);
    int arrNumSpelare[4];
    // number of rules;
    intDicerolling(dices);
    bubbleSort(dices, 5);
    // this should output 1 but instead outputs 0, other than that my code works
    cout << pairCheck(dices) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << dices[i];
        if (i < 4)
        {
            cout << ", ";
        }
    }

    rule twoOfaKind = {0, 0};
    if (pairCheck(dices) == true)
    {
        twoOfaKind.crossed = true;
        twoOfaKind.points = chance(dices);
    }
    else
    {
        twoOfaKind.crossed = true;
    }
    cout << endl << twoOfaKind.crossed << twoOfaKind.points;
}

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

// yahtzee

bool pairCheck(int input[])
{

    for (int i = 0; i < 5; i++)
    {
        if (input[i] == input[i - 1])
        {
            return true;
        }
    }
    return false;
};

// implementation of a yatzee rule
// this is a fucking atrocious implementation because
// it does not do this in the way i actually want it to
int chance(int input[])
{ // tested, works
    int score = 0;
    for (int i = 0; i < 5; i++)
    {
        score += input[i];
    }
    return score;
};

// implementation of buble sort i stole off the internet
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
};

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);

                // swapped is set to true if the swap is
                // done
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
};