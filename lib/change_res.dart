import 'change_res_platform_interface.dart';

class ChangeRes {
  Future<String?> changeReslutionScreen({int? width, int? high}) {
    return ChangeResPlatform.instance
        .changeReslutionScreen(high: high, width: width);
  }

  Future<String?> getReslotion() {
    return ChangeResPlatform.instance.getReslotion();
  }
}
