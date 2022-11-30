#include "change_res_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h> 
#include <memory>
#include <sstream>


namespace change_res {

// static
void ChangeResPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "change_res",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<ChangeResPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

ChangeResPlugin::ChangeResPlugin() {}
std::map<std::string,int> ChangeResPlugin::getCurrentRes() {
   DEVMODE dm;
memset(&dm, 0, sizeof(dm));
dm.dmSize = sizeof(dm);
std::map<std::string,int> staffMap;
if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm)){
int width = dm.dmPelsWidth;
int high = dm.dmPelsHeight;

staffMap.insert(std::make_pair("width", width));
staffMap.insert(std::make_pair("hiegh", high));
}
return staffMap;

}

ChangeResPlugin::~ChangeResPlugin() {}
bool ChangeResPlugin::ChangeRes(int width,int high) {
  DEVMODE dm;
memset(&dm, 0, sizeof(dm));
dm.dmSize = sizeof(dm);

if (0 != EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm))
{
    
    dm.dmPelsWidth = width;
    dm.dmPelsHeight = high;

    LONG result = ChangeDisplaySettings(&dm, 0);
    if (result == DISP_CHANGE_SUCCESSFUL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
return false;
}

void ChangeResPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("changeReslutionScreen") == 0) {
    std::ostringstream version_stream;
        auto *arguments = std::get_if<flutter::EncodableMap>(method_call.arguments());

     auto width = std::get<int>(arguments->at(flutter::EncodableValue("width")));
    auto height = std::get<int>(arguments->at(flutter::EncodableValue("high")));
    std::cout<<width<<" X "<<height;
    std::map<std::string, int> data = getCurrentRes();
    if(data.empty()){
   version_stream << "";

    }else{
         version_stream << data["width"]<<",,"<<data["hiegh"];

    }
    ChangeRes(width,height);

    result->Success(flutter::EncodableValue(version_stream.str()));
  } else if(
    method_call.method_name().compare("getRes") == 0
  ){
    std::ostringstream version_stream;
    std::map<std::string, int> data = getCurrentRes();
    if(data.empty()){
   version_stream << "";

    }else{
         version_stream << data["width"]<<",,"<<data["hiegh"];

    }
    result->Success(flutter::EncodableValue(version_stream.str())); 
    }
  else{
    result->NotImplemented();

  }
}

}  // namespace change_res
