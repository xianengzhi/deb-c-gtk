import gi
gi.require_version('AppIndicator3', '0.1')
from gi.repository import AppIndicator3 as app

# 以下是继续实现托盘的步骤：

APPINDICATOR_ID = 'myappindicator'

def main():
    # 创建托盘图标
    indicator = app.Indicator.new(
        APPINDICATOR_ID,
        "icon",
        app.IndicatorCategory.APPLICATION_STATUS
    )
    indicator.set_status(app.IndicatorStatus.ACTIVE)
    indicator.set_attention_icon("icon")

    # 显示或隐藏托盘图标
    if indicator.get_status() == app.IndicatorStatus.ACTIVE:
        indicator.set_status(app.IndicatorStatus.PASSIVE)
    else:
        indicator.set_status(app.IndicatorStatus.ACTIVE)

    # 删除托盘图标
    indicator.set_status(app.IndicatorStatus.PASSIVE)
    app.Indicator.uninstall(indicator)