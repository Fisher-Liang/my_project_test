## daemon service && log print
-----------------------------
**1**. 将程序注册为Linux系统服务
（1）简介
将程序注册为系统服务后，可通过 systemctl 和 service 系统命令启动，查看，停止程序，并可以将程序设置为开机自启动等等。
将程序注册为系统服务，需要编辑xxx.service文件，并将文件存储到 /usr/lib/systemd/system/ 目录下
systemctl daemon-reload, sudo systemctl enable xxx.service, sudo systemctl start xxx.service, systemctl status xxx
（2）常用命令
   命令格式：systemctl 动作  服务名，service  服务名 动作， 两个命令效果一样
　　systemctl status xxx　　查看服务状态
　　systemctl start xxx　　 启动服务
　　systemctl stop xxx     停止服务
　　systemctl restart xxx   重启服务
　　systemctl enable xxx   启用服务开机自启动
　　systemctl disable xxx  禁止服务开机自启动
　　systemctl list-units --type=service 查看所有已启动的服务
　　修改xxx.service文件后，需要执行 systemctl daemon-reload 重新加载文件；

（3）service文件格式

```cpp
vim /usr/lib/systemd/system/sshd.service

[Unit]
Description=OpenSSH server daemon
Documentation=man:sshd(8) man:sshd_config(5)
After=network.target sshd-keygen.service
Wants=sshd-keygen.service

[Service]
Type=notify
EnvironmentFile=/etc/sysconfig/sshd
ExecStart=/usr/sbin/sshd -D $OPTIONS
ExecReload=/bin/kill -HUP $MAINPID
KillMode=process
Restart=on-failure
RestartSec=42sPrivateTmp=true

[Install]
WantedBy=multi-user.target
```

```cpp
[Unit]
此区块信息用于描述当前服务的简单描述：
Description：服务描述信息；
Documentation：文档相关信息；
下面四个选项只涉及启动顺序，不涉及依赖关系；
After：定义sshd服务应该在哪些服务之后启动；
Before：定义sshd服务应该在哪些服务之前启动；
Requires：表示强依赖关系，如果sshd服务启动失败或异常退出，则Requires配置的服务也必须退出；
Wants：表示若依赖关系，如果sshd服务启动失败或异常退出，不影响Wants配置的服务；
```

```cpp
[Service]
type 字段定义启动类型　
simple：默认值，ExecStart字段启动的进程为主进程，如果启动脚本中 以 nohup & 形式启动进程时，此时启动脚本后会自动 kill 当前服务；
forking：ExecStart字段将以fork()方式启动，此时父进程将会退出，子进程将成为主进程；
oneshot：类似于simple，但只执行一次，Systemd 会等它执行完，才启动其他服务，表明这个服务只要运行一次就行；
dbus：类似于simple，但会等待 D-Bus 信号后启动
notify：类似于simple，启动结束后会发出通知信号，然后 Systemd 再启动其他服务
idle：类似于simple，但是要等到其他任务都执行完，才会启动该服务。一种使用场合是为让该服务的输出，不与其他服务的输出相混合

启动，停止，重启命令
EnvironmentFile：环境参数配置文件，文件内部配置参数形式为key=value键值对，可以在service文件中以$key的形式引用配置项；
ExecStart：启动服务时执行的命令；
ExecReload：重启服务时执行的命令；
ExecStop：停止服务时执行的命令；
ExecStartPre：启动服务之前执行的命令；
ExecStartPost：启动服务之后执行的命令；
ExecStopPost：停止服务之后执行的命令；

停止模式
KillMode 表示停止服务时的方式
control-group：默认值，当前控制组里面的所有子进程，都会被杀掉
process：只杀主进程
mixed：主进程将收到 SIGTERM 信号，子进程收到 SIGKILL 信号
none：没有进程会被杀掉，只是执行服务的 stop 命令
```
```cpp
[Install]
定义如何安装配置文件；
WantedBy：表示服务所在的服务组；
WantedBy=multi-user.target 表示 sshd服务属于 multi-user.target 用户组；
multi-user.target 组里的所有服务都将开机启动；
执行 systemctl enable sshd.service 时将把 sshd.service 文件的一个符号链接保存到 /etc/systemd/system 目录下的 multi-user.target.wants 子目录中；
```

