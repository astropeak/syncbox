#ifndef SYNCTRANS_H
#define SYNCTRANS_H
#include <map>

static std::map<string, int> filePreviousStatus;
class SyncTrans {
public:
    SyncTrans(File& file1, File& file2):itsFile1(file1), itsFile2(file2){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // do nothing
    }

    int execute(const string& path1, const string& path2){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        FileInfo fi1(itsFile1);
        FileInfo fi2(itsFile2);
        Checker chk(fi1, fi2);

        int status = chk.execute(path1, path2);
        cout<<" check status: "<<status<<endl;

        if (status == CLIENT_NEW || status==CLIENT_ADDED) {
            cout<<"Client new or added, push it to server. "<<endl;
            ostream* os= itsFile2.getOstream(path2);
            istream* is= itsFile1.getIstream(path1);
            (*os)<<is->rdbuf();
            delete is;
            delete os;
        } else if (status == SERVER_NEW || status==SERVER_ADDED){
            cout<<"Server new or added, pull it to client. ";
            // itsFile.read(server, client);
        } else if (status == CLIENT_DELETED){
            cout<<"CLient deleted, remove server side. ";
            // itsFile.remove(server);
            // itsFile.remove(client); // call to remove version file.
        } else if (status == SERVER_DELETED){
            cout<<"Server deleted, remove client side. ";
            // itsFile.remove(client);
        } else if (status == BOTH_DELETED){
            if(filePreviousStatus[path1] != status) {
                cout<<"Both deleted. remove current entry from list? ";
            }
        } else if (status == EQUAL){
            if(filePreviousStatus[path1] != status) {
                cout<<"Equal, do nothing. ";
            }
        } else {
            cout<<"### ERROR ###, both changed ";
        }

        filePreviousStatus[path1]=status;
    }
private:
    File& itsFile1;
    File& itsFile2;
};

#endif /* SYNCTRANS_H */