#ifndef SSHFILE_H
#define SSHFILE_H

class SshFile:public File{
public:
    SshFile(string host, int port, string idFile):
        itsHost(host), itsPort(port), itsIdFile(idFile){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        //connect to the host.
        //and should keep the connection.
    };
    ostream* getOstream(const string& path) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SshOstream(path);
    }
    istream* getIstream(const string& path) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SshIstream(path);
    }
    int remove(const string& path){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // remove path;
    }
    FileData getInfo(const string& path){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
    int setInfo(const string& path, int property, int value){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
private:
    string& itsHost;
    int itsPort;
    string& itsIdFile;
};

#endif /* SSHFILE_H */