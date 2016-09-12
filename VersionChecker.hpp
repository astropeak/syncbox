#ifndef VERSIONCHECKER_H
#define VERSIONCHECKER_H
#include "Version.hpp"

class VersionChecker:public Checker{
public:
    int execute(void) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        Version ver(itsDestDir, itsName, itsDir);
        int cv=ver.read(CLIENT);
        int sv=ver.read(SERVER);
        if (cv>sv) {
            return CLIENT_NEW;
        } else if (cv<sv) {
            return SERVER_NEW;
        } else {
            return EQUAL;
        }
    }

    VersionChecker(string& destDir, string& name, string& dir):Checker(destDir, name, dir){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
};



#endif /* VERSIONCHECKER_H */