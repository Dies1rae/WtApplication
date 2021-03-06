#include <Wt/Dbo/backend/Sqlite3.h>

#include "MainApp.h"
#include "UserAccount.h"
#include "Entry.h"

mainApp::mainApp(const Wt::WEnvironment& env) : Wt::WApplication(env) {
    auto sqlite3 = std::make_unique<Wt::Dbo::backend::Sqlite3>(WApplication::appRoot() + "coupon_web.db");
    sqlite3->setProperty("show-queries", "true");
    session.setConnection(std::move(sqlite3));

    session.mapClass<userAccount>("user_account");
    session.mapClass<Entry>("entry");

    dbo::Transaction transaction(session);
    try {
        session.createTables();
        log("info") << "Database created";
    } catch (...) {
        log("info") << "Using existing database";
    }

    transaction.commit();
    messageResourceBundle().use(appRoot() + "login");
    messageResourceBundle().use(appRoot() + "mainpage");

    //this->user_acc_ = this->user_acc_ = userAccount::login(session, "root");
    //this->main_ptr_ = this->root()->addWidget(std::make_unique<mainPage>(this->user_acc_ ));
    this->login_ptr_ = root()->addWidget(std::make_unique<loginPage>());
    this->login_ptr_->loggedIn().connect(this, &mainApp::logIn);
}

void mainApp::logIn(const Wt::WString& user) {
    this->root()->clear();
    this->user_acc_ = userAccount::login(session, user);
    this->main_ptr_ = this->root()->addWidget(std::make_unique<mainPage>(this->user_acc_ ));
    if(this->isFirstLogin) {
        this->isFirstLogin = false;
        this->menuMain();
    }
    this->main_ptr_->refresh_ctr_ = this->refresh_ctr_;


    this->main_ptr_->exitMain().connect(this, &mainApp::logOut);
    this->main_ptr_->menuMain().connect(this, &mainApp::menuMain);
    this->main_ptr_->menuOne().connect(this, &mainApp::menuOne);
    this->main_ptr_->menuTwo().connect(this, &mainApp::menuTwo);
    this->main_ptr_->menuThree().connect(this, &mainApp::menuThree);
}

void mainApp::logOut() {
    //TODO return to LOGIN PAGE
    this->instance()->quit();
    this->user_acc_.flush();
    this->root()->clear();

    //This works fine, but i dont like it
    /*this->isFirstLogin = true;
    this->refresh_ctr_ = 0;
    this->user_acc_.flush();

    this->root()->clear();
    this->login_ptr_ = this->root()->addWidget(std::make_unique<loginPage>());
    this->login_ptr_->loggedIn().connect(this, &mainApp::logIn);*/
}

void mainApp::refresh(void) {
    this->refresh_ctr_++;
    this->root()->removeWidget(this->main_ptr_);
    this->root()->refresh();
    this->logIn(this->user_acc_->name);
}

void mainApp::menuMain(void) {
    this->refresh();
    this->main_ptr_->setMainPageContent();
}

void mainApp::menuOne(void) {
    this->refresh();
    this->main_ptr_->setMenuOneContent();
}

void mainApp::menuTwo(void) {
    this->refresh();
    this->main_ptr_->setMenuTwoContent();
}

void mainApp::menuThree(void) {
    this->refresh();
    this->main_ptr_->setMenuThreeContent();
}
