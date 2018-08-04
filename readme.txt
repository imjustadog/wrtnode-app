每次编译之前最好加上：
export STAGING_DIR=/home/adoge/wrtnode/staging_dir

在openwrt加载i2c命令：
insmod i2c-gpio-custom bus0=0,1,2

在openwrt测试摄像头命令：(两个叠一起的上面的那个usb口好像比较好使）
mjpg_streamer -i "input_uvc.so -d /dev/video0 -r 160x120 -f 20 -yuv"  -o "output_http.so -p 8080 -w /www/camwww"
然后在浏览器中输入http://192.168.8.1:8080/?action=stream

每隔5秒拍照命令（存在tmp下）
mjpg_streamer -i "input_uvc.so -d /dev/video0 -r 160x120 -f 20 -yuv" -o "output_file.so -d 5000 -f /tmp"

编译好的output_file.so存放：
sudo scp output_file.so root@192.168.8.1:/usr/lib/

