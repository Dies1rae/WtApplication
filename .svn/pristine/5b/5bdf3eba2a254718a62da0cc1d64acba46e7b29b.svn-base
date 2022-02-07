#include <Wt/WApplication.h>
#include <Wt/WLogger.h>
#include <Wt/Dbo/WtSqlTraits.h>

#include "UserAccount.h"
#include "Entry.h"

using namespace Wt::Dbo;

userAccount::userAccount() { }

userAccount::userAccount(const WString& aName) : name(aName) { }

collection<ptr<Entry>> userAccount::entriesInRange(const WDate& from, const WDate& until) const {
    return entries.find().where("start >= ?").bind(WDateTime(from)).where("start < ?").bind(WDateTime(until));
}

ptr<userAccount> userAccount::login(Session& session, const WString& userName) {
    Transaction transaction(session);

    ptr<userAccount> ua = session.find<userAccount>("where name = ?").bind(userName);

    if (!ua) {
        WApplication::instance()->log("notice") << "Creating user: " << userName.toUTF8();
        ua = session.add(std::make_unique<userAccount>(userName));
    }

    transaction.commit();

    return ua;
}
