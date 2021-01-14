#ifndef MROS2_MROS2_H
#define MROS2_MROS2_H

#include <string>
#include "rtps/rtps.h"


namespace mros2 {

    class Node//TODO: move to node.h/cpp?
    {
    public:
        static Node create_node();
        void create_subscription(
            std::string node_name,
            int qos,
            int callback
        );
        std::string node_name;
        rtps::Participant* part;

    private:
       
    };


    void init(int argc, char *argv);
    void spin();

    void setTrue(void *args);void setTrue(void *args);
    void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange);
    void message_callback(void* callee, const rtps::ReaderCacheChange& cacheChange);

    #ifdef __cplusplus
    extern "C" {
    #endif
    void mros2_init(void *arg);
    #ifdef __cplusplus
    }
    #endif
}//namespace mros2
#endif //MROS2_MROS2_H
