#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
private:
    string m_UserNickname;
    int m_Score;

public:
    User();
    void SetUserNickname(string nickname);
    string GetUserNickname() { return m_UserNickname; }
    void SetScore(int score);
    void ResetScore();
    int GetScore() { return m_Score; }
    ~User();
};

#endif