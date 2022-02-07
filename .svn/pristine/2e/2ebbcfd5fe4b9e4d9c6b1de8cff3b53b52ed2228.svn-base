#include "MenuOne.h"

using namespace Wt;

menuOne::menuOne(dbo::ptr<userAccount> user) :  Wt::WContainerWidget(), user_(user)
{
    this->addWidget(std::make_unique<Wt::WText>("<h1> FIRST MENU </h1>"));
    this->initElems();

    auto clicked_main = [this]{
        this->back_main_page_.emit(true);
    };

    auto clicked_exit = [this]{
        this->logged_out_.emit(true);
    };

    auto clicked_menuOne = [this]{
        this->refresh_menu_one_.emit(true);
    };

    this->main_pg_btn_->clicked().connect(clicked_main);
    this->ext_btn_->clicked().connect(clicked_exit);
    this->menu1_btn_->clicked().connect(clicked_menuOne);
}

void menuOne::initElems(void) {
    this->setStyleClass("centered");

    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));
    this->main_pg_btn_ = this->addWidget(std::make_unique<Wt::WPushButton>("MAIN"));
    this->main_pg_btn_->setStyleClass("button");

    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));
    this->menu1_btn_ = this->addWidget(std::make_unique<Wt::WPushButton>("MENU 1"));
    this->menu1_btn_->setStyleClass("button");

    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));
    this->menu2_btn_ = this->addWidget(std::make_unique<Wt::WPushButton>("MENU 2"));
    this->menu2_btn_->setStyleClass("button");

    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));
    this->menu3_btn_ = this->addWidget(std::make_unique<Wt::WPushButton>("MENU 3"));
    this->menu3_btn_->setStyleClass("button");

    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));
    this->ext_btn_ = this->addWidget(std::make_unique<Wt::WPushButton>("EXIT"));
    this->ext_btn_->setStyleClass("button");
}

