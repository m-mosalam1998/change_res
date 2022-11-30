import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'change_res_method_channel.dart';

abstract class ChangeResPlatform extends PlatformInterface {
  /// Constructs a ChangeResPlatform.
  ChangeResPlatform() : super(token: _token);

  static final Object _token = Object();

  static ChangeResPlatform _instance = MethodChannelChangeRes();

  /// The default instance of [ChangeResPlatform] to use.
  ///
  /// Defaults to [MethodChannelChangeRes].
  static ChangeResPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [ChangeResPlatform] when
  /// they register themselves.
  static set instance(ChangeResPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> changeReslutionScreen({int? width, int? high}) {
    throw UnimplementedError(
        'changeReslutionScreen() has not been implemented.');
  }

 

  Future<String?> getReslotion() {
    throw UnimplementedError('getReslotion() has not been implemented.');
  }
}
