#ifndef ENTRY_H
#define ENTRY_H

/*
 * Local DB class for store session info
 */

#include <Wt/WDateTime.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/WtSqlTraits.h>

using namespace Wt;

class userAccount;

namespace dbo = Dbo;

class Entry {
public:
    dbo::ptr<userAccount> user;

    WDateTime start;
    WDateTime stop;
    WString summary;
    WString text;

  template<class Action>
  void persist(Action& a) {
        dbo::belongsTo(a, user, "user");
        dbo::field(a, start, "start");
        dbo::field(a, stop, "stop");
        dbo::field(a, summary, "summary");
        dbo::field(a, text, "text");
  }
};
#endif // ENTRY_H
