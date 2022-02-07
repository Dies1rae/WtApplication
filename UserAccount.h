#ifndef USERACCOUNT_H
#define USERACCOUNT_H

/*
 * UserAccount class for Entry.h and mainApp
 * in fact class with data and methods to store in Dbo
 */

#include <Wt/WDate.h>
#include <Wt/WString.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/WtSqlTraits.h>

using namespace Wt;

class Entry;

namespace dbo = Wt::Dbo;

class userAccount
{
public:
    dbo::collection< dbo::ptr<Entry> > entries;

    userAccount(void);

    userAccount(const WString& name);

    dbo::collection<dbo::ptr<Entry>>

    entriesInRange(const WDate& from, const WDate& until) const;

    static dbo::ptr<userAccount> login(dbo::Session& session, const WString& user);

    template<class Action>
    void persist(Action& a) {
        dbo::field(a, name, "name");
        dbo::hasMany(a, entries, dbo::ManyToOne, "user");
    }

    WString name;
};

#endif // USERACCOUNT_H
