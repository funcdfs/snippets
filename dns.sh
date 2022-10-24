#!/bin/bash
HOSTS_FILE_WIN='/mnt/c/Windows/System32/drivers/etc/hosts'
TEMP_FILE_PATH='/home/konng/.opt/dns_back'
inetIp=`ifconfig eth0 | grep -o "inet [0-9]*\.[0-9]*\.[0-9]*\.[0-9]*  netmask" | cut -f 2 -d " "` # 获取本机ip

nu=`cat -n ${HOSTS_FILE_WIN} | grep wsl2 | awk '{print $1}'`   # 获取已设置dns行号

dnsIp=`cat ${HOSTS_FILE_WIN} | grep -o "[0-9]*\.[0-9]*\.[0-9]*\.[0-9]* wsl #" | cut -f 1 -d " "` # 获取已设置dns ip

echo "wsl's ip is: ${inetIp}"

# set -x
set -e
if [ ${nu} ]  # 若已设置
then
        if [ ${inetIp} != ${dnsIp} ] # 已设置dns不正确
        then
                echo reset
	 	        sudo cp -f "${HOSTS_FILE_WIN}" "${TEMP_FILE_PATH}"
		        sed -i "${nu}d" ${TEMP_FILE_PATH} # 删除对应行
        		echo "${inetIp} wsl #wsl2 dns config" >> ${TEMP_FILE_PATH} # 重新设置
		        cat ${TEMP_FILE_PATH} > ${HOSTS_FILE_WIN}
        		echo success
        fi
else # 未设置
                echo "${inetIp} wsl #wsl2 dns config" >> ${HOSTS_FILE_WIN} # 直接设置
fi
