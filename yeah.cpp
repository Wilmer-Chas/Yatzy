#include <iostream>
using namespace std;

typedef struct rule
{
    int points;
    bool crossed;
} rule;
void bubbleSort(int arr[], int n);
bool pairCheck(int input[]);
int chance(int input[]);

int main()
{
    int exampleroll[5] = {3, 2, 3, 5, 4};
    bubbleSort(exampleroll, 5);
    // this should output 1 but instead outputs 0, other than that my code works
    cout << pairCheck(exampleroll) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << exampleroll[i];
        if (i < 4)
        {
            cout << ", ";
        }
    }

    rule twoOfaKind = {0, 0};
    if (pairCheck(exampleroll) == true)
    {
        twoOfaKind.crossed = true;
        twoOfaKind.points = chance(exampleroll);
    }
    else
    {
        twoOfaKind.crossed = true;
    }
    cout << endl << twoOfaKind.crossed << twoOfaKind.points;
}

// yahtzee

bool pairCheck(int input[])
{
    int last = 0;
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
    {
        if (last == input[i])
        {
            return true;
        }
        last = input[i];
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