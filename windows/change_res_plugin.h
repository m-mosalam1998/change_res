#ifndef FLUTTER_PLUGIN_CHANGE_RES_PLUGIN_H_
#define FLUTTER_PLUGIN_CHANGE_RES_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace change_res {

class ChangeResPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  ChangeResPlugin();

  virtual ~ChangeResPlugin();

  // Disallow copy and assign.
  ChangeResPlugin(const ChangeResPlugin&) = delete;
  ChangeResPlugin& operator=(const ChangeResPlugin&) = delete;
    
 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
  bool ChangeRes(int widgth,int high);
  std::map<std::string,int> getCurrentRes();
  
};

}  // namespace change_res

#endif  // FLUTTER_PLUGIN_CHANGE_RES_PLUGIN_H_
