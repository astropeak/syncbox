#ifndef SYNCTRANS_H
#define SYNCTRANS_H

class SyncTrans {
public:
    int execute(const string& client, const FileID& server) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        int status = itsChk.execute(client, server);
        if (status == CLIENT_NEW || status==CLIENT_ADDED) {
            cout<<" Client new or added, push it to server"<<endl;
            itsFile.write(client, server);
        } else if (status == SERVER_NEW || status==SERVER_ADDED){
            cout<<" Server new or added, pull it to client"<<endl;
            itsFile.read(server, client);
        } else if (status == CLIENT_DELETED){
            cout<<" CLient deleted, remove server side"<<endl;
            itsFile.remove(server);
        } else if (status == SERVER_DELETED){
            cout<<" Server deleted, remove client side"<<endl;
            itsFile.remove(client);
        } else if (status == BOTH_DELETED){
            cout<<" Both deleted. remove current entry from list?"<<endl;
        } else if (status == EQUAL){
            cout<<" Equal, do nothing"<<endl;
        } else {
            cout<<" ### ERROR ###, both changed"<<endl;
        }
    }
    SyncTrans(File& file, Checker& chk):itsFile(file), itsChk(chk) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // do nothing
    }
private:
    Checker& itsChk;
    File& itsFile;
};

#endif /* SYNCTRANS_H */