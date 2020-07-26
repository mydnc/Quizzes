#include "TextQuestion.h"

#include <iostream>

using namespace std;

TextQuestion::TextQuestion()
{
}

void TextQuestion::ShowQuestion()
{
    cout << GetQuestionId() << ":" << GetQuestion() << endl;
    cout << endl;
}

void TextQuestion::SetChoices(string choice)
{
    (void)choice;
}

int TextQuestion::GetNumberOfChoices()
{
    return 0;
}

TextQuestion::~TextQuestion()
{
}