#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Question.h"
#include "MultipleChoiceQuestion.h"
#include "Answer.h"
#include "Solution.h"

using namespace std;

/**
 * The class is used to read questions and solutions from related files. Also, validates, creates and writes
 * score of a user and a full result of each section that user solved.
 * 
 * Fields:
 * inFile is an input file stream object that used for reading questions, solutions, score board and result board.
 * outFile is an output file stream object that used for saving scores and results of a user from quizzes.
 * 
 * @method CheckScoreFile() 
 *    checks if Score Board file exists or not. If not then calls CreateScoreFile() method to create new one
 *    with informing the user.
 * @param void
 * @return void
 * 
 * @method CreateScoreFile() 
 *    creates new Score Board file.
 * @param void
 * @return void
 * 
 * @method CheckResultFile() 
 *    checks if Result Board file exists or not. If not then calls CreateResultFile() method to create new one
 *    with informing the user.
 * @param void
 * @return void
 * 
 * @method CreateResultFile() 
 *    creates new Result Board file.
 * @param void
 * @return void
 * 
 * @method WriteScoreToFile()
 *    Writes user's nickname, score and passed section to score file in append mode.
 * @param nickname(string), score(int) and section(int).
 * @return void
 * 
 * @method WriteResultToFile()
 *    Writes user's nickname, score, passed section. Also questions that are already seen, solutions of related questions
 *    and answers from user to result file in append mode.
 * @param nickname(string), score(int), section(int), question(vector of question pointers), solution(vector of solution)
 *    and, answer(vector of answer pointers).
 * @return void
 * 
 * @method ShowScoreTable() 
 *    prints the score board file in a specific format.
 * @param void
 * @return void
 * 
 * @method ShowResultTable() 
 *    prints the result board file in a specific format.
 * @param void
 * @return void
 * 
 * @method ReadQuestionsFromFile() 
 *    Reads questions from files and stores them in to related instances. Also, validates if question file
 *    is empty. If yes then returns false otherwise true.
 * @param Path of a questions file(string) and question (vector of question pointers).
 * @return true if reading from file is successful otherwise false.
 * 
 * @method ReadSolutionsFromFile() 
 *    Reads solutions from files and stores them in to related instances. Also, validates if solution file
 *    is empty. If yes then returns false otherwise true.
 * @param Path of a solution file(string) and solution (vector of solution).
 * @return true if reading from file is successful otherwise false.
 * 
 */

class FileHandling
{
private:
    ifstream inFile;
    ofstream outFile;

public:
    FileHandling();
    void CheckScoreFile();
    void CreateScoreFile();
    void CheckResultFile();
    void CreateResultFile();
    void WriteScoreToFile(string nickname, int score, int section);
    void WriteResultToFile(string nickname, int score, int section,
                           vector<Question *> &question,
                           vector<Solution> &solution,
                           vector<Answer *> &answer);
    void ShowScoreTable();
    void ShowResultTable();
    bool ReadQuestionsFromFile(string questionsPath, vector<Question *> &question);
    bool ReadSolutionsFromFile(string solutionsPath, vector<Solution> &solution);
    ~FileHandling();
};

#endif