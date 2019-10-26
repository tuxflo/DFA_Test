//This is an example on a deterministic finite state machine with a 2D Array
//The machine accepts all words ending by the sequence "ananas" in a given string

#include <iostream>
#include <string>
using namespace std;

//The recursive function delta_hat represents the transition function
int delta_hat(int array[][7], std::string sigma, int state, std::string word, int error)
{
    int number = -1;
    if(word.empty())
        return state;
    for(int i=0; i< (int)sigma.length(); i++)   //the int cast is just to avoid a warning in gcc
    {
        if(sigma.at(i) == word.at(0))
            number = i;
    }
    if(number == -1)
    {
        for(int i=0; i< error; i++)
            cout << " ";
        cout << "^" << endl;
        cout << "word contents undefined symbol!" << endl;
        return -1;
    }
    state = array[number][state];
    word = word.substr(1, word.length()); //word is shortend by the first char
    return delta_hat(array, sigma, state, word, ++error);
}

int main()
{
                           //z0 z1 z2 z3 z4 z5 zE
    int array[3][7] = {/*a*/ {1, 1, 3, 1, 5, 1, 1},
                       /*n*/ {0, 2, 0, 4, 0, 4, 0},
                       /*s*/ {0, 0, 0, 0, 0, 6, 0}};

    std::string sigma = "ans";

    cout << "Please enter the word to check:" << endl;
    std::string word;
    cin >> word;

    int test = delta_hat(array, sigma, 0, word, 0);
    switch(test)
    {
    case -1:
        cout << "Error while parsing word" << endl;
        break;
    case 6:
       cout << "word accepted!" << endl;
        break;
    default:
        cout << "word not accepted!" << endl;
        break;
    }
    return 0;
}

