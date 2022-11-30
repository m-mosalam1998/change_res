#import "ChangeResPlugin.h"
#if __has_include(<change_res/change_res-Swift.h>)
#import <change_res/change_res-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "change_res-Swift.h"
#endif

@implementation ChangeResPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftChangeResPlugin registerWithRegistrar:registrar];
}
@end
