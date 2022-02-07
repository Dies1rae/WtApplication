#ifndef MAINAPP_H
#define MAINAPP_H

/*
 * This is main application class, in fact - brain of all project
 * his working in every time, listen signals, connect objects and change
 * main page state. So may be in some point we can build state machine in loop method
 */

#include <Wt/WApplication.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>

#include "UserAccount.h"
#include "LoginPage.h"
#include "MainPage.h"

class mainApp : public Wt::WApplication
{
public:
    Wt::Dbo::Session session;

    mainApp(const Wt::WEnvironment& env);

    static mainApp* mainPageInst() {
        return (mainApp*)WApplication::instance();
    }

    unsigned int refresh_ctr_ = 0;

private:
    void logIn(const Wt::WString& user);
    void logOut(void);
    void refresh(void);
    void menuMain(void);
    void menuOne(void);
    void menuTwo(void);
    void menuThree(void);

    bool                      isFirstLogin = true;
    loginPage *               login_ptr_ = nullptr;
    mainPage *                main_ptr_ = nullptr;
    dbo::ptr<userAccount>     user_acc_;
};

#endif // MAINAPP_H
