#include "TrueFalseQuestion.h"

TrueFalseQuestion::TrueFalseQuestion()
{
}

void TrueFalseQuestion::ShowQuestion()
{
    cout << GetQuestionId() << ":" << GetQuestion() << "(True/False)" << endl;
    cout << endl;
}

void TrueFalseQuestion::SetChoices(string choice)
{
    (void)choice;
}

int TrueFalseQuestion::GetNumberOfChoices(){
    return 0;
}

TrueFalseQuestion::~TrueFalseQuestion()
{
}