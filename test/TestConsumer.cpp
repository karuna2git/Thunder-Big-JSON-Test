#ifndef MODULE_NAME
#define MODULE_NAME TestConsumer
#endif /* MODULE_NAME */

#include <core/core.h>
#include <websocket/websocket.h>

MODULE_NAME_DECLARATION("MyTestConsumer")

using namespace WPEFramework;
using namespace std;

void onDataAvailable(const JsonObject& parameters)
{
    string sample;
    parameters.ToString(sample);
    printf ("Received %s\n", sample.c_str());
    return;
}

int main ()
{
    Core::SystemInfo::SetEnvironment(_T("THUNDER_ACCESS"), (_T("127.0.0.1:9998")));


    std::shared_ptr<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement>> jsonPlugin;
    jsonPlugin = make_shared<WPEFramework::JSONRPC::LinkType<WPEFramework::Core::JSON::IElement> >("TestPlugin.1", "");

    sleep(5); //TODO : Report separate issue to Thunder on this. ie Without the sleep here, the subscription always fails.

    jsonPlugin->Subscribe<JsonObject>(5000, _T("onDataAvailable"), &onDataAvailable);
    JsonObject parameters, response;
    jsonPlugin->Invoke<JsonObject, JsonObject>(5000, _T("StartPublishing"), parameters, response);

    while(1)
    {
        int opt = toupper(getchar());
        if ('Q' == opt)
            break;
    }
    return 0;
}
