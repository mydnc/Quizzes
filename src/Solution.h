#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>

using namespace std;

/**
 * The class is used to store solution with its id.
 * 
 * m_SolutionId is the filed keeps question id in integer format.
 * m_Solution is a sting which stores the solution of a question in a string format.
 * 
 * @method SetSolutionId() 
 *    a simple setter that sets the solution id.
 * @param id (int)
 * @return void
 * 
 * @method GetSolutionId() 
 *    a simple getter that returns the solution id.
 * @param void
 * @return int
 * 
 * @method SetSolution() 
 *    a simple setter that stores the solution in the field m_Solution.
 * @param solution (string)
 * @return void
 * 
 * @method GetSolution() 
 *    a simple getter which returns the solution in a string format.
 * @param void
 * @return string
 * 
 * @method ShowSolution() 
 *    method that prints the solution with its id.
 * @param void
 * @return void
 */

class Solution
{
private:
    int m_SolutionId;
    string m_Solution;

public:
    Solution();
    void SetSolutionId(int id);
    int GetSolutionId() { return m_SolutionId; }
    void SetSolution(string solution);
    string GetSolution() { return m_Solution; }
    void ShowSolution();
    ~Solution();
};

#endif