#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include <iostream>
#include <vector>
#include "Question.h"

using namespace std;

/**
 * The class is used to store and shows multiple choice question which is child class of the Question class.
 * 
 * Fields:
 * m_Choices is a vector of string which keeps the choices of a multiple choce question.
 * m_NumberOfChoices is an integer field which stores how many choices a multiple question has.
 * 
 * @method SetChoices() 
 *    an implementation of a full virtual method from the base class Question. 
 *    It performs push_back on the vector m_Choices to store choices of a multiple choice question in the container.
 * @param choice (string).
 * @return void
 * 
 * @method SetNumberOfChoices() 
 *    a simple setter method to manipulate the field m_NumberOfChoices.
 * @param number (int).
 * @return void
 * 
 *  @method GetNumberOfChoices() 
 *    a simple implementation of a full vurtial method from the base class Question in order to get number of choices;
 * @param void
 * @return int
 * 
 *  @method ShowQuestion() 
 *    full virtual method from the base class Question that prints question id, question and its choices.
 * @param void
 * @return void
 * 
 */

class MultipleChoiceQuestion : public Question
{
private:
    vector<string> m_Choices;
    int m_NumberOfChoices;

public:
    MultipleChoiceQuestion();
    virtual void SetChoices(string choice);
    void SetNumberOfChoices(int number);
    virtual int GetNumberOfChoices() { return m_NumberOfChoices; }
    virtual void ShowQuestion();
    ~MultipleChoiceQuestion();
};

#endif