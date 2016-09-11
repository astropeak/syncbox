#ifndef PULLTRANS_H
#define PULLTRANS_H

#include "Checker.hpp"
#include "File.hpp"

class PullTrans {
public:
    int execute(void) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        if (itsChk->execute() == SERVER_NEW) {
            cout<<" Server new, pull it to local"<<endl;
            itsFile->read();
        } else {
            cout<<" Local new, do nothing"<<endl;
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