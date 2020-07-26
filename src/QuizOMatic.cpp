#include "QuizOMatic.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include <bits/stdc++.h>
#include "FileHandling.h"
#include "MenuItems.h"

using namespace std;

QuizOMatic::QuizOMatic()
{
    m_MenuChoice = "";
    m_SectionLevel = 0;
    m_Failed = false;
    m_QuizTaken = false;
}

void QuizOMatic::SetSectionLevel(int score)
{
    if (score >= 0 && score < 50)
    {
        m_SectionLevel = 1;
    }
    else if (score >= 50 && score < 100 && GetSectionLevel() == 1)
    {
        m_SectionLevel = 2;
    }
    else if (score >= 100 && GetSectionLevel() == 2)
    {
        m_SectionLevel = 3;
    }
    else
    {
        m_SectionLevel = 0;
    }
}

void QuizOMatic::SetFailure(bool failed)
{
    m_Failed = failed;
}

void QuizOMatic::SetQuizStatus(bool quizTaken)
{
    m_QuizTaken = quizTaken;
}

void QuizOMatic::Interaction()
{
    while (1)
    {
        m_MenuChoice = "*";
        cout << string(150, '\n');
        m_Menu.ShowBanner();
        m_Menu.ShowIntroMenu();
        getline(cin, m_MenuChoice);
        if (m_MenuChoice.size() > 1)
        {
            m_MenuChoice = "*";
            m_Menu.ShowInvalidMenuChoice();
            continue;
        }
        else if (m_MenuChoice == "1")
        {
            m_MenuChoice = "*";
            while (1)
            {
                string nickname = "*";
                cout << string(150, '\n');
                cout << "Once you enter your nickname the first section will start immediately! :)" << endl;
                cout << endl;
                cout << "Enter your nickname (Max 10 characters): ";
                getline(cin, nickname);
                if (nickname.size() > 10)
                {
                    cout << "Nickname is too long!" << endl;
                    cout << "Keep it shorter than 10 characters.." << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    continue;
                }
                else if (nickname.empty())
                {
                    cout << "You did not enter a nickname!" << endl;
                    cout << "At least try something funny.." << endl;
                    this_thread::sleep_for(chrono::milliseconds(1800));
                }
                else
                {
                    nickname.erase(remove_if(nickname.begin(), nickname.end(), ::isspace), nickname.end());
                    m_User.SetUserNickname(nickname);
                    m_User.SetScore(0);
                    break;
                }
            }
            inFile.CheckScoreFile();
            inFile.CheckResultFile();
            SetQuizStatus(false);
            SetSectionLevel(m_User.GetScore());
            if (LoadSection(GetSectionLevel()) == false)
            {
                break;
            }
            StartQuiz();
            EvaluateSection();

            while (!GetQuizStatus())
            {
                if (GetFailure())
                {
                    while (1)
                    {
                        SetFailure(false);
                        cout << string(150, '\n');
                        m_MenuChoice = "*";
                        cout << "You failed the section " << GetSectionLevel() << "." << endl;
                        m_Menu.ShowGoToMainMenu();
                        getline(cin, m_MenuChoice);

                        if (m_MenuChoice.empty())
                        {
                            m_Menu.ShowEmptyInputWarning();
                            continue;
                        }
                        else if (m_MenuChoice.size() > 1)
                        {
                            m_Menu.ShowInvalidMenuChoice();
                            continue;
                        }
                        else if (m_MenuChoice == "1")
                        {
                            m_MenuChoice = "*";
                            SetQuizStatus(true);
                            ClearContainers();
                            m_User.ResetScore();
                            break;
                        }
                        else if (m_MenuChoice == "2")
                        {
                            m_Menu.ShowCloseApplication();
                            return;
                        }
                        else
                        {
                            m_Menu.ShowInvalidMenuChoice();
                            continue;
                        }
                    }
                }
                else
                {
                    while (1)
                    {
                        if (GetSectionLevel() == 3 && !GetFailure())
                        {
                            m_MenuChoice = "*";
                            cout << string(150, '\n');
                            cout << "Total score: " << m_User.GetScore() << endl;
                            cout << endl;
                            cout << "Congragulations! You have completed the General Knowledge Test." << endl;
                            cout << endl;
                            cout << "(1)Go to main menu." << endl;
                            cout << "(2)Quit." << endl;
                            getline(cin, m_MenuChoice);
                            if (m_MenuChoice.empty())
                            {
                                m_MenuChoice = "*";
                                m_Menu.ShowEmptyInputWarning();
                                continue;
                            }
                            else if (m_MenuChoice.size() > 1)
                            {
                                m_MenuChoice = "*";
                                m_Menu.ShowInvalidMenuChoice();
                                continue;
                            }
                            else if (m_MenuChoice == "1")
                            {
                                m_MenuChoice = "*";
                                SetQuizStatus(true);
                                ClearContainers();
                                m_User.ResetScore();
                                break;
                            }
                            else if (m_MenuChoice == "2")
                            {
                                m_Menu.ShowCloseApplication();
                                return;
                            }
                            else
                            {
                                m_Menu.ShowInvalidMenuChoice();
                                continue;
                            }
                        }
                        else
                        {
                            cout << string(150, '\n');

                            m_MenuChoice = "*";
                            cout << "Total score: " << m_User.GetScore() << endl;
                            cout << "You have passed the section " << GetSectionLevel() << "!" << endl;
                            cout << "(1) Continue to section " << GetSectionLevel() + 1 << "." << endl;
                            cout << "(2) Finish the quiz and go to the main menu." << endl;
                            getline(cin, m_MenuChoice);
                            if (m_MenuChoice.empty())
                            {
                                m_MenuChoice = "*";
                                m_Menu.ShowEmptyInputWarning();
                                continue;
                            }
                            else if (m_MenuChoice.size() > 1)
                            {
                                m_MenuChoice = "*";
                                m_Menu.ShowInvalidMenuChoice();
                                continue;
                            }
                            else if (m_MenuChoice == "1")
                            {
                                ClearContainers();
                                SetSectionLevel(m_User.GetScore());
                                if (LoadSection(GetSectionLevel()) == false)
                                {
                                    break;
                                }
                                StartQuiz();
                                EvaluateSection();
                                if (GetFailure())
                                {
                                    break;
                                }
                            }
                            else if (m_MenuChoice == "2")
                            {
                                SetQuizStatus(true);
                                ClearContainers();
                                m_User.ResetScore();
                                break;
                            }
                            else
                            {
                                m_Menu.ShowInvalidMenuChoice();
                                continue;
                            }
                        }
                    }
                }
            }
        }
        else if (m_MenuChoice[0] == '2')
        {
            while (1)
            {
                m_MenuChoice = "*";
                cout << string(150, '\n');
                inFile.ShowScoreTable();
                cout << "(1) Go back to the menu." << endl;
                cout << "(2) See the results in detail." << endl;
                getline(cin, m_MenuChoice);

                if (m_MenuChoice.size() > 1)
                {
                    m_Menu.ShowInvalidMenuChoice();
                    continue;
                }
                else if (m_MenuChoice == "1")
                {
                    cin.clear();
                    break;
                }
                else if (m_MenuChoice == "2")
                {
                    while (1)
                    {
                        m_MenuChoice = "*";
                        cout << string(150, '\n');
                        inFile.ShowResultTable();
                        cout << "(1) Go back to the Score table." << endl;
                        getline(cin, m_MenuChoice);
                        if (m_MenuChoice.size() > 1)
                        {
                            m_Menu.ShowInvalidMenuChoice();
                            continue;
                        }
                        else if (m_MenuChoice == "1")
                        {
                            cin.clear();
                            break;
                        }
                        else if (m_MenuChoice.empty())
                        {
                            m_Menu.ShowEmptyInputWarning();
                            continue;
                        }
                        else
                        {
                            m_Menu.ShowInvalidMenuChoice();
                            continue;
                        }
                    }
                }
                else if (m_MenuChoice.empty())
                {
                    m_Menu.ShowEmptyInputWarning();
                    continue;
                }
                else
                {
                    m_Menu.ShowInvalidMenuChoice();
                    continue;
                }
            }
            m_Menu.ShowIntroMenu();
        }
        else if (m_MenuChoice == "3")
        {
            cout << string(150, '\n');
            cout << "You have closed General Knowledge Test console application." << endl;
            return;
        }
        else if (m_MenuChoice.empty())
        {
            m_Menu.ShowEmptyInputWarning();
            continue;
        }
        else
        {
            cin.clear();
            cout << "Invalid menu choice!" << endl;
            cout << "Enter only a valid choice: (1),(2) or (3)." << endl;
            this_thread::sleep_for(chrono::milliseconds(1200));
            continue;
        }
    }
}

