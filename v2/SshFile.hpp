#ifndef SSHFILE_H
#define SSHFILE_H
#include <libssh/libssh.h>
#include "scp/examples_common.h"
#include <cassert>
#include <string>
#include <boost/iostreams/stream.hpp>
#include "SshFileDevice.hpp"

namespace io = boost::iostreams;
namespace ex = boost::iostreams::examplecc;


class SshFile:public File{
public:
    SshFile(string host, int port, string idFile):
        itsHost(host), itsPort(port), itsIdFile(idFile){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        //connect to the host.
        //and should keep the connection.
        itsSession=connect_ssh(host.c_str(),NULL,0);
        if(itsSession == NULL){
            cout<<"Error: can't connect to host via ssh: "<<host<<endl;
        }

    };
    ~SshFile(){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        ssh_disconnect(itsSession);
        ssh_free(itsSession);
        ssh_finalize();
    }
    ostream* getOstream(const string& path) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SshOstream(path);
        return new io::stream<ex::SshFileSink>(itsSession, path.c_str());
    }
    istream* getIstream(const string& path) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        // return SshIstream(path);
        // todo: when free and close the itsScp?
        return new io::stream<ex::SshFileSource>(itsSession, path.c_str());
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
    ssh_session itsSession;
};

#endif /* SSHFILE_H */