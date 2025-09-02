#ifndef _HTTP_REQUEST_SCENE_HPP
#define _HTTP_REQUEST_SCENE_HPP

#include "axmol.h"
#include "Scenes/TemplateScene.hpp"
#include "network/HttpClient.h"

class HttpRequestScene : public TemplateScene
{
public:
    bool init() override;

private:
    ax::Label* _responseLabel;
    void onHttpResponse(ax::network::HttpClient* sender, ax::network::HttpResponse* response);

};

#endif // _HTTP_REQUEST_SCENE_HPP