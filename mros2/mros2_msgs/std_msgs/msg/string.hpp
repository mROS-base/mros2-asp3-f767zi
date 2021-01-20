#include <string>
#include "rtps/rtps.h"

namespace std_msgs{
    namespace msg {
        class String
        {
            public:
                std::string getTypeName();
                std::string data;
                void copyToBuf(uint8_t *addrPtr){
                    uint32_t size = data.size();
                    memcpy(addrPtr, &size, 4);
                    addrPtr += 4;
                    memcpy(addrPtr, data.c_str(),size);
                    addrPtr += size;
                    *addrPtr = 0;
                    //buf_index += size;
                }
                uint8_t getTotalSize(){
                    return (5 + data.size());
                }
                static intptr_t deserialize(const rtps::ReaderCacheChange& cacheChange, uint8_t *recv_buf) {
                    uint32_t msg_size;
                    memcpy(&msg_size, &cacheChange.data[4], 4);
                    std_msgs::msg::String *msg = (std_msgs::msg::String *)recv_buf;
                    msg->data.resize(msg_size);
                    memcpy(&msg->data[0], &cacheChange.data[8], msg_size);
                    return (intptr_t)msg;
                }
            private:
                std::string type_name = "std_msgs::msg::dds_::String";
        };
    }//namspace msg
}//namespace std_msgs

namespace message_traits
{

template<>
struct TypeName<std_msgs::msg::String>
{
    static const char* value()
    {
        return "std_msgs::msg::dds_::String_";
    }
};

}
