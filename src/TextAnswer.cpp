#include "TextAnswer.h"

TextAnswer::TextAnswer()
{
    m_TextAnswer = "";
}

void TextAnswer::SetAnswer(string answer)
{
    m_TextAnswer = answer;
}

void TextAnswer::ShowAnswer()
{
    cout << GetAnswerId() << ": " << GetAnswer() << endl;
}

TextAnswer::~TextAnswer()
{
}