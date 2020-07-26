#include "MultipleChoiceQuestion.h"
#include <iostream>
#include <vector>

using namespace std;

MultipleChoiceQuestion::MultipleChoiceQuestion()
{
    m_NumberOfChoices = 0;
}

void MultipleChoiceQuestion::SetChoices(string choice){
    m_Choices.push_back(choice);
    m_NumberOfChoices++;
}

void MultipleChoiceQuestion::SetNumberOfChoices(int number){
    m_NumberOfChoices = number;
}

void MultipleChoiceQuestion::ShowQuestion(){
    cout << GetQuestionId() << ":" << GetQuestion() << "(Multiple Choice)" << endl;
    cout << endl;
    for (size_t i = 0; i < m_Choices.size(); i++)
    {
        cout << " " << char(65+i) << "-) " << m_Choices[i] << endl;
    }
    cout << endl;
    
}

MultipleChoiceQuestion::~MultipleChoiceQuestion()
{
    
}