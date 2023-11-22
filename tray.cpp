#include <libappindicator/app-indicator.h>

#define APPINDICATOR_ID "myappindicator"

int main() {
  // 创建托盘图标
  AppIndicator *indicator = app_indicator_new(APPINDICATOR_ID, "icon", APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
  app_indicator_set_status(indicator, APP_INDICATOR_STATUS_ACTIVE);
  app_indicator_set_attention_icon(indicator, "icon");

  // 显示或隐藏托盘图标
  if (app_indicator_get_status(indicator) == APP_INDICATOR_STATUS_ACTIVE) {
    app_indicator_set_status(indicator, APP_INDICATOR_STATUS_PASSIVE);
  } else {
    app_indicator_set_status(indicator, APP_INDICATOR_STATUS_ACTIVE);
  }

  // 删除托盘图标
  app_indicator_set_status(indicator, APP_INDICATOR_STATUS_PASSIVE);
  app_indicator_stop(indicator);
  return 0;
}