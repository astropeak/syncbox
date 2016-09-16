#ifndef EXISTVERSIONTIMESTAMPCHECKER_H
#define EXISTVERSIONTIMESTAMPCHECKER_H

#include "ExistChecker.hpp"

class ExistVersionTimeStampChecker:public Checker{
public:
    ExistVersionTimeStampChecker(ExistChecker& ex, VersionChecker& ver, TimeStampChecker& ts):
        itsEx(ex), itsVer(ver), itsTs(ts){}

    int execute(const string& client, const FileID& server) {
        // cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        int ex = itsEx.execute(client, server);
        VersionTimeStampChecker verTs(itsVer, itsTs);
        int vt = verTs.execute(client, server);
        int ver = itsVer.execute(client, server);
        // the logic seems complicated. Thanksfully I made this part independent!!
        // but maybe I can implement a simple one now only for test!!
        if (ex==CLIENT_EXIST) {
            if (ver==BOTH_NOT_EXIST) return CLIENT_ADDED;
            else return SERVER_DELETED;
        } else if (ex==SERVER_EXIST) {
            if (ver==SERVER_EXIST) return SERVER_ADDED;//client ver not exist,
            else return CLIENT_DELETED;
        } else if(ex==BOTH_EXIST){
            return vt;
        } else {
            return BOTH_DELETED;
        }
    }
private:
    VersionChecker& itsVer;
    TimeStampChecker& itsTs;
    ExistChecker& itsEx;
};

#endif /* EXISTVERSIONTIMESTAMPCHECKER_H */