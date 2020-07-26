#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include "Answer.h"
#include "TextAnswer.h"
#include "BooleanAnswer.h"
#include "OneAnswerCorrect.h"
#include "Solution.h"

using namespace std;

/**
 * The class is used to store three different types of questions.
 * 
 * Fields:
 * m_TextAnswer stores the text answer in string format.
 * m_BoolAnswer stores the answer in format of boolean.
 * m_CharAnswer stores the answer in choices which user picks between printed choices.
 * 
 * @method SetQuestionId() 
 *    a simple setter that sets the question id.
 * @param id (int)
 * @return void
 * 
 * @method GetQuestionId() 
 *    a simple getter which returns the question id in integer format.
 * @param void
 * @return int
 * 
 * @method SetQuestion() 
 *    a simple setter that sets the string question.
 * @param question (string)
 * @return void
 * 
 * @method GetQuestion() 
 *    a simple getter that returns the string question.
 * @param void
 * @return string
 * 
 * @method SetQuestionType() 
 *    a simple setter that sets the type of a question(true/false, multiple choice and text).
 *    It is necessary to have it in order to detect question type before present it to the user.
 * @param type (string)
 * @return void
 * 
 * @method GetQuestionType() 
 *    a simple getter that returns the question type in string format.
 * @param void
 * @return string
 * 
 * @method ShowQuestion() 
 *    a pure virtual method that is implemented in the child classes in order to print
 *    question with its id(and its choices).
 * @param void
 * @return void
 * 
 * @method GetNumberOfChoices() 
 *    a simple pure virtual getter method that is implemented to prints number of choices in 
 *    MultipleChoiceQuestion class.
 * @param void
 * @return int
 * 
 */

class Question
{
protected:
    int m_QuestionId;
    string m_Question;
    string m_Type;

public:
    Question();
    void SetQuestionId(int id);
    int GetQuestionId() { return m_QuestionId; }
    void SetQuestion(string question);
    string GetQuestion() { return m_Question; }
    void SetQuestionType(string type);
    string GetQuestionType() { return m_Type; }

    virtual ~Question();
    virtual void ShowQuestion() = 0;
    virtual int GetNumberOfChoices() = 0;
};

#endif