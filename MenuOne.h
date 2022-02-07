#ifndef MENUONE_H
#define MENUONE_H

#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WGroupBox.h>
#include <Wt/Dbo/Dbo.h>

#include "UserAccount.h"

class menuOne : public Wt::WContainerWidget
{
public:
    menuOne(dbo::ptr<userAccount> user);

    void initElems(void);

    Wt::Signal<bool>& exitMain() {
        return this->logged_out_;
    }

    Wt::Signal<bool>& mainPage() {
        return this->back_main_page_;
    }

    Wt::Signal<bool>& menuOneRefresh() {
        return this->refresh_menu_one_;
    }

private:
    Wt::Signal<bool> logged_out_;
    Wt::Signal<bool> back_main_page_;
    Wt::Signal<bool> refresh_menu_one_;



    dbo::ptr<userAccount> user_;
    Wt::WPushButton * ext_btn_ = nullptr;
    Wt::WPushButton * main_pg_btn_ = nullptr;
    Wt::WPushButton * menu1_btn_ = nullptr;
    Wt::WPushButton * menu2_btn_ = nullptr;
    Wt::WPushButton * menu3_btn_ = nullptr;
};

#endif // MENUONE_H
