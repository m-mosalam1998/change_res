import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:change_res/change_res_method_channel.dart';

void main() {
  MethodChannelChangeRes platform = MethodChannelChangeRes();
  const MethodChannel channel = MethodChannel('change_res');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.changeReslutionScreen(), '42');
  });
}
