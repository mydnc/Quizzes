#ifndef TRUEFALSEQUESTION_H
#define TRUEFALSEQUESTION_H

#include "Question.h"

using namespace std;

/**
 * The class is derived from base class Question to store True/False question.
 * 
 * @method ShowQuestion() 
 *    a pure virtual method that is declared in the base class Question. The method prints
 *    true/false question with its id.
 * @param void
 * @return void
 */

class TrueFalseQuestion : public Question
{
public:
    TrueFalseQuestion();
    virtual void ShowQuestion();
    virtual void SetChoices(string choice);
    virtual int GetNumberOfChoices();
    ~TrueFalseQuestion();
};

#endif