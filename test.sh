#!/bin/bash
# 注意会拷贝到所有/home 目录下
# # 检查当前用户是否未 root 用户
# if [ $EUID -ne 0 ]; then
#     echo "此脚本需要使用 root 用户权限运行" >&2
#     exit 1
# fi
# 遍历所有用户的桌面文件夹路径
for home_dir in /home/* /root/; do
    desktop_dir="${home_dir}/Desktop"

    # 检查 Desktop 文件夹是否存在
    if [ ! -d "${desktop_dir}" ];then
        echo "warning:用户 ${home_dir} 的Desktop文件夹不存在，使用桌面文件夹" >&2
        desktop_dir="${home_dir}/桌面"
    fi
    # 检查 desktop_dir 是否存在
    if [ ! -d "${desktop_dir}" ];then
        echo "error:用户 ${home_dir} 的桌面文件夹不存在，跳过" >&2
        continue
    fi

    # 复制文件到桌面文件夹
    cp /usr/share/applications/hello.desktop "${desktop_dir}/"
    chmod +x ${desktop_dir}/${APP_NAME}.desktop
    echo "chmod +x ${desktop_dir}/${APP_NAME}.desktop"

    echo "已将文件复制到用户 ${home_dir} 的桌面文件夹"
done


