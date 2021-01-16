#include <string>

namespace std_msgs{
    namespace msg {
        class String
        {
            public:
                std::string getTypeName();
                std::string data;
            private:
                std::string type_name = "std_msgs::msg::dds_::String";
        };
    }//namspace msg
}//namespace std_msgs

namespace message_traits
{

template<>
struct TypeName<std_msgs::msg::String*>
{
    static const char* value()
    {
        return "std_msgs::msg::dds_::String_";
    }
};

}
