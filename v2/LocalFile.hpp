#ifndef LOCALFILE_H
#define LOCALFILE_H
#include <cassert>
#include <string>
#include <boost/iostreams/stream.hpp>
#include "LocalFileDevice.hpp"

namespace io = boost::iostreams;
namespace ex = boost::iostreams::examplecc;

class LocalFile:public File{
public:
    LocalFile(){
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
    }
    ostream* getOstream(const string& path) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        return new io::stream<ex::LocalFileSink>(path.c_str());
    }
    istream* getIstream(const string& path) {
        cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<endl;
        return new io::stream<ex::LocalFileSource>(path.c_str());
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
};
#endif /* LOCALFILE_H */