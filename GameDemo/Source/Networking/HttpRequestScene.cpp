#include "HttpRequestScene.hpp"

USING_NS_AX;
using namespace ax::network;
using namespace std;

#define CHROME_UA                                                                                               \
    "User-Agent: Windows/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/112.0.0.0 " \
    "Safari/537.36"

bool HttpRequestScene::init()
{
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }
    setTitle("HTTP Request");

    _responseLabel = Label::createWithTTF("Response: ", "fonts/arial.ttf", 18);
    _responseLabel->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));
    this->addChild(_responseLabel);

    // HTTP GET request
    HttpRequest* request = new HttpRequest();
    request->setUrl("https://httpbin.org/ip");
    request->setRequestType(HttpRequest::Type::GET);
    request->setHeaders(std::vector<std::string>{CHROME_UA});
    request->setTag("GET test3");
    request->setResponseCallback(AX_CALLBACK_2(HttpRequestScene::onHttpResponse, this));
    HttpClient::getInstance()->send(request);
    request->release();

    return true;
}

void HttpRequestScene::onHttpResponse(ax::network::HttpClient* sender, ax::network::HttpResponse* response)
{
    string requestType    = response->getHttpRequest()->getRequestType() == HttpRequest::Type::GET ? "GET" : "POST";
    string responseString = "Response failed";
    if (response && response->isSucceed())
    {
        yasio::sbyte_buffer* data = response->getResponseData();
        responseString            = string(data->begin(), data->end());
    }
    string resString = "[" + requestType + "]" + "[Response]: " + responseString;
    AXLOG("%s", resString.c_str());
    printf("%s\n", resString.c_str());
    _responseLabel->setString(resString);
}