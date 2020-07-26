#include "Question.h"
#include <iostream>
#include <string>

using namespace std;

Question::Question()
{
    m_QuestionId = 0;
    m_Question = "";
    m_Type = "";
}
void Question::SetQuestionId(int id)
{
    m_QuestionId = id;
}
void Question::SetQuestion(string question)
{
    m_Question = question;
}

void Question::SetQuestionType(string type){
    m_Type = type;
}

Question::~Question()
{
}