bool QuizOMatic::LoadSection(int sectionLevel)
{
    switch (sectionLevel)
    {
    case 1:
        if (inFile.ReadQuestionsFromFile(m_PathSection1, m_Question) == false)
        {
            return false;
        }

        if (inFile.ReadSolutionsFromFile(m_PathSectionSolutions1, m_Solution) == false)
        {
            return false;
        }
        break;
    case 2:
        if (inFile.ReadQuestionsFromFile(m_PathSection2, m_Question) == false)
        {
            return false;
        }

        if (inFile.ReadSolutionsFromFile(m_PathSectionSolutions2, m_Solution) == false)
        {
            return false;
        }
        break;
    case 3:
        if (inFile.ReadQuestionsFromFile(m_PathSection3, m_Question) == false)
        {
            return false;
        }

        if (inFile.ReadSolutionsFromFile(m_PathSectionSolutions3, m_Solution) == false)
        {
            return false;
        }
        break;
    }
    return true;
}

void QuizOMatic::RemoveExtraSpaces(string &string)
{
    int n = string.length();
    int i = 0, j = -1;

    bool spaceFound = false;

    while (++j < n && string[j] == ' ');

    while (j < n)
    {
        if (string[j] != ' ')
        {
            if ((string[j] == '.' || string[j] == ',' || string[j] == '?') && i - 1 >= 0 && string[i - 1] == ' ')
            {
                string[i - 1] = string[j++];
            }
            else
            {
                string[i++] = string[j++];
            }
            spaceFound = false;
        }
        else if (string[j++] == ' ')
        {
            if (!spaceFound)
            {
                string[i++] = ' ';
                spaceFound = true;
            }
        }
    }

    if (i <= 1)
    {
        string.erase(string.begin() + i, string.end());
    }
    else
    {
        string.erase(string.begin() + i, string.end());
    }
}

