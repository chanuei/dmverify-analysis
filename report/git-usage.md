# git 

## 配置
以 ubuntu 14.04 为例

安装并配置
```bash
sudo apt-get install git
git config --global user.name "Your Name"
git config --global user.email "email@example.com"
git config --global color.ui true
```

如果只对当前项目使用不同用户信息
```bash
git config user.name "Jiang Xin"
git config user.email "gotgithub@gmail.com"
```

    默认master分支
    查看远程库信息,远程默认库名origin
     git remote -v

### 创建git库
本地创建及初始化git库
 git init
将本地库内容关联到github仓库
 git remote add origin git@github.com:fengjinyang/learn.git
将本地内容推送到远程库上
 git push -u origin master

从远程库克隆
 git clone git@github.com:fengjinyang/learn.git

###普通操作
####添加文件
 git add readme.txt Home.md
 git add -A
 git commit -m "comment"
####查看未提交的修改
 git diff
 git diff HEAD -- readme.txt
####查看历史
 git log
####回退上一版本
 git reset --hard HEAD^
####跳转特定版本
 git reset --hard 3628164
####操作记录
 git reflog
####签出文件
 git checkout -- readme.txt
####删除文件
 git rm readme.txt

###分支
####创建分支
 创建一个叫做dev的分支
 git checkout -b dev
  相当于
 git branch dev
 git checkout dev
####创建与远程分支对应的分支
 git checkout -b dev origin/dev
####合并分支
 将dev分支合并到当前分支
 git merge dev 
####将本地test分支推送到远程(origin)的master分支
git push origin test:master
####删除分支
 删除dev分支
 git branch -d dev
 现在只是本地分支被删除了，远程的dev分支尚在。删除远程的分支就不能使用git branch命令，而是要使用git push命令，不过在使用推送分支命令时要使用一个特殊的引用表达式（冒号前为空）。如下：
 git push origin :dev

####取消跟踪
git branch --unset-upstream master

>从远程分支checkout的本地分支，称为跟踪分支(tracking branch)。跟踪分支是一种和远程
分支有直接联系的本地分支。在跟踪分支里输入git push，Git会自行推断应该向哪个服务器的
哪个分支推送数据。反过来，在这些分支里运行git pull会获取所有远程索引，并把它们的数据
都合并到本地分支中来。

####备份工作现场
 git stash
####恢复工作现场
 git stash pop

####指定本地dev分支与远程origin/dev分支关联
 git branch --set-upstream dev origin/dev
####从远程抓取分支
 git pull

###标签
####打标签
 打标签,命名v1.0
 git tag v1.0
 默认HEAD,如果为历史提交打标签
 git tag v0.9 6224936
####查看标签历史
 git tag
####查看标签信息
 git show v0.9
####用私钥签名一个标签
 git tag -s v0.2 -m "signed version 0.2 released" fec145a
####删除标签
 git tag -d v0.1
 然后删除远程对应的标签
 git push orgin :refs/tags/v0.9
####推送标签
 git push origin v1.0
 推送所有标签
 git push origin --tags

###忽略特殊文件
在Git工作区的根目录下创建一个.gitignore文件,然后把忽略的文件名放进去,git就会自动忽略这些文件.文件名支持模式匹配.
>.gitignore文件本身要放到版本库里，并且可以对.gitignore做版本管理！

###配置别名
 将status使用st来做别名
 git config --global alias.st status

###远程库管理
 查看远程分支
 git remote

###日志
#### 项目日志
git log
#### 单个文件日志
git log -p filename
####
git reflog


