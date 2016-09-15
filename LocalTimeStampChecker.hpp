#ifndef LOCALTIMESTAMPCHECKER_H
#define LOCALTIMESTAMPCHECKER_H

#include <boost/filesystem.hpp>
#include "TimeStampChecker.hpp"
using namespace boost::filesystem;

class LocalTimeStampChecker:public TimeStampChecker{
public:
    static void setDestDir(const string& destDir){
        itsDestDir=destDir;
    }
    int execute(const string& client, const FileID& server) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SERVER_NEW;
        path p1(client);
        path p2(itsDestDir+"/"+server.getPath());

        std::time_t t1=-1, t2=-1;
        if (!exists(p1)) {
            cout<<" file not exists: "<<client<<endl;
            t1=-1;
        } else {
            t1=last_write_time(p1);
        }

        if (!exists(p2)){
            cout<<" file not exists: "<<server.getPath()<<endl;
            t2=-2;
        } else {
            t2=last_write_time(p2);
        }

        if (t1>t2){
            return CLIENT_NEW;
        } else if(t1<t2){
            return SERVER_NEW;
        } else {
            return EQUAL;
        }
    }
private:
    static string itsDestDir;
};

string LocalTimeStampChecker::itsDestDir;
#endif /* LOCALTIMESTAMPCHECKER_H */