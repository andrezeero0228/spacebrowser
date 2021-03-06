#ifndef DB_DBGROUP_H_
#define DB_DBGROUP_H_

#include <db/Backend.h>
#include <db/DbClient.h>
#include <db/Config2.h>
#include <db/Keys2.h>
#include <db/Passwords2.h>
#include <db/ScriptBlock2.h>
#include <db/Tabs2.h>

#include <memory>

namespace db
{

struct DbGroup
{
    using GroupMap = std::map<QString, std::shared_ptr<DbGroup>>;

    db::Backend& backend;
    db::DbClient dbc;
    db::Config2 config;
    db::Keys2 keys;
    db::Passwords2 pwds;
    db::ScriptBlock2 scb;
    db::Tabs2 tabs;

    static void createGroup(QString dbName, QString schemaName, Backend& backend);
    static std::shared_ptr<DbGroup> getGroup(QString dbName);
    static GroupMap& getGroupMap();

private:
    static GroupMap groups;

    DbGroup(QString dbName, QString schemaName, Backend& _backend);
};

}

#endif
