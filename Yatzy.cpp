#include <iostream>
using namespace std;

typedef struct rule
{
    int points;
    bool crossed;
} rule;

class Player
{
    public:
        string name;
        int score;
        bool combinationIsCrossed[16];
};

void bubbleSort(int arr[], int n);
void singleDigit(int input[], int requestedNumber, Player &player);
void pairCheck(int input[], Player &player);
void threeOfAKindCheck(int input[], Player &player);
void fourOfAKindCheck(int input[], Player &player);
int chance(int input[]);

int main()
{
    Player player;    
    int exampleroll[5] = {3, 2, 3, 5, 4};
    bubbleSort(exampleroll, 5);
    // this should output 1 but instead outputs 0, other than that my code works

    for (int i = 0; i < 5; i++)
    {
        cout << exampleroll[i];
        if (i < 4)
        {
            cout << ", ";
        }
    }
    cout << endl;
    cout << player.score << endl;
    pairCheck(exampleroll, player);
    cout << player.score << endl;

}

// yahtzee

void singleDigit(int input[], int requestedNumber, Player &player)
{
    int count = 0;
    if(player.combinationIsCrossed[requestedNumber - 1])
    {
        cout << "Combination already used. Please try something else." << endl;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (input[i] == requestedNumber)
        {
            player.score += input[i];
            player.combinationIsCrossed[requestedNumber - 1] = true;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Crossing " << requestedNumber << "'s with 0 score." << endl;
    }
    player.combinationIsCrossed[requestedNumber - 1] = true;    
    return;
}

void pairCheck(int input[], Player &player)
{
    int found = 0;
    if(player.combinationIsCrossed[6])
    {
        cout << "Combination already used. Please try something else." << endl;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (input[i] == input[i - 1])
        {
            player.score += input[i] * 2;
            found++;
        }
    }
    if(found == 0) cout << "Crossing pair with 0 score." << endl;
    player.combinationIsCrossed[6] = true;
    return;
};

void threeOfAKindCheck(int input[], Player &player)
{
    int found = 0;
    if (player.combinationIsCrossed[6] == true)
    {
        cout << "Combination already used. Please try something else." << endl;
        return;
    }
    
    for (int i = 0; i < 5; i++)
    {
        if (input[i] == input[i - 1] && input[i] == input[i - 2])
        {
            player.score += input[i] * 3;
            found++;
        }
    }
    if (found == 0)
        {
            cout << "Crossing three of a kind with 0 score." << endl;
        }
    player.combinationIsCrossed[7] = true;
    return;
};

void fourOfAKindCheck(int input[], Player &player)
{
    int found = 0;
    if (player.combinationIsCrossed[7])
    {
        cout << "Combination already used. Please try something else." << endl;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (input[i] == input[i - 1] && input[i] == input[i - 2] && input[i] == input[i - 3])
        {
            player.score += input[i] * 4;
        }
    }
    if (found == 0)
    {
        cout << "Crossing four of a kind with 0 score." << endl;
    }
    return;    
}


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