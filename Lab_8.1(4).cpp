// Lab_8.1(4).cpp
// Лабораторна робота № 8.1. Пошук та заміна символів у літерному рядку.
// Варіант 8. Використання стандартних функцій мови С++ для рядків string.
// Виконала: Кучер Софія.
//
// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Вияснити, чи є серед цих символів всі букви, що входять в слово "while".
// 2. Замінити кожну групу букв "while" парою зірочок "**".

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// чи входять до рядка s всі букви слова "while"
bool ContainsAllLetters(const string& s)
{
    const string letters = "while";

    for (size_t j = 0; j < letters.length(); j++)
        if (s.find(letters[j]) == string::npos)
            return false;
    return true;
}

// замінює кожну групу букв "while" парою зірочок "**";
// змінений рядок записується в параметр s і повертається як результат
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("while", pos)) != string::npos)
    {
        s.replace(pos, 5, "**");
        pos += 2;                 // продовжуємо пошук після вставлених зірочок
    }

    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    if (ContainsAllLetters(str))
        cout << "String contains all letters of \"while\"" << endl;
    else
        cout << "String does not contain all letters of \"while\"" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    system("pause");    // щоб вікно не закривалося одразу
    return 0;
}
