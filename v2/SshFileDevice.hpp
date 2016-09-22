#ifndef SSHFILEDEVICE_H
#define SSHFILEDEVICE_H

#include <algorithm>                       // copy, min
#include <iosfwd>                          // streamsize
#include <boost/iostreams/categories.hpp>  // source_tag
#include <iostream>
#include <fstream>

namespace boost { namespace iostreams { namespace examplecc {
class SshFileSource {
public:
    typedef char  char_type;
    typedef source_tag                      category;
    SshFileSource(ssh_session session, const char* name):itsRead(false)
        {
          std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
          int r=prepareFetchFile(session, name, &itsScp);
          cout<<"itsScp: in consturctor"<<itsScp<<endl;
          if (r!=0){
            cout<<"Error: prepareFetchFile failed. "<<name<<endl;
          }
        }
    ~SshFileSource(){
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        //free and close itsScp
        // because this function will be called imediatlly 3 times after this object is created, so add a flag. This is only a workaround.
        if(itsRead){
            cout<<"close and free scp"<<endl;
            ssh_scp_close(itsScp);
            ssh_scp_free(itsScp);
        }
    }
    std::streamsize read(char_type* s, std::streamsize n)
    {
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        itsRead=true;
        // itsFile->read(s, n);

        cout<<"itsScp: "<<itsScp<<endl;
        std::cout<<"n: "<<n<<std::endl;
        int r=ssh_scp_read(itsScp,s,n);
        std::cout<<"n: "<<n<<", read count: "<<r<<std::endl;
        return r;
    }
    // Container& container() { return container_; }
private:
    ssh_scp itsScp;
    bool itsRead;
};

class SshFileSink {
public:
    typedef char  char_type;
    typedef sink_tag                      category;
    SshFileSink(ssh_session session, const char* name):itsWrite(false)
        {
          std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
          int r=prepareWriteFile(session, name, &itsScp);
          cout<<"itsScp: in consturctor"<<itsScp<<endl;
          if (r!=0){
            cout<<"Error: prepareWriteFile failed. "<<name<<endl;
          }
        }
    ~SshFileSink(){
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        // because this function will be called imediatlly 3 times after this object is created, so add a flag. This is only a workaround.
        if(itsWrite){
            cout<<"close and free scp"<<endl;
            ssh_scp_close(itsScp);
            ssh_scp_free(itsScp);
        }
        // delete itsFile;
    }
    std::streamsize write(const char_type* s, std::streamsize n)
    {
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        itsWrite=true;
        std::cout<<"n: "<<n<<std::endl;
        cout<<"itsScp: "<<itsScp<<endl;
        int rc = ssh_scp_write(itsScp, s, n);
        if (rc != SSH_OK){
            cout<<"Write fialed"<<endl;
            return -1;
        }
        return n;
    }
    // Container& container() { return container_; }
private:
    ssh_scp itsScp;
    bool itsWrite;
};
} } } // End namespace boost::iostreams:example


#endif /* SSHFILEDEVICE_H */