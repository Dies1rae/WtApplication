
cmake_minimum_required(VERSION 3.10)

project(CouponWebSrv CXX)
set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(Wt REQUIRED Wt HTTP)
ADD_DEFINITIONS(-DHPDF_DLL)

set(CMAKE_CXX_FLAGS " -pthread -pipe -Wall -Werror=return-type")

# add the executable
add_executable (
  	WebSrv.wt
  	main.cpp
	LoginPage.cpp
	MainApp.cpp
	MainPage.cpp
	MenuOne.cpp
	UserAccount.cpp
)

# target libs
TARGET_LINK_LIBRARIES (
  	WebSrv.wt
    Wt::Wt
    Wt::HTTP
	Wt::Dbo
	Wt::DboSqlite3
	Wt::DboPostgres
	${EXAMPLES_DBO_LIBS}
)
  
INCLUDE_DIRECTORIES(${WT_SOURCE_DIR}/src)

