https://backlog.com/git-tutorial/cn/stepup/stepup1_1.html
https://zhuanlan.zhihu.com/p/463643494
https://www.cnblogs.com/upstudy/p/15870787.html
https://zhuanlan.zhihu.com/p/276376558
https://blog.csdn.net/weixin_43314519/article/details/107572206
https://learngitbranching.js.org/?locale=zh_CN
https://www.liaoxuefeng.com/wiki/896043488029600

Git常用命令：
   mkdir：         XX (创建一个空目录 XX指目录名)

   pwd：          显示当前目录的路径。

   git init          把当前的目录变成可以管理的git仓库，生成隐藏.git文件。

   git add XX       把xx文件添加到暂存区去。

   git commit –m “XX”  提交文件 –m 后面的是注释。

   git status        查看仓库状态

   git diff  XX      查看XX文件修改了那些内容  $ git diff HEAD -- readme.txt 

   git log          查看历史记录

   git reset  --hard HEAD^ 或者 git reset  --hard HEAD~ 回退到上一个版本

                        (如果想回退到100个版本，使用git reset –hard HEAD~100 )

   cat XX         查看XX文件内容

   git reflog       查看历史记录的版本号id

   git checkout -- XX  把XX文件在工作区的修改全部撤销。

   git rm XX          删除XX文件

   git remote add origin https://github.com/tugenhua0707/testgit 关联一个远程库

   git push –u(第一次要用-u 以后不需要) origin master 把当前master分支推送到远程库

   git clone https://github.com/tugenhua0707/testgit  从远程库中克隆

   git checkout –b dev  创建dev分支 并切换到dev分支上

   git branch  查看当前所有的分支

   git checkout master 切换回master分支

   git merge dev    在当前的分支上合并dev分支

   git branch –d dev 删除dev分支

   git branch name  创建分支

   git stash 把当前的工作隐藏起来 等以后恢复现场后继续工作

   git stash list 查看所有被隐藏的文件列表

   git stash apply 恢复被隐藏的文件，但是内容不删除

   git stash drop 删除文件

   git stash pop 恢复文件的同时 也删除文件

   git remote 查看远程库的信息

   git remote –v 查看远程库的详细信息

   git push origin master  Git会把master分支推送到远程库对应的远程分支上
   
   
   
   Git流程：
   
   设置名称和邮箱：
   git config --global user.name "xxx"
   git config --global user.email "xxx.xxx"
   查看 git config --list
   
   连接远程服务器：
   设置秘钥 ssh-keygen -t rsa -C "liangfs_victory@163.com"
   连接 ssh git@github.com

   初始化：
   git init
   提交暂存区：
   git add filename / *
   提交本地仓库：
   git commit -m "注释"
   从本地仓库提交远程仓库
   git remote add origin git@github.com:Fisher-Liang/my_project_test.git
   git push -u(第一次要用) origin master
   查看commit id ：git log   
   查看历史命令：git reflog
   
   如果本地repo和远程仓库有冲突，要merge或pull同步一下
   
   branch操作：
   创建并切换到新branch：
   git checkout -b branchname
   创建和删除branch(不切换)：
   git branch branchname
   git branch –d branchname
   切回主分支：
   git checkout master
   
   merge分支和topic分支：merge分支通常为master分支，即主分支，方便发布新版本，topic分支（各个工作人员建立的分支）是在稳定的master分支基础上进行操作的分支。
   reset操作：