#include "BooleanAnswer.h"
#include <iostream>
#include <algorithm>

using namespace std;

BooleanAnswer::BooleanAnswer(/* args */)
{
    m_BoolAnswer = false;
}

void BooleanAnswer::SetAnswer(string answer)
{
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if (answer == "T" || answer == "TRUE")
    {
        m_BoolAnswer = true;
    }
    else if (answer == "F" || answer == "FALSE")
    {
        m_BoolAnswer = false;
    }
}

void BooleanAnswer::ShowAnswer()
{
    cout << GetAnswerId() << ": " << boolalpha << GetAnswer() << endl;
}

BooleanAnswer::~BooleanAnswer()
{
}