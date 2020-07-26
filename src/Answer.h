#ifndef ANSWER_H
#define ANSWER_H

#include <iostream>

using namespace std;

/**
 * The class is used to store three different types of answers of related questions from the user.
 * 
 * Fields:
 * m_AnswerId holds the id of the answer in integer format.
 * m_TextAnswer stores the text answer in string format.
 * m_BoolAnswer stores the answer in format of boolean.
 * m_CharAnswer stores the answer in choices which user picks between printed choices.
 * 
 * @method GetAnswer() 
 *    is a pure vurtial function which is implemented in the child classes and returns answer.
 * @param void
 * @return answer in string format.
 * 
 * @method ShowAnswer() 
 *    is a pure vurtial function which is implemented in the child classes and prints answer with answer id.
 * @param void
 * @return void
 */

class Answer
{
protected:
    int m_AnswerId;
    string m_TextAnswer;
    bool m_BoolAnswer;
    char m_CharAnswer;

public:
    Answer();
    void SetAnswerId(int id);
    int GetAnswerId() { return m_AnswerId; }
    virtual string GetAnswer() = 0;
    virtual void ShowAnswer() = 0;
    virtual ~Answer();
};

#endif