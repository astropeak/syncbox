#ifndef SYNCFILES_H
#define SYNCFILES_H

#include <vector>
#include <map>
#include "SyncTrans.hpp"

using namespace std;

class SyncFiles {
public:
    //files is the relative part file path name.
    SyncFiles(SyncTrans& st, vector<string>& files, string& dir):itsSt(st) {
        vector<string>::iterator iter=files.begin();
        while(iter!=files.end()){
            itsFiles[dir+"/"+*iter] = *iter;
            ++iter;
        }
    }

    int execute(void){
        // cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        map<string, string>::iterator iter = itsFiles.begin();
        while(iter != itsFiles.end()) {
            cout<<"\n### Sync file: "<<iter->first<<endl;
            itsSt.execute(iter->first, PathFileID(iter->second));
            ++iter;
        }
    }
private:
    map <string, string> itsFiles;
    SyncTrans& itsSt;
};

#endif /* SYNCFILES_H */