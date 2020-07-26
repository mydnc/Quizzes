#ifndef QUIZOMATiC_H
#define QUIZOMATIC_H

#include <iostream>
#include <vector>
#include "FileHandling.h"
#include "Answer.h"
#include "Solution.h"
#include "Question.h"
#include "MenuItems.h"
#include "User.h"

using namespace std;

/**
 * The class is used to interact with the user by displaying of a menu and gets information of a user
 * (such as nickname). Class loads sections and asks user answers of each question one by one in 
 * 3 sections which are dependent to each other. After every section class evaluates the section(s) 
 * and determines if user can continue with next section or fails because of less amount of correct 
 * answers. Then class allows user to see his/her brief score or detailed result.
 * 
 * Fields:
 * inFile is the instance which provides functionalities such as load questions, load solutions, 
 * print score table and print result table from related files by providing it correct paths.
 * 
 * m_Menu in an instance of the Menu class which is responsible with printing banner, intro menu,
 * and warnings.
 * 
 * m_MenuChoce is the field which holds user's validated navigation inputs in the menu.
 * 
 * m_User is an instance of the User class which is responsible wit holding users nickname and user
 * score.
 * 
 * m_SectionLevel is the field that holds the current level of a section.
 * 
 * m_Failed is a bool field which holds the state of failure from any section.
 * 
 * m_QuizTaken is a bool field which holds the state of retaking the test as a new user.
 * 
 * m_PathSection fields hold paths of section of questions.
 * 
 * m_PathSectionSolution fields hold paths of solutions of each section.
 * 
 * m_Question is a vector of question pointers which is responsible with containing the three different
 * types of questions to ask the user.
 * 
 * m_Solution is a vector of solutions that store solutions. This vector is necessary to evaluate quiz
 * with comparing answers from the user.
 * 
 * m_Answer is a vector of answer pointers which contains answer of each question from the user.
 * 
 * @method SetSectionLevel() 
 *    setter which determines the section level after a decision based on an integer score.
 * @param score (int)
 * @return void
 * 
 * @method GetSectionLevel() 
 *    a simple getter that returns the section level in integer format.
 * @param void
 * @return int
 * 
 * @method SetFailure() 
 *    a simple setter which sets the state of failure.
 * @param failed (bool)
 * @return void
 * 
 * @method GetFailure() 
 *    a simple getter that returns the failure state in boolean format.
 * @param void
 * @return bool
 * 
 * @method SetQuizStatus() 
 *    a simple setter which sets the state of quiz after taken previous failed quiz or 
 *    cancelled quiz.
 * @param quizTaken (bool)
 * @return void
 * 
 * @method GetQuizStatus() 
 *    a simple getter that returns the state of quiz.
 * @param void
 * @return bool
 * 
 * @method Interaction() 
 *    Method that includes menu and allow the user make choices. In this method, based of user decision,
 *    user can enter a nickname, start a quiz, finish a quiz, performs show score table and show result
 *    table. Also, validations of menu choices done in this method. 
 * @param void
 * @return void
 * 
 * @method LoadSection() 
 *    method that loads the related section by providin it section level. it returns false in case of
 *    any problem of loading questions or solutions. Otherwise returns true.
 * @param sectionLevel (int)
 * @return bool
 * 
 * @method StartQuiz() 
 *    method that prints questions and gets answers one by one. Also validations of answers done in
 *    this method.
 * @param void
 * @return void
 * 
 * @method RemoveExtraSpaces() 
 *    method that removes extra whitespaces from given text answer.
 * @param string (string)
 * @return void
 * 
 * @method EvaluateSection() 
 *    method that evaluates a finished quiz by comparing given answers and solutions. After evaluation
 *    method uses inFile method to write users score and detailed result to the file.
 * @param void
 * @return void
 * 
 * @method ClearContainers() 
 *    method which performs delete on vector of Question and Answer pointers one by one and . This method
 *    called when user successfuly finishes the quiz, cancel attending next section or fails the section
 *    in order to use containers for new questions, answers and solutions.
 * @param void
 * @return void
 * 
 */

class QuizOMatic
{
private:
    FileHandling inFile;
    MenuItems m_Menu;
    string m_MenuChoice;
    User m_User;
    int m_SectionLevel;
    bool m_Failed;
    bool m_QuizTaken;
    const string m_PathSection1 = "src/sections/section1.txt";
    const string m_PathSection2 = "src/sections/section2.txt";
    const string m_PathSection3 = "src/sections/section3.txt";
    const string m_PathSectionSolutions1 = "src/sections/sectionAnswers1.txt";
    const string m_PathSectionSolutions2 = "src/sections/sectionAnswers2.txt";
    const string m_PathSectionSolutions3 = "src/sections/sectionAnswers3.txt";
    vector<Question *> m_Question;
    vector<Solution> m_Solution;
    vector<Answer *> m_Answer;

public:
    QuizOMatic();
    void SetSectionLevel(int score);
    int GetSectionLevel() { return m_SectionLevel; }
    void SetFailure(bool failed);
    bool GetFailure() { return m_Failed; }
    void SetQuizStatus(bool quizTaken);
    bool GetQuizStatus() { return m_QuizTaken; }
    void Interaction();
    bool LoadSection(int sectionLevel);
    void StartQuiz();
    void RemoveExtraSpaces(string &string);
    void EvaluateSection();
    void ClearContainers();
    ~QuizOMatic();
};

#endif