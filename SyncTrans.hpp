#ifndef SYNCTRANS_H
#define SYNCTRANS_H
#include <map>

static std::map<string, int> filePreviousStatus;
class SyncTrans {
public:
    int execute(const string& client, const FileID& server) {
        // cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        int status = itsChk.execute(client, server);
        // cout<<" check status: "<<status<<endl;
        if (status == CLIENT_NEW || status==CLIENT_ADDED) {
            cout<<"Client new or added, push it to server. ";
            cout<<"File: "<<server.getPath()<<endl;
            itsFile.write(client, server);
        } else if (status == SERVER_NEW || status==SERVER_ADDED){
            cout<<"Server new or added, pull it to client. ";
            cout<<"File: "<<server.getPath()<<endl;
            itsFile.read(server, client);
        } else if (status == CLIENT_DELETED){
            cout<<"CLient deleted, remove server side. ";
            cout<<"File: "<<server.getPath()<<endl;
            itsFile.remove(server);
            itsFile.remove(client); // call to remove version file.
        } else if (status == SERVER_DELETED){
            cout<<"Server deleted, remove client side. ";
            cout<<"File: "<<server.getPath()<<endl;
            itsFile.remove(client);
        } else if (status == BOTH_DELETED){
            if(filePreviousStatus[client] != status) {
                cout<<"Both deleted. remove current entry from list? ";
                cout<<"File: "<<server.getPath()<<endl;
            }
        } else if (status == EQUAL){
            if(filePreviousStatus[client] != status) {
                cout<<"Equal, do nothing. ";
                cout<<"File: "<<server.getPath()<<endl;
            }
        } else {
            cout<<"### ERROR ###, both changed ";
            cout<<"File: "<<server.getPath()<<endl;
        }

        filePreviousStatus[client]=status;
    }
    SyncTrans(File& file, Checker& chk):itsFile(file), itsChk(chk) {
        // cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // do nothing
    }
private:
    Checker& itsChk;
    File& itsFile;
};

#endif /* SYNCTRANS_H */