#ifndef VERSIONCHECKER_H
#define VERSIONCHECKER_H
#include "Version.hpp"
#include "Checker.hpp"

class VersionChecker:public Checker{
public:
    VersionChecker(Version& ver):itsVer(ver){}
    int execute(const string& client, const FileID& server) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SERVER_NEW;
        int vc=itsVer.read(CLIENT, server);
        int vs=itsVer.read(SERVER, server);
        if (vc>vs){
            return CLIENT_NEW;
        } else if(vc<vs){
            return SERVER_NEW;
        } else {
            return EQUAL;
        }
    }
private:
    Version& itsVer;
};

#endif /* VERSIONCHECKER_H */