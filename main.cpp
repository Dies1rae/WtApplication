#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WTheme.h>
#include <Wt/WCssTheme.h>
#include <Wt/WBootstrap2Theme.h>
#include <Wt/WBootstrap3Theme.h>
#include <Wt/WBootstrap5Theme.h>
#include <iostream>

#include "MainApp.h"

using namespace Wt;

std::unique_ptr<WApplication> createApplication(const Wt::WEnvironment& env) {
    auto app = std::make_unique<mainApp>(env);
    const std::string *themePtr = env.getParameter("theme");
    std::string theme;
    if (!themePtr) {
        theme = "bootstrap5";
    } else {
        theme = *themePtr;
    }
    if (theme == "bootstrap5") {
        auto bootstrapTheme = std::make_shared<WBootstrap5Theme>();
        app->setTheme(bootstrapTheme);
    } else if (theme == "bootstrap3") {
        auto bootstrapTheme = std::make_shared<WBootstrap3Theme>();
        bootstrapTheme->setResponsive(true);
        app->setTheme(bootstrapTheme);
        app->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");
    } else if (theme == "bootstrap2") {
        auto bootstrapTheme = std::make_shared<WBootstrap2Theme>();
        bootstrapTheme->setResponsive(true);
        app->setTheme(bootstrapTheme);
    } else {
        app->setTheme(std::make_shared<WCssTheme>(theme));
    }

    app->setTitle("GZ Coupon interface");
    app->useStyleSheet("./style/Theme.css");
    return app;
}

int main(int argc, char **argv) {
    return Wt::WRun(argc, argv, &createApplication);
}
