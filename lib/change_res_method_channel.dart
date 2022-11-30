import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'change_res_platform_interface.dart';

/// An implementation of [ChangeResPlatform] that uses method channels.
class MethodChannelChangeRes extends ChangeResPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('change_res');

  @override
  Future<String?> changeReslutionScreen({int? width, int? high}) async {
    final version = await methodChannel
        .invokeMethod<String>('changeReslutionScreen', <String, dynamic>{
      'width': width ?? 1920,
      'high': high ?? 1080,
    });
    return version;
  }


  @override
  Future<String?> getReslotion() async {
    final version = await methodChannel.invokeMethod<String>('getRes');
    return version;
  }
}
