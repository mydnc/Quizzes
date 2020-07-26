#include "OneAnswerCorrect.h"

OneAnswerCorrect::OneAnswerCorrect()
{
    m_CharAnswer = ' ';
}

void OneAnswerCorrect::SetAnswer(char answer){
    m_CharAnswer = answer;
}

void OneAnswerCorrect::ShowAnswer()
{
    cout << GetAnswerId() << ": " << GetAnswer() << endl;
}

OneAnswerCorrect::~OneAnswerCorrect()
{
}