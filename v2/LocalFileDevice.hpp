#include <algorithm>                       // copy, min
#include <iosfwd>                          // streamsize
#include <boost/iostreams/categories.hpp>  // source_tag
#include <iostream>
#include <fstream>

namespace boost { namespace iostreams { namespace examplecc {
// TODO: delete itsFile member in destructor. But seems the destructor will be called many times.
class LocalFileSource {
public:
    typedef char  char_type;
    typedef source_tag                      category;
    LocalFileSource(){
          std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
    }
    LocalFileSource(const char* name):itsFile(new std::ifstream(name))
        {
          std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
            // itsFile.open(name);
        }
    ~LocalFileSource(){
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        // delete itsFile;
    }
    std::streamsize read(char_type* s, std::streamsize n)
    {
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        itsFile->read(s, n);
        std::cout<<"n: "<<n<<", read count: "<<itsFile->gcount()<<", is open:"<<itsFile->is_open()<<std::endl;
        return itsFile->gcount();
    }
    // Container& container() { return container_; }
private:
    std::ifstream* itsFile;
};

class LocalFileSink {
public:
    typedef char  char_type;
    typedef sink_tag                      category;
    LocalFileSink(const char* name):itsFile(new std::ofstream(name))
        {
            std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
            // itsFile.open(name);
        }
    ~LocalFileSink(){
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        // delete itsFile;
    }
    std::streamsize write(const char_type* s, std::streamsize n)
    {
        std::cout<<__FILE__<<":"<<__LINE__<<", "<<__FUNCTION__<<std::endl;
        std::cout<<"n: "<<n<<", is open:"<<itsFile->is_open()<<std::endl;
        itsFile->write(s, n);
        itsFile->flush();
        return n;
    }
    // Container& container() { return container_; }
private:
    std::ofstream* itsFile;
};

} } } // End namespace boost::iostreams:example


 