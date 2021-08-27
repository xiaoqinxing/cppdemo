#include <iostream>
#include "rpc/client.h"
#include "rpc/rpc_error.h"

struct DataRpc
{
    int a;
    float b;
    std::string c;
    MSGPACK_DEFINE_ARRAY(a, b, c)
};

int main()
{
    try
    {
        // Creating a client that connects to the localhost on port 8080
        rpc::client client("127.0.0.1", 8080);

        // Calling a function with paramters and converting the result to int
        auto result = client.call("add", 2, 3).as<int>();
        std::cout << "The result is: " << result << std::endl;

        std::cout << client.call("foo").as<std::string>() << std::endl;

        DataRpc send = {2, 3.3, "send"};
        DataRpc ret = client.call("transport", send).as<DataRpc>();
        std::cout << ret.a << ' ' << ret.b << ' ' << ret.c << std::endl;

        ret = client.call("transport").as<DataRpc>();
        std::cout << ret.a << ' ' << ret.b << ' ' << ret.c << std::endl;

        client.call("stop_server");
    }
    catch (rpc::rpc_error &e)
    {
        std::cout << std::endl
                  << e.what() << std::endl;
        std::cout << "in function " << e.get_function_name() << ": ";

        using err_t = std::tuple<int, std::string>;
        auto err = e.get_error().as<err_t>();
        std::cout << "[error " << std::get<0>(err) << "]: " << std::get<1>(err)
                  << std::endl;
        return 1;
    }
    catch (const std::exception &t)
    {
        // will display a message like
        // rpc::timeout: Timeout of 50ms while calling RPC function 'sleep'
        std::cout << t.what() << std::endl;
    }

    return 0;
}