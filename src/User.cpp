#include "User.h"
#include <iostream>

using namespace std;

User::User()
{
    m_UserNickname = "";
    m_Score = 0;
}

void User::SetUserNickname(string nickname)
{
    m_UserNickname = nickname;
}

void User::SetScore(int score)
{
    m_Score += score;
}

void User::ResetScore()
{
    m_Score = 0;
}
User::~User()
{
}
