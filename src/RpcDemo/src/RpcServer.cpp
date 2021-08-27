#include <iostream>
#include "rpc/server.h"
#include "rpc/this_server.h"
#include "rpc/this_session.h"

struct DataRpc
{
    int a;
    float b;
    std::string c;
    MSGPACK_DEFINE_ARRAY(a, b, c)
};

std::string foo()
{
    std::cout << "foo was called!" << std::endl;
    return "hello world";
}

DataRpc transport(DataRpc ret)
{
    std::cout << "receive: " << ret.a << ' ' << ret.b << ' ' << ret.c << std::endl;
    ret.a = 1;
    ret.b = 2.2;
    ret.c = "haha";
    return ret;
}

int main(int argc, char *argv[])
{
    // Creating a server that listens on port 8080
    rpc::server srv(8080);

    // Binding the name "foo" to free function foo.
    // note: the signature is automatically captured
    srv.bind("foo", &foo);

    // Binding a lambda function to the name "add".
    srv.bind("add", [](int a, int b)
             { return a + b; });

    srv.bind("transport", &transport);

    // 停止服务器上的所有会话
    srv.bind("stop_server", []()
             { rpc::this_server().stop(); });

    // 会话表示服务器上的客户端连接，停止当前会话
    srv.bind("exit", []()
             { rpc::this_session().post_exit(); });

    // Run the server loop.
    srv.run();

    return 0;
}