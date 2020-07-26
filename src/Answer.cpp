#include "Answer.h"
#include <iostream>

using namespace std;

Answer::Answer(/* args */)
{
    m_AnswerId = 0;
}

void Answer::SetAnswerId(int id){
    m_AnswerId = id;
}

Answer::~Answer()
{
}