# 替换fota程序的命令行操作

```shell
    #  1.关闭要更新程序的service
    1  sudo systemctl status MpdFotaApp.service  # 显示fota service状态
    4  sudo systemctl stop MpdFotaApp.service   # 替换之前先关闭服务
    5  sudo /ap/bin/adg.sh --state      # 查看服务状态
    6  ps -ef|grep comd                 # 查看通信状态
    7  cd /app/ap/studio/
   10  sudo mv MpdFotaApp old_MpdFotaApp   # 备份之前的fota程序
   12  sudo tcpdump -i mgbe3_0.3 -w /fota/fota.pcap &    # 替换程序之前先抓包，看通信是否有问题

   #   2.u盘挂载，将新程序复制到旧程序所在目录
   14  sudo mount /dev/sda1 /mnt/     # u盘挂载到/mnt
   15  cd /mnt/
   21  sudo chown  -R pp-cem:pp-cem /mnt/    #  /mnt的所有者和所属组都被设置为 pp-cem
   23  sudo mv ep35_mpd_fota+6.tar.gz /app/ap/studio/
   24  sudo chown -R pp-cem:pp-cem /app/ap/studio/
   25  cd /app/ap/studio/
   26  mkdir temp
   27  mv ep35_mpd_fota+6.tar.gz temp/
   29  cd temp/
   31  tar -zxvf ep35_mpd_fota+6.tar.gz 
   33  cd ep35_mpd_fota/
   39  cd temp/
   40  mv ep35_mpd_fota MpdFotaApp
   42  mv MpdFotaApp ../

   #   3.替换程序中的lib库，如果旧程序的库可以用，则可以直接替换
   46  cd old_MpdFotaApp/
   48  cd lib/
   51  cd /mnt/
   53  cp fota_lib.tar.gz  /app/ap/studio/temp/
   54  cd /app/ap/studio/temp/
   56  tar -zxvf fota_lib.tar.gz 
   58  cd es33_mpd_fota/
   59  ls
   60  cd impl/
   61  ls
   62  cd lib/
   70  cp -r old_MpdFotaApp/usr/lib MpdFotaApp/usr/  # cp -r 命令是递归复制文件夹及其子目录到新的文件夹，保持源目录和文件的权限和属性以及文件树。cp -rf会覆盖同名文件。
   71  cd MpdFotaApp/usr/
   72  ls
   73  cd lib/
   75  ls -l

   #  4.手动启动第一步关闭的service，更新json配置文件，并显示
   78  cd /app/ap/studio/MpdFotaApp/aa_startup/
   80  sudo ./MpdFotaApp.sh
   81  sudo systemctl start MpdFotaApp.service 
   82  systemctl status MpdFotaApp.service 
   85  cat /app/image_version 
   86  systemctl status dlt-daemon.service 
   87  tail -f /log/dlt/MpdFotaApp_001_20230627-123501.dlt   # 追加到.dlt文件末尾并实时显示
   89  sudo systemctl stop MpdFotaApp.service 
   90  cd ../
   91  cp /mnt/es33_mpd_fota_CM_MPD_MPU_EthECUInterface_MPD_MPU.json ./
   92  ls
   93  sudo mv /ap_conf/etc/adaptive/ara_Com/daemon_1/mgbe3_0.3/MpdFotaApp_CM_MPD_MPU_EthECUInterface_MPD_MPU.json  /fota/
   94  vi /fota/MpdFotaApp_CM_MPD_MPU_EthECUInterface_MPD_MPU.json 
   95  ls
   96  vi es33_mpd_fota_CM_MPD_MPU_EthECUInterface_MPD_MPU.json 
   97  sync
   98  sudo mv es33_mpd_fota_CM_MPD_MPU_EthECUInterface_MPD_MPU.json /ap_conf/etc/adaptive/ara_Com/daemon_1/mgbe3_0.3/
   99  sync
  100  sudo /ap/bin/adg.sh --stop       # 关闭com模块的服务
  101  sudo /ap/bin/adg.sh --start
  102  sudo /ap/bin/adg.sh --state
  103  ps -ef|grep comd
  104  ps -ef|grep tcpdump
  105  sudo systemctl stop cem_driver_*    # 关闭这个是因为显示太多了，还要关闭IDPS service。
  106  sudo systemctl status MpdFotaApp.service 
  107  tail -f /log/dlt/MpdFotaApp_001_20230627-123501.dlt 

  实时显示的第二种方式，
  # EXPORT LD_LIBRARY_PATH = /app/dlt/lib  
  # /app/... -a -p 3495 localhost
  108  history
  109  history > h.log

```
 


# switch 刷写
打开cmd
fwupdate es33....50.. //百兆口，插口在右边
fwupdate es33....60.. //千兆口，插口在中间
重新上电查看Switch版本