(4)文件模版

```cpp
[Unit]
Description=simulator

[Service]
Type=simple
ExecStart=/home/chenfan/simulator/start.sh
ExecStop=/home/chenfan/simulator/stop.sh

[Install]
WantedBy=multi-user.target
```
https://www.cnblogs.com/fusheng11711/p/12893296.html#:~:text=%E5%B0%86%E7%A8%8B%E5%BA%8F%E6%B3%A8%E5%86%8C%E4%B8%BA%E7%B3%BB%E7%BB%9F%E6%9C%8D%E5%8A%A1%E5%90%8E%EF%BC%8C%E5%8F%AF%E9%80%9A%E8%BF%87%20systemctl%20%E5%92%8C%20service,%E7%B3%BB%E7%BB%9F%E5%91%BD%E4%BB%A4%E5%90%AF%E5%8A%A8%EF%BC%8C%E6%9F%A5%E7%9C%8B%EF%BC%8C%E5%81%9C%E6%AD%A2%E7%A8%8B%E5%BA%8F%EF%BC%8C%E5%B9%B6%E5%8F%AF%E4%BB%A5%E5%B0%86%E7%A8%8B%E5%BA%8F%E8%AE%BE%E7%BD%AE%E4%B8%BA%E5%BC%80%E6%9C%BA%E8%87%AA%E5%90%AF%E5%8A%A8%E7%AD%89%E7%AD%89%E3%80%82%20%E5%B0%86%E7%A8%8B%E5%BA%8F%E6%B3%A8%E5%86%8C%E4%B8%BA%E7%B3%BB%E7%BB%9F%E6%9C%8D%E5%8A%A1%EF%BC%8C%E9%9C%80%E8%A6%81%E7%BC%96%E8%BE%91xxx.service%E6%96%87%E4%BB%B6%EF%BC%8C%E5%B9%B6%E5%B0%86%E6%96%87%E4%BB%B6%E5%AD%98%E5%82%A8%E5%88%B0%20%2Fusr%2Flib%2Fsystemd%2Fsystem%2F%20%E7%9B%AE%E5%BD%95%E4%B8%8B



**2**. 利用.sh脚本文件启动程序，service无法启动
```cpp
● test_function.service - test_function-1.0
     Loaded: loaded (/lib/systemd/system/test_function.service; enabled; vendor preset: enabled)
     Active: failed (Result: exit-code) since Wed 2023-09-20 16:47:02 CST; 3s ago
    Process: 47264 ExecStart=/home/fisher/lfs/my_project_test/src/test_func_startup.sh (code=exited, status=203/EXEC)
   Main PID: 47264 (code=exited, status=203/EXEC)
```
bugfix：脚本解释器错误：脚本文件的第一行应该包含正确的解释器声明（shebang），例如 #!/bin/bash，以告诉系统使用哪个解释器来执行脚本。如果解释器声明不正确或解释器不存在，就会导致 "Exec format error"。确保解释器的路径正确，并且解释器可执行。

其他可能原因：

+ 文件权限问题：确保 test_func_startup.sh 脚本有执行权限。可以使用 chmod 命令为脚本添加执行权限，如 chmod +x /home/fisher/lfs/my_project_test/src/test_func_startup.sh。

+ 脚本不存在或路径错误：确认脚本文件是否真的存在于 /home/fisher/lfs/my_project_test/src/ 这个路径下。如果文件不存在或路径不正确，执行会失败。

+ 脚本语法错误：检查脚本本身是否有语法错误，这些错误可能导致脚本无法执行。可以尝试手动运行脚本以查看是否会产生错误，例如 /home/fisher/lfs/my_project_test/src/test_func_startup.sh。

