#include "FileHandling.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include "Question.h"
#include "TextQuestion.h"
#include "MultipleChoiceQuestion.h"
#include "TrueFalseQuestion.h"
#include "QuizOMatic.h"
#include "MenuItems.h"

using namespace std;

FileHandling::FileHandling(/* args */)
{
}

void FileHandling::CheckScoreFile()
{
    inFile.open("src/log/ScoreBoard.txt");

    if (inFile.fail())
    {
        cout << "Score board file does not exist!" << endl;
        cout << "Seems like you run the Quiz-O-Matic for the first time or you've deleted the score table file." << endl;
        cout << "Creating new one.." << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(4000));

        CreateScoreFile();
    }

    inFile.close();
}

void FileHandling::CreateScoreFile()
{
    ofstream outFile("src/log/ScoreBoard.txt");

    outFile << "---------------" << endl;
    outFile << "--Score Table--" << endl;
    outFile << "---------------" << endl;
    outFile << endl;

    outFile.close();
}

void FileHandling::ShowScoreTable()
{
    CheckScoreFile();

    string temp = "";

    inFile.open("src/log/ScoreBoard.txt");

    while (getline(inFile, temp))
    {
        cout << temp << endl;
    }
    inFile.close();
    temp = "";
    cout << endl;
}

void FileHandling::CheckResultFile()
{
    inFile.open("src/log/ResultBoard.txt");

    if (inFile.fail())
    {
        cout << "Result board file does not exist!" << endl;
        cout << "Seems like you run the Quiz-O-Matic for the first time or you've deleted the score table file." << endl;
        cout << "Creating new one.." << endl;
        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(4000));

        CreateResultFile();
    }

    inFile.close();
}

void FileHandling::CreateResultFile()
{
    ofstream outFile("src/log/ResultBoard.txt");

    outFile << "----------------" << endl;
    outFile << "--Result Table--" << endl;
    outFile << "----------------" << endl;
    outFile << endl;

    outFile.close();
}

void FileHandling::ShowResultTable()
{
    CheckResultFile();

    string temp = "";

    inFile.open("src/log/ResultBoard.txt");

    while (getline(inFile, temp))
    {
        cout << temp << endl;
    }
    inFile.close();
    temp = "";
    cout << endl;
}

bool FileHandling::ReadQuestionsFromFile(string questionsPath, vector<Question *> &question)
{
    inFile.open(questionsPath);
    if (inFile.peek() == ifstream::traits_type::eof())
    {
        cout << "Error: Question file data corrupted." << endl;
        return false;
    }
    else if (inFile.fail())
    {
        cout << "Error: Cannot read questions from file!" << endl;
        return false;
    }
    else
    {
        int numberOfLinesText = 0,
            numberOfLinesTF = 0,
            numberOfLinesMultiple = 0;
        string temp = "";

        while (getline(inFile, temp))
        {
            if (temp == "!Text!")
            {
                TextQuestion *textQuestion = new TextQuestion;
                getline(inFile, temp);
                textQuestion->SetQuestionType("Text");
                textQuestion->SetQuestion(temp);
                textQuestion->SetQuestionId(numberOfLinesTF + numberOfLinesText + numberOfLinesMultiple + 1);
                question.push_back(textQuestion);
                temp = "";
                numberOfLinesText++;
            }
            else if (temp == "!True_False!")
            {
                TrueFalseQuestion *tfQuestion = new TrueFalseQuestion;
                getline(inFile, temp);
                tfQuestion->SetQuestionType("Boolean");
                tfQuestion->SetQuestion(temp);
                tfQuestion->SetQuestionId(numberOfLinesTF + numberOfLinesText + numberOfLinesMultiple + 1);
                question.push_back(tfQuestion);
                temp = "";
                numberOfLinesTF++;
            }
            else if (temp == "!Multiple_Choice!")
            {
                MultipleChoiceQuestion *mcQuestion = new MultipleChoiceQuestion;
                getline(inFile, temp);
                mcQuestion->SetQuestionType("Multiple Choice");
                mcQuestion->SetQuestion(temp);
                mcQuestion->SetQuestionId(numberOfLinesTF + numberOfLinesText + numberOfLinesMultiple + 1);
                while (temp != "*")
                {
                    getline(inFile, temp);

                    if (temp == "*")
                        break;
                    mcQuestion->SetChoices(temp);
                }
                question.push_back(mcQuestion);
                temp = "";
                numberOfLinesMultiple++;
            }
        }
        inFile.close();
        return true;
    }
}

bool FileHandling::ReadSolutionsFromFile(string solutionsPath, vector<Solution> &solution)
{
    string temp = "";
    inFile.open(solutionsPath);
    if (inFile.peek() == ifstream::traits_type::eof())
    {
        cout << "Error: Question file data corrupted." << endl;
        return false;
    }
    else if (inFile.fail())
    {
        cout << "Error: Cannot read questions from file!" << endl;
        return false;
    }
    else
    {
        int numberOfLinesAnswer = 0;
        while (getline(inFile, temp))
        {
            Solution a;
            a.SetSolution(temp);
            a.SetSolutionId(numberOfLinesAnswer + 1);
            solution.push_back(a);
            temp = "";
            numberOfLinesAnswer++;
        }
        inFile.close();
        return true;
    }
}

void FileHandling::WriteScoreToFile(string nickname, int score, int section)
{
    outFile.open("src/log/ScoreBoard.txt", ios_base::app);
    outFile << "Nickname: " << nickname << setw(20 - nickname.size()) << " Score: " << score << "  Section: " << section << endl;
    outFile.close();
}

void FileHandling::WriteResultToFile(string nickname, int score, int section,
                                     vector<Question *> &question,
                                     vector<Solution> &solution,
                                     vector<Answer *> &answer)
{
    outFile.open("src/log/ResultBoard.txt", ios_base::app);

    outFile << "Nickname: " << nickname << setw(18 - nickname.size()) << " Score: " << score << endl;
    outFile << "Section: " << section << endl;
    outFile << "Questions: " << endl;

    for (int i = 0; i < (int)question.size(); i++)
    {
        outFile << question[i]->GetQuestionId() << ":" << question[i]->GetQuestion() << endl;
    }
    outFile << endl;

    outFile << "Solutions: " << setw(35) << "Given Answers: " << endl;
    for (int i = 0; i < (int)solution.size(); i++)
    {
        outFile << solution[i].GetSolutionId() << ":" << solution[i].GetSolution() << setw(30 - solution[i].GetSolution().size()) << answer[i]->GetAnswerId() << ":" << answer[i]->GetAnswer() << endl;
    }
    outFile << endl;
    outFile << "#######################################################################################################" << endl;
    outFile << endl;

    outFile.close();
}

FileHandling::~FileHandling()
{
}