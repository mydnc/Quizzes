#ifndef BOOLANSWER_H
#define BOOLANSWER_H

#include "Answer.h"

/**
 * The class is used to hold boolean answer of true/false question from the user.
 *
 * @method SetAnswer() 
 *    takes a string parameter and validates by uppercasing it. After comparing with a letter of "T"/"F" 
 *    or a word of "TRUE"/"FALSE" answer stores a boolean value.
 * @param string
 * @return void.
 * 
 * @method GetAnswer() 
 *    is a implementation of pure vurtial function from base class which returns a string after a boolean comparison.
 * @param void
 * @return answer in string format.
 * 
 * @method ShowAnswer() 
 *    is a implementation of pure vurtial function from base class which prints answer with answer id.
 * @param void
 * @return void
 */

class BooleanAnswer : public Answer
{
public:
    BooleanAnswer();
    void SetAnswer(string answer);
    virtual string GetAnswer() { return m_BoolAnswer ? "true" : "false"; }
    virtual void ShowAnswer();
    ~BooleanAnswer();
};

#endif