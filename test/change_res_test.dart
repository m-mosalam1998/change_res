import 'package:flutter_test/flutter_test.dart';
import 'package:change_res/change_res.dart';
import 'package:change_res/change_res_platform_interface.dart';
import 'package:change_res/change_res_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockChangeResPlatform
    with MockPlatformInterfaceMixin
    implements ChangeResPlatform {
  @override
  Future<String?> changeReslutionScreen({int? width, int? high}) {
    throw UnimplementedError();
  }

  @override
  Future<String?> getReslotion() {
    throw UnimplementedError();
  }

  @override
  Future<String?> restReslotion() {
    throw UnimplementedError();
  }
}

void main() {
  final ChangeResPlatform initialPlatform = ChangeResPlatform.instance;

  test('$MethodChannelChangeRes is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelChangeRes>());
  });

  test('getPlatformVersion', () async {
    ChangeRes changeResPlugin = ChangeRes();
    MockChangeResPlatform fakePlatform = MockChangeResPlatform();
    ChangeResPlatform.instance = fakePlatform;

    expect(await changeResPlugin.changeReslutionScreen(), '42');
  });
}
