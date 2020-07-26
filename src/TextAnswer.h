#ifndef TEXTANSWER_H
#define TEXTANSWER_H

#include "Answer.h"

using namespace std;

/**
 * The class is derived from base class Answer to store text answer.
 * 
 * @method SetAnswer() 
 *    a simple setter that stores the answer in string format.
 * @param answer (string)
 * @return void
 * 
 * @method GetAnswer() 
 *    a simple getter that returns the text answer in string format.
 * @param void
 * @return string
 * 
 * @method ShowAnswer() 
 *    a pure virtual method that is declared in the base class Answer. The method prints
 *    text answer with its id.
 * @param void
 * @return void
 */

class TextAnswer : public Answer
{
public:
    TextAnswer();
    void SetAnswer(string answer);
    string GetAnswer() { return m_TextAnswer; }
    virtual void ShowAnswer();
    ~TextAnswer();
};

#endif