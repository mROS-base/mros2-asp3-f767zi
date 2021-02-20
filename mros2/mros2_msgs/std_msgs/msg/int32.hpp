#include <string>
#include "rtps/rtps.h"

namespace std_msgs{
    namespace msg {
        class Int32
        {
            public:
                std::string getTypeName();
                int data;
                void copyToBuf(uint8_t *addrPtr){
                    memcpy(addrPtr, &data, 4);
                    addrPtr += 4;
                    //buf_index += size;
                }
                uint8_t getTotalSize(){
                    return 4;
                }
                static intptr_t deserialize(const rtps::ReaderCacheChange& cacheChange, uint8_t *recv_buf) {
                    std_msgs::msg::Int32 *msg = (std_msgs::msg::Int32 *)recv_buf;
                    memcpy(&msg->data, &cacheChange.data[4], 4);
                    return (intptr_t)msg;
                }
            private:
                std::string type_name = "std_msgs::msg::dds_::Int32";
        };
    }//namspace msg
}//namespace std_msgs

namespace message_traits
{

template<>
struct TypeName<std_msgs::msg::Int32>
{
    static const char* value()
    {
        return "std_msgs::msg::dds_::Int32_";
    }
};

}
