#ifndef MAINPAGE_H_
#define MAINPAGE_H_

/*
 *  Main page, primary container with all menu, widgets ...etc
 *  holds and call all signals to mainApp, renew data by commands from
 *  mainApp. In feature gets data from DB and work with couponlib
 */

#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WToolBar.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WGroupBox.h>

#include "UserAccount.h"

class mainPage : public Wt::WContainerWidget
{
public:
    mainPage(dbo::ptr<userAccount> user);  

    Wt::Signal<bool>& exitMain(void) {
        return this->logged_out_;
    }

    Wt::Signal<bool>& menuMain(void) {
        return this->main_page_;
    }

    Wt::Signal<bool>& menuOne(void) {
        return this->menu_one_;
    }

    Wt::Signal<bool>& menuTwo(void) {
        return this->menu_two_;
    }

    Wt::Signal<bool>& menuThree(void) {
        return this->menu_three_;
    }

    void setMainPageContent(void);
    void setMenuOneContent(void);
    void setMenuTwoContent(void);
    void setMenuThreeContent(void);

    int refresh_ctr_ = 0;
private:
    Wt::Signal<bool> logged_out_;
    Wt::Signal<bool> main_page_;
    Wt::Signal<bool> menu_one_;
    Wt::Signal<bool> menu_two_;
    Wt::Signal<bool> menu_three_;

    void initElems(void);

    void leftMenuElems(std::unique_ptr<Wt::WContainerWidget>& lhs_ctr);

    std::unique_ptr<Wt::WPushButton> createButton(const char * style, const Wt::WString& name);

    dbo::ptr<userAccount>                   user_;
    Wt::WToolBar *                          main_menu_ = nullptr;
    Wt::WToolBar *                          left_menu_ = nullptr;
    Wt::WPushButton *                       user_name_wdgt_ = nullptr;
    std::unique_ptr<Wt::WContainerWidget>   container_main_ = nullptr;
};

#endif // MAINPAGE_H_
