#include "MainPage.h"

using namespace Wt;

mainPage::mainPage(dbo::ptr<userAccount> user) : Wt::WContainerWidget(), user_(user) {
    this->initElems();

    auto clicked_main = [this]{
        this->main_page_.emit(true);
    };
    auto clicked_exit = [this]{
        this->logged_out_.emit(true);
    };
    auto clicked_menu_one = [this]{
        this->menu_one_.emit(true);
    };
    auto clicked_two_one = [this]{
        this->menu_two_.emit(true);
    };
    auto clicked_three_one = [this]{
        this->menu_three_.emit(true);
    };

    ((Wt::WPushButton *)this->main_menu_->widget(0))->clicked().connect(clicked_main);
    ((Wt::WPushButton *)this->main_menu_->widget(1))->clicked().connect(clicked_menu_one);
    ((Wt::WPushButton *)this->main_menu_->widget(2))->clicked().connect(clicked_two_one);
    ((Wt::WPushButton *)this->main_menu_->widget(3))->clicked().connect(clicked_three_one);
    ((Wt::WPushButton *)this->main_menu_->widget(4))->clicked().connect(clicked_exit);
}

void mainPage::initElems(void) {
    this->setStyleClass("centered");

    this->user_name_wdgt_ = this->addWidget(createButton("topnav-a-username", "Username: " + this->user_->name));
    this->user_name_wdgt_->setDisabled(true);
    
    this->main_menu_ = this->addNew<Wt::WToolBar>();
    this->main_menu_->setStyleClass("topnav");
    this->main_menu_->addButton(createButton("topnav-a", "main menu"));
    this->main_menu_->addButton(createButton("topnav-a", "Menu 1"));
    this->main_menu_->addButton(createButton("topnav-a", "Menu 2"));
    this->main_menu_->addButton(createButton("topnav-a", "Menu 3"));
    this->main_menu_->addButton(createButton("topnav-a", "EXIT"));
}

std::unique_ptr<Wt::WPushButton> mainPage::createButton(const char * style, const Wt::WString& name) {
    auto button = std::make_unique<Wt::WPushButton>();
    button->setTextFormat(Wt::TextFormat::XHTML);
    button->setText(name);
    button->addStyleClass(style);
    return button;
}

void mainPage::leftMenuElems(std::unique_ptr<Wt::WContainerWidget>& lhs_ctr) {
    this->left_menu_ = lhs_ctr->addNew<Wt::WToolBar>();
    this->left_menu_->setStyleClass("leftnav");
    this->left_menu_->addButton(createButton("leftnav-a", "Sub_Menu 1"));
    this->left_menu_->addButton(createButton("leftnav-a", "Sub_Menu 2"));
    this->left_menu_->addButton(createButton("leftnav-a", "Sub_Menu 3"));
    this->left_menu_->addButton(createButton("leftnav-a", "Sub_Menu 4"));
    this->left_menu_->addButton(createButton("leftnav-a", "Sub_Menu 5"));
}

void mainPage::setMainPageContent(void) {
    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));

    this->container_main_ = std::make_unique<Wt::WContainerWidget>();
    this->container_main_->setStyleClass("row-main");

    auto container_left = std::make_unique<Wt::WContainerWidget>();
    container_left->setStyleClass("left-column-main");
    this->leftMenuElems(container_left);
    this->container_main_->addWidget(std::move(container_left));

    auto container_right = std::make_unique<Wt::WContainerWidget>();
    container_right->setStyleClass("right-column-main");
    auto MENU_RIGHT = std::make_unique<Wt::WText>("MAIN PAGE, REFRESH CTR = " + std::to_string(this->refresh_ctr_));

    MENU_RIGHT->setStyleClass("right-wgt-info");
    container_right->addWidget(std::move(MENU_RIGHT));
    this->container_main_->addWidget(std::move(container_right));

    this->addWidget(std::move(this->container_main_));
}

void mainPage::setMenuOneContent() {
    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));

    this->container_main_ = std::make_unique<Wt::WContainerWidget>();
    this->container_main_->setStyleClass("row-main");

    auto container_left = std::make_unique<Wt::WContainerWidget>();
    container_left->setStyleClass("left-column-main");
    auto MENU_LEFT = std::make_unique<Wt::WText>("SOME MENU BUTTONS");
    MENU_LEFT->setStyleClass("left-wgt-info");
    container_left->addWidget(std::move(MENU_LEFT));
    this->container_main_->addWidget(std::move(container_left));

    auto container_right = std::make_unique<Wt::WContainerWidget>();
    container_right->setStyleClass("right-column-main");
    auto MENU_RIGHT = std::make_unique<Wt::WText>("FIRST PAGE, REFRESH CTR = " + std::to_string(this->refresh_ctr_));
    MENU_RIGHT->setStyleClass("right-wgt-info");
    container_right->addWidget(std::move(MENU_RIGHT));
    this->container_main_->addWidget(std::move(container_right));

    this->addWidget(std::move(this->container_main_));
}

void mainPage::setMenuTwoContent(void) {
    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));

    this->container_main_ = std::make_unique<Wt::WContainerWidget>();
    this->container_main_->setStyleClass("row-main");

    auto container_left = std::make_unique<Wt::WContainerWidget>();
    container_left->setStyleClass("left-column-main");
    auto MENU_LEFT = std::make_unique<Wt::WText>("SOME MENU BUTTONS");
    MENU_LEFT->setStyleClass("left-wgt-info");
    container_left->addWidget(std::move(MENU_LEFT));
    this->container_main_->addWidget(std::move(container_left));

    auto container_right = std::make_unique<Wt::WContainerWidget>();
    container_right->setStyleClass("right-column-main");
    auto MENU_RIGHT = std::make_unique<Wt::WText>("SECOND PAGE, REFRESH CTR = " + std::to_string(this->refresh_ctr_));
    MENU_RIGHT->setStyleClass("right-wgt-info");
    container_right->addWidget(std::move(MENU_RIGHT));
    this->container_main_->addWidget(std::move(container_right));

    this->addWidget(std::move(this->container_main_));
}

void mainPage::setMenuThreeContent(void) {
    this->addWidget(std::make_unique<Wt::WText>("<br></br>"));

    this->container_main_ = std::make_unique<Wt::WContainerWidget>();
    this->container_main_->setStyleClass("row-main");

    auto container_left = std::make_unique<Wt::WContainerWidget>();
    container_left->setStyleClass("left-column-main");
    auto MENU_LEFT = std::make_unique<Wt::WText>("SOME MENU BUTTONS");
    MENU_LEFT->setStyleClass("left-wgt-info");
    container_left->addWidget(std::move(MENU_LEFT));
    this->container_main_->addWidget(std::move(container_left));

    auto container_right = std::make_unique<Wt::WContainerWidget>();
    container_right->setStyleClass("right-column-main");
    auto MENU_RIGHT = std::make_unique<Wt::WText>("THIRD PAGE, REFRESH CTR = " + std::to_string(this->refresh_ctr_));
    MENU_RIGHT->setStyleClass("right-wgt-info");
    container_right->addWidget(std::move(MENU_RIGHT));
    this->container_main_->addWidget(std::move(container_right));

    this->addWidget(std::move(this->container_main_));
}
