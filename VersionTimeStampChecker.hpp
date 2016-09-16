#ifndef VERSIONTIMESTAMPCHECKER_H
#define VERSIONTIMESTAMPCHECKER_H

#include "Version.hpp"
#include "Checker.hpp"
#include "TimeStampChecker.hpp"
#include "VersionChecker.hpp"

class VersionTimeStampChecker:public Checker{
public:
    VersionTimeStampChecker(VersionChecker& ver, TimeStampChecker& ts):itsVer(ver), itsTs(ts){}
    int execute(const string& client, const FileID& server) {
        // cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SERVER_NEW;
        int vc = itsVer.execute(client, server);
        int tsc = itsTs.execute(client, server);
        if (vc == SERVER_NEW) {
            if (tsc == CLIENT_NEW) {
                cout<<" #### ERROR ####. Server version new, while client timestamp new. Return BOTH_NEW. (Manually merge needed)"<<endl;
                return BOTH_NEW;
            } else if (tsc==SERVER_NEW){
                cout<<" Server version new and time stamp new"<<endl;
                return SERVER_NEW;
            } else {
                cout<<" #### Warning ####. Server version new but timestamp the same. Return SERVER_NEW"<<endl;
                return SERVER_NEW;
            }
        } else if (vc == CLIENT_NEW){
            cout<<" #### ERROR ####. This is impossiable. Client version newer than server. Return result of time stamp."<<endl;
            return tsc;
        } else { //vc equal
            if (tsc==CLIENT_NEW){
                cout<<" Version the same, client time stamp new. Return CLIENT_NEW"<<endl;
                return CLIENT_NEW;
            } else if (tsc==SERVER_NEW) {
                cout<<" #### ERROR ####. Version the same, but server's time stamp new. Return SERVER_NEW"<<endl;
                return SERVER_NEW;
            } else { //tsc equal
                cout<<" Both version and time stamp the same. Return EQUAL"<<endl;
                return EQUAL;
            }
        }
    }
private:
    VersionChecker& itsVer;
    TimeStampChecker& itsTs;
};

#endif /* VERSIONTIMESTAMPCHECKER_H */