#include "Solution.h"
#include <iostream>

using namespace std;

Solution::Solution()
{
}

void Solution::SetSolutionId(int id)
{
    //do not forget validation
    m_SolutionId = id;
}
void Solution::SetSolution(string solution)
{
    //do not forget validation
    m_Solution = solution;
}

void Solution::ShowSolution()
{
    cout << GetSolutionId() << ":" << GetSolution() << endl;
}

Solution::~Solution()
{
}