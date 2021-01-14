#ifndef MROS2_MROS2_H
#define MROS2_MROS2_H

#include <string>
#include "rtps/rtps.h"

namespace mros2 {

    class Node
    {
    public:
        std::string node_name;
    };
    void init(int argc, char *argv);
    void spin();

    void setTrue(void *args);void setTrue(void *args);
    void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange);
    void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange);
}//namespace mros2
#endif //MROS2_MROS2_H