void QuizOMatic::StartQuiz()
{
    string validate, tempAnswer;

    for (size_t i = 0; i < m_Question.size(); i++)
    {
        cin.clear();
        cout << string(150, '\n');

        if (m_Question[i]->GetQuestionType() == "Text")
        {
            TextAnswer *a = new TextAnswer;
            while (1)
            {
                m_Question[i]->ShowQuestion();
                cout << "Answer: ";
                getline(cin, tempAnswer);
                cin.clear();
                RemoveExtraSpaces(tempAnswer);
                if (tempAnswer.empty())
                {
                    cout << string(150, '\n');
                    m_Menu.ShowEmptyInputWarning();
                    cin.clear();
                }
                else
                {
                    a->SetAnswerId(m_Question[i]->GetQuestionId());
                    a->SetAnswer(tempAnswer);
                    m_Answer.push_back(a);
                    tempAnswer = "";
                    cin.clear();
                    break;
                }
            }
        }
        else if (m_Question[i]->GetQuestionType() == "Boolean")
        {
            BooleanAnswer *a = new BooleanAnswer;
            while (true)
            {
                cout << string(150, '\n');
                m_Question[i]->ShowQuestion();
                cout << "Answer: ";
                getline(cin, tempAnswer);
                validate = tempAnswer;
                transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
                if (validate == "T" || validate == "TRUE" ||
                    validate == "F" || validate == "FALSE")
                {
                    a->SetAnswerId(m_Question[i]->GetQuestionId());
                    a->SetAnswer(tempAnswer);
                    m_Answer.push_back(a);
                    tempAnswer = "";
                    validate = "";
                    cin.clear();
                    break;
                }
                else
                {
                    cout << string(150, '\n');
                    cout << "Invalid answer!" << endl;
                    cout << "Enter the answers in the following forms: \'T\',\'t\',\"True\" or \'F\',\'f\',\"False\"" << endl;
                    this_thread::sleep_for(chrono::milliseconds(1600));
                    cin.clear();
                }
            }
        }
        else if (m_Question[i]->GetQuestionType() == "Multiple Choice")
        {
            OneAnswerCorrect *a = new OneAnswerCorrect;
            while (true)
            {
                cout << string(150, '\n');
                m_Question[i]->ShowQuestion();
                cout << "Answer: ";
                getline(cin, tempAnswer);
                validate = tempAnswer;
                transform(validate.begin(), validate.end(), validate.begin(), ::toupper);
                if (validate.size() == 1)
                {
                    if (int(validate[0]) < 65 || int(validate[0]) >= m_Question[i]->GetNumberOfChoices() + 65)
                    {
                        cout << string(150, '\n');
                        cout << "Invalid answer!" << endl;
                        cout << "The letter you entered does not represent any of the choices." << endl;
                        cout << "Enter a letter that appears in the choices as an answer." << endl;
                        this_thread::sleep_for(chrono::milliseconds(2000));
                    }
                    else
                    {
                        a->SetAnswerId(m_Question[i]->GetQuestionId());
                        a->SetAnswer(tempAnswer[0]);
                        m_Answer.push_back(a);
                        tempAnswer = "";
                        validate = "";
                        cin.clear();
                        break;
                    }
                    cin.clear();
                }
                else
                {
                    cout << string(150, '\n');
                    cout << "Invalid answer!" << endl;
                    cout << "Enter a letter that appears in the choices as an answer." << endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    cin.clear();
                }
            }
        }
        cin.clear();
        cout << tempAnswer << endl;
    }
}

