#ifndef MENUITEMS_H
#define MENUITEMS_H

#include <iostream>

using namespace std;

/**
 * The class is used to print banner, menu choices and warnings.
 * 
 * @method ShowIntroMenu() 
 *    Prints informative intro menu. Menu leads user to solve new quiz, check score table and terminating the program.
 * @param void
 * @return void
 * 
 * @method ShowBanner()
 *    Prints a large banner of the program.
 * @param void
 * @return void
 * 
 * @method ShowGoToMainMenu()
 *    prints directions for user to go to main menu or quit the program.
 * @param void
 * @return void
 * 
 * @method ShowEmptyInputWarning()
 *    prints a warning about empty input.
 * @param void
 * @return void
 * 
 * @method ShowInvalidMenuChoice()
 *    prints a warning about wrong choice when user enters something irrelevant.
 * @param void
 * @return void
 * 
 * @method ShowCloseApplication()
 *    prints informative message which lets the user know that he/she terminated the program.
 * @param void
 * @return void
 * 
 */

class MenuItems
{
public:
    MenuItems();
    void ShowIntroMenu();
    void ShowBanner();
    void ShowGoToMainMenu();
    void ShowEmptyInputWarning();
    void ShowInvalidMenuChoice();
    void ShowCloseApplication();
    ~MenuItems();
};

#endif