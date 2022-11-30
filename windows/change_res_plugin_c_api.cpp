#include "include/change_res/change_res_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "change_res_plugin.h"

void ChangeResPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  change_res::ChangeResPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
