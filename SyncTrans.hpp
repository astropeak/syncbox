#ifndef SYNCTRANS_H
#define SYNCTRANS_H

class SyncTrans {
public:
    int execute(const string& client, const FileID& server) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        int status = itsChk->execute();
        if (status == CLIENT_NEW) {
            cout<<" Client new, push it to server"<<endl;
            itsFile->write(client, server);
        } else if (status == SERVER_NEW){
            cout<<" Server new, pull it to client"<<endl;
            itsFile->read(server, client);
        } else {
            cout<<" Equal, do nothing"<<endl;
        }
    }
    SyncTrans(File* file, Checker* chk):itsFile(file), itsChk(chk) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // do nothing
    }
private:
    Checker* itsChk;
    File* itsFile;
};

#endif /* SYNCTRANS_H */