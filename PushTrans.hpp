#ifndef PUSHTRANS_H
#define PUSHTRANS_H

class PushTrans {
public:
    int execute(const string& from, const FileID* to) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        int status = itsChk->execute();
        if (status == CLIENT_NEW) {
            cout<<" Client new, push it to server"<<endl;
            itsFile->write(from, to);
        } else if (status == SERVER_NEW){
            cout<<" Server new, do nothing"<<endl;
        } else {
            cout<<" Equal, do nothing"<<endl;
        }
    }
    PushTrans(File* file, Checker* chk):itsFile(file), itsChk(chk) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // do nothing
    }
private:
    Checker* itsChk;
    File* itsFile;
};

#endif /* PUSHTRANS_H */