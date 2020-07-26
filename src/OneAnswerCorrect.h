#ifndef ONEANSWERCORRECT_H
#define ONEANSWERCORRECT_H

#include "Answer.h"

/**
 * The class is derived from the base class Answer which holds an answer of multiple choice question.
 * 
 * @method SetAnswer() 
 *    a simple setter that has a char parameter. It sets the field of m_CharAnswer in the base class Answer.
 * @param answer (char)
 * @return void
 * 
 * @method GetAnswer() 
 *    a simple getter that returns the m_CharAnswer in a string form.
 * @param void
 * @return string
 * 
 * @method ShowAnswer() 
 *    pure virtual method from the base class Answer. It prints answer id and the answer.
 * @param void
 * @return void
 */

class OneAnswerCorrect : public Answer
{
public:
    OneAnswerCorrect();
    void SetAnswer(char answer);
    string GetAnswer()
    {
        string s;
        s.push_back(m_CharAnswer);
        return s;
    }
    virtual void ShowAnswer();
    ~OneAnswerCorrect();
};

#endif