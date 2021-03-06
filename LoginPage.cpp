#include "LoginPage.h"

using namespace Wt;

loginPage::loginPage() : Wt::WContainerWidget() {
    this->initElems();
    this->login_status_ = this->addWidget(std::make_unique<Wt::WText>());

    auto greet = [this]{
        if(this->credentionalVoidCheck()) {
            this->login_status_->setText("login with name: " + this->lgn_->text() + ", and password: " + this->psswd_->text());
            if(this->credentionalOKCheck()) {
                this->login_status_->setText("LOGGED IN ...");
                logged_in_.emit(this->lgn_->text());
            } else {
                this->login_status_->setText("BAD LOGIN\\PASSWORD");
            }
        } else {
            this->login_status_->setText("Error, blanked credentials");
        }
    };
    this->lgn_btn_->clicked().connect(greet);
    this->enterPressed().connect(greet);
}


bool loginPage::credentionalVoidCheck(void) const {
    return !(this->lgn_->text().empty() || this->psswd_->text().empty());
}
bool loginPage::credentionalOKCheck(void) const {
    return (this->lgn_->text() == "root" && this->psswd_->text() == "123");
}

void loginPage::initElems(void) {
    this->main_bx_ = this->addWidget(std::make_unique<Wt::WGroupBox>("Login form"));
    this->main_bx_->setStyleClass("centered-example");

    auto txt_lg = this->main_bx_->addWidget(std::make_unique<Wt::WText>("<b>Login name </b>"));
    txt_lg->setStyleClass("text_lg");
    this->lgn_ = this->main_bx_->addWidget(std::make_unique<Wt::WLineEdit>());
    this->lgn_->setStyleClass("forms-inputs");
    this->main_bx_->addWidget(std::make_unique<Wt::WBreak>());
    auto txt_ps = main_bx_->addWidget(std::make_unique<Wt::WText>("<b>Password </b>"));
    txt_ps->setStyleClass("text_ps");
    this->psswd_ = this->main_bx_->addWidget(std::make_unique<Wt::WLineEdit>());
    this->psswd_->setStyleClass("forms-inputs");
    this->main_bx_->addWidget(std::make_unique<Wt::WBreak>());
    this->lgn_btn_ = this->main_bx_->addWidget(std::make_unique<Wt::WPushButton>("LOGIN"));
    this->lgn_btn_->setStyleClass("button");

    this->lgn_->setFocus();
}