void QuizOMatic::EvaluateSection()
{
    string solution, answer;
    int tempScore = 0;

    for (size_t i = 0; i < m_Solution.size(); i++)
    {
        solution = m_Solution[i].GetSolution();
        answer = m_Answer[i]->GetAnswer();
        transform(solution.begin(), solution.end(), solution.begin(), ::toupper);
        transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
        if (solution == answer)
        {
            tempScore += 10;
        }
        solution = "";
        answer = "";
    }
    if (tempScore < 50)
    {
        SetFailure(true);
    }

    m_User.SetScore(tempScore);
    
    inFile.WriteScoreToFile(m_User.GetUserNickname(), m_User.GetScore(), GetSectionLevel());
    inFile.WriteResultToFile(m_User.GetUserNickname(), m_User.GetScore(),
                             GetSectionLevel(), m_Question,
                             m_Solution, m_Answer);
}

void QuizOMatic::ClearContainers()
{
    for (int i = 0; i < (int)m_Question.size(); i++)
    {
        delete m_Question[i];
    }
    for (int i = 0; i < (int)m_Answer.size(); i++)
    {
        delete m_Answer[i];
    }
    m_Question.clear();
    m_Answer.clear();
    m_Solution.clear();
}

QuizOMatic::~QuizOMatic()
{
    for (int i = 0; i < (int)m_Question.size(); i++)
    {
        delete m_Question[i];
    }
    for (int i = 0; i < (int)m_Answer.size(); i++)
    {
        delete m_Answer[i];
    }
}