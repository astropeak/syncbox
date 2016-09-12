#ifndef TIMESTAMPCHECKER_H
#define TIMESTAMPCHECKER_H

#include "Checker.hpp"

class TimeStampChecker:public Checker{
public:
    int execute(void) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SERVER_NEW;
        return CLIENT_NEW;
    }
    TimeStampChecker(string& destDir, string& name, string& dir):Checker(destDir, name, dir){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
};

#endif /* TIMESTAMPCHECKER_H */