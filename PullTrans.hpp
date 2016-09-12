#ifndef PULLTRANS_H
#define PULLTRANS_H

#include "Checker.hpp"
#include "File.hpp"

class PullTrans {
public:
    int execute(void) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        int status = itsChk->execute();
        if (status == SERVER_NEW) {
            cout<<" Server new, pull it to local"<<endl;
            itsFile->read();
        } else if (status == CLIENT_NEW){
            cout<<" Local new, do nothing"<<endl;
        } else {
            cout<<" Equal, do nothing"<<endl;
        }
    }
    PullTrans(File* file, Checker* chk):itsFile(file), itsChk(chk) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // do nothing
    }
private:
    Checker* itsChk;
    File* itsFile;
};


#endif /* PULLTRANS_H */