+ 脚本内部依赖项错误：如果脚本依赖于外部命令或文件，请确保这些依赖项在系统中可用，并且相关路径和环境变量设置正确。

+ 文件编码问题：脚本文件应该使用正确的编码保存，通常是 UTF-8。不正确的编码可能导致解释器无法正确解释脚本内容。



**3**. 

```cpp

```                    



### 查看程序的运行状态
ps -a
ps -aux|grep xxx
top
kill -9 pid


### chmod
chmod [u/g/o/a] [+/-/=] [r/w/x] filename
[ ]里都代表的意思： 
u表示User，是文件的所有者 
g表示跟User同Group的用户 
o表示Other，即其他用户 
a表示ALL，所有用户

+表示增加权限 
-表示取消权限 
=表示取消之前的权限，并给予唯一的权限

r表示Read，即读文件 
w表示Write，即写文件 
x表示运行文件

sudo chmod u+rw /media/name/name.text
sudo chmod u+rw /media/name/

chmod [xyz] file
sudo chmod 774 /code/readme.txt
其中x，y，z分别指定User、Group、Other的权限；用三位二进制数表示 ” r , w , x”（注意顺序）三种权限，其中 0 代表没有该权限，1 代表有该权限，如 100 则表示，有 ‘r”权限，无 “w x”权限；再将这个三位的二进制数转为十进制，则是 x (或y，z)的值

https://blog.csdn.net/zbbmm/article/details/88617926



###### DLT

启动daemon和receive client的脚本文件：

```sh
#!/bin/bash
export DLT_PIPE_DIR=/tmp/genivi_dlt
export LD_LIBRARY_PATH=/app/dlt/lib
sudo /app/dlt/bin/dlt-daemon -c /app/dlt/etc/dlt.conf -t /tmp/genivi_dlt -p 34955
 &
/app/dlt/bin/dlt-receive -a -p 3495 localhost &
```
+ DLT User 用户程序，可以使用LOG命令，它使用DLT LIBRARY来创建和传递消息。
+ DLT Library 提供API接口，作用是创建和传递消息给Daemon，如果Daemon没打开，就把消息放在ring buffer里
+ DLT Daemon 是ECU的通信接口，作为DLT Client的服务器，响应其请求和控制消息。
+ DLT Client 通过daemon从user接受log信息，他还可以传递用户定义的数据。


## 获取dlt-daemon源码
```bash
git clone https://github.com/GENIVI/dlt-daemon.git
cd dlt-daemon
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig
```
## dlt-viewer
现装依赖包 sudo apt-get install libqt5serialport5-dev libqt5serialport5
批注：也可以使用 sudo apt install dlt-viewer 完成安装。

```bash
git clone https://github.com/GENIVI/dlt-viewer.git
mkdir build
cd build
cmake ..
make
```
## 生成测试程序
```bash
cd dlt-daemon/examples/example1/
mkdir build
cd build
cmake ..
make
```

## 启动dlt-daemon
+ 首先复制dlt.conf文件
```bash
cd dlt-daemon/src/daemon/
sudo cp dlt.conf /etc/
sudo gedit /etc/dlt.conf
```

+ 修改dlt.conf：
```bash
LoggingMode = 2
OfflineTraceDirectory = /tmp
OfflineTraceFileSize = 1000000
OfflineTraceMaxSize = 4000000

OfflineTraceFileNameTimestampBased = 1
OfflineLogstorageDirPath = /opt
```

+ 链接配置文件：
```bash
dlt-daemon -c /etc/dlt.conf
```

+ 启动log接收端：
```bash
dlt-receive -o /tmp/log.dlt localhost
```
+ 启动example1:

```bash
dlt-daemon/examples/example1/build$ sudo ./dlt-example1 
```


https://www.cnblogs.com/chendeqiang/p/13033234.html#2904241770

https://github.com/ads830e/dlt-daemon-windows-msys2/tree/main