#ifndef LOGINPAGE_H_
#define LOGINPAGE_H_

/*
 * Separate page for Login users,
 * TODO create and connect authorization mechanism from another class
 */

#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WGroupBox.h>

class loginPage : public Wt::WContainerWidget
{
public:
    loginPage(void);

    Wt::Signal<Wt::WString>& loggedIn() {
        return this->logged_in_;
    }


private:
    //Credential  check mechanics
    bool credentionalVoidCheck(void) const;
    bool credentionalOKCheck(void) const;

    //Base initialization
    void initElems(void);

    Wt::Signal<Wt::WString>   logged_in_;
    Wt::WText               * login_status_;
    Wt::WLineEdit           * lgn_;
    Wt::WLineEdit           * psswd_;
    Wt::WPushButton         * lgn_btn_;
    Wt::WGroupBox           * main_bx_;
};

#endif // LOGINPAGE_H_
