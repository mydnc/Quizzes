#include "MenuItems.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;


MenuItems::MenuItems()
{
}

void MenuItems::ShowIntroMenu()
{
    cout << "Menu:" << endl;
    cout << "(1)Start a new General Knowledge Test." << endl;
    cout << "(2)Show Score Table." << endl;
    cout << "(3)Exit." << endl;
}

void MenuItems::ShowBanner()
{
    cout << string(150, '\n');
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "  ____            _                   ____             __  __           _     _        " << endl;
    cout << " / __ \\          (_)                 / __ \\           |  \\/  |         | |   (_)       " << endl;
    cout << "| |  | |  _   _   _   ____  ______  | |  | |  ______  | \\  / |   __ _  | |_   _    ___ " << endl;
    cout << "| |  | | | | | | | | |_  / |______| | |  | | |______| | |\\/| |  / _` | | __| | |  / __|" << endl;
    cout << "| |__| | | |_| | | |  / /           | |__| |          | |  | | | (_| | | |_  | | | (__ " << endl;
    cout << " \\___\\_\\  \\__,_| |_| /___|           \\____/           |_|  |_|  \\__,_|  \\__| |_|  \\___|" << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Welcome to \"General Knowledge Quizes\" console application!" << endl;
    cout << "Press any number in the menu and then hit the \"Enter\" button.." << endl;
    cout << endl;
}

void MenuItems::ShowGoToMainMenu()
{
    cout << "(1)Go to main menu." << endl;
    cout << "(2)Quit." << endl;
}

void MenuItems::ShowEmptyInputWarning()
{
    cout << "You did not chose any thing." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
}

void MenuItems::ShowInvalidMenuChoice()
{
    cin.clear();
    cout << "Invalid menu choice!" << endl;
    cout << "Enter only a valid choice that appears in the menu." << endl;
    this_thread::sleep_for(chrono::milliseconds(1200));
}

void MenuItems::ShowCloseApplication()
{
    cout << string(150, '\n');
    cout << "You have closed General Knowledge Test console application." << endl;
    cout << endl;
}

MenuItems::~MenuItems()
{
}