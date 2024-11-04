#include <iostream>
#include <vector>
using namespace std;

enum RuleIndex
{
    // sum of all dices showing 1, score is sum
    ONES, 
    // sum of all dices showing 2, score is sum
    TWOS,
    // sum of all dices showing 3, score is sum
    THREES,
    // sum of all dices showing 4, score is sum
    FOURS,
    // sum of all dices showing 5, score is sum
    FIVES,
    // sum of all dices showing 6, score is sum
    SIXES,
    // two dices showing the same number, score is the sum of the two dices
    ONE_OF_A_KIND,
    // three dices showing the same number score is the sum of all the dices.
    TWO_OF_A_KIND,
    // fource dices showing the same number score is the sum of all the dices.
    THREE_OF_A_KIND,
    // fource dices showing the same number score is the sum of all the dices.
    FOUR_OF_A_KIND,
    // the combination of 1, 2, 3, 4 , 5, score is 15 (sum of all dices)
    SMALL_STRAIGHT,
    // the combination of 2, 3, 4, 5, 6. score is 20 (sum of all dices)
    LARGE_STRAIGHT,
    // any set of the three combined with a different pair. score is sum of all dices
    FULLHOUSE,
    // chance: any combination of the dices: score is the sum of all dices.
    CHANCE,
    // yatzy all five dices showing the same number, score is 50
    YATZY
};

typedef struct rule
{
    int points;
    bool crossed;
} rule;

struct Player
{
    vector<rule> rules;
    Player() : rules(14, {0, false}) {};

};



void bubbleSort(int arr[], int n);
void intDicerolling(int Dices[]);
void initiliazeDices(int Dices[]);
void reroll(int Dices[]);
bool pairCheck(int input[]);
int chance(int input[]);

int main()
{
    int numPlayers;
    cout << "how many players shall play today";
    cin >> numPlayers;
    int dices[5];
    vector<Player> players (numPlayers); // create an object containing the number of players
    for (int turn = 0; turn < 13; turn++)
    {
        for(int i = 0; i < numPlayers; i++)
        {
            cout << "Player " << (i + 1) << "'s turn" << endl;
            initiliazeDices(dices);
            intDicerolling(dices);
            bubbleSort(dices, 5);

            evaluvateRules(players[i], dices); // evaluvates what rules are taken

            // need a way to display scores
        }
    }
    /*
    cout << pairCheck(dices) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << dices[i];
        if (i < 4)
        {
            cout << ", ";
        }
    }
    if (pairCheck(dices) == true)
    {
        twoOfaKind.crossed = true;
        twoOfaKind.points = chance(dices);
    }
    else
    {
        twoOfaKind.crossed = true;
    }
    cout << endl << twoOfaKind.crossed << twoOfaKind.points; */
}

void evaluvateRules(Player &player, int dices[])
{
    if(player.rules[ONES].crossed == false)
    {
        player.rules[ONES].points = scoreOnes(dices);
        player.rules[ONES].crossed = true;
    }
    if(player.rules[TWOS].crossed == false)
    {
        // add a scoring system
        player.rules[ONES].crossed = true;
    }
    if(player.rules[THREES].crossed == false)
    {
        // add a scoring system
        player.rules[ONES].crossed = true;
    }
    
}

int scoreOnes(const int dices[]) {
    int score = 0;
    for (int i = 0; i < 5; i++) {
        if (dices[i] == 1) {
            score += 1;
        }
    }
    return score;
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
    srand(time(0));
    int requestedNumber;
    for(int i = 0; i < 5; i++)
    {
        cout << "do you want to reroll dice"<<i+1<< "? 1 = yes, 0 = no";
        cin >> requestedNumber;
        if(requestedNumber == 1)
        {
        Dices[i] = rand() % 6 + 1;
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