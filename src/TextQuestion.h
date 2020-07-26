#ifndef TEXTQUESTION_H
#define TEXTQUESTION_H

#include "Question.h"

using namespace std;

/**
 * The class is derived from base class Question to store text question.
 * 
 * @method ShowQuestion() 
 *    a pure virtual method that is declared in the base class Question. The method prints
 *    text question with its id.
 * @param void
 * @return void
 */

class TextQuestion : public Question
{
public:
    TextQuestion();
    virtual void SetChoices(string choice);
    virtual int GetNumberOfChoices();
    virtual void ShowQuestion();
    ~TextQuestion();
};

#endif