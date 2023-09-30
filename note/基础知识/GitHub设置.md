## Git

![](../pic/github/git-command_1.jpg)

- workspace：工作区
- staging area：暂存区/缓存区
- local repository：版本库或本地仓库
- remote repository：远程仓库



**工作区和暂存区**

​	工作区：就是你在电脑上看到的目录，比如目录下testgit里的文件(.git隐藏目录版本库除外)。或者以后需要再新建的目录文件等等都属于工作区范畴

​	暂存区：工作区有一个隐藏目录.git,这个不属于工作区，这是版本库。其中版本库里面存了很多东西，其中最重要的就是stage(暂存区)，还有Git为我们自动创建了第一个分支master,以及指向master的一个指针HEAD



### 库的创建和使用

**创建和初始化库**

​	创建版本库：`git init`（对应文件夹内打开git bash后）

​	添加文件到暂存区：`git add` 文件名.文件类型（该文件需在.git同文件夹内）//git add . 提交所有文件

​	提交暂存区文件到库：`git commit -m` “注释内容”

​	**提交修改和提交文件步骤一样，都是先添加到暂存区后再提交到库**

​	查看仓库当前状态：`git status`

​	查看文件修改内容：`git diff` 文件名.文件类型

**撤销修改和删除文件**

撤销修改：`git checkout --文件名.文件类型`	//把对应文件在工作区做的修改全部撤销

​	#这是除了版本回退或者直接操作文件的第三种方法

​	1、文件没有被放到暂存区，使用撤销修改就回到和版本库一模一样的状态

​	2、文件还在暂存区但没有commit，撤销修改就回到添加暂存区后的状态

删除文件：`git rm 文件名.文件类型`

​	若删除前修改过并且已经放到暂存区，则需用强制删除选项`-f`

​	若只想删除暂存区文件：`git rm --cached <file>`

​	递归删除：`git rm -r *<.文件类型>`	若无文件类型而是目录则会递归删除目中中所有子目录和文件

恢复已删除但是没有commit的文件：即撤销修改

**文件版本查看**

查看库内文件历史记录：`git log`

​	`git log -pretty=online`	//查看精简信息

**退回文件版本**

​	1、`git reset --hard HEAD^`（退回上一版本，若上上版本则为^^）

​	2、`git reset --hard HEAD~100`	//退回到前100个版本

​	3、`git reset --hard 版本号`	//文件版本回退到指定版本号

查看文件版本号：`git reflog`



### 远程库的连接

1、查看用户主目录下有无.ssh文件夹

​		若有，查看是否有id_rsa和id_rsa.pub这两个文件，如果也有，可直接到下一步

​		若没有，在开始附录里找到Git Bash，输入$ ssh-keygen -t rsa -C "github注册使用的邮箱"创建SSH Key

​		**SSH Key ：id_rsa是私钥，不能泄露；id_rsa.pub是公钥，可以公开**

2、github填写SSH Key

​		1）”Account setting“中”SSH and DGP keys“界面

​		2）点击“New SSH key”，title随意，key填写id_rsa.pub的全部内容

3、验证是否成功：ssh -T git@github.com

​		//初次设置continue connecting询问yes即可

4、github创建仓库，不要勾选initialize（后面可能报错）

5、关联远程仓库：根据创建好的仓库页面的提示（找自己仓库的提示代码）

​		在本地仓库命令行输入：`git remote add origin` 远程仓库对应URL

### 远程仓库操作

**git remote**

​		`git remote`	列出当前仓库中已配置的远程仓库。
​		`git remote -v`	列出当前仓库中已配置的远程仓库，并显示它们的 URL。
​		`git remote add <remote_name> <remote_url>`	添加一个新的远程仓库。指定一个远程仓库的名称和 URL，将其添加到当前仓		库中。
​		`git remote rename <old_name> <new_name>`	将已配置的远程仓库重命名。
​		`git remote remove <remote_name>`	从当前仓库中删除指定的远程仓库。
​		`git remote set-url <remote_name> <new_url>`	修改指定远程仓库的 URL。
​		`git remote show <remote_name>`	显示指定远程仓库的详细信息，包括 URL 和跟踪分支。

**git fetch**

​		`git fetch <远程主机名>`	将某个远程主机的更新全部取回本地

​			`<远程主机名><分支名>`	只取回特定分支更新

**git pull**

​		`git pull <远程主机名> <远程分支名>:<本地分支名>`	从远程获取代码并合并本地版本





**git push**

​		`git push <远程主机名> <本地分支名>:<远程分支名>`	将本地的分支版本上传到远程并合并，若远程分支与本地相同则分支名可省略

​			`push --force`	如果本地版本与远程版本有差异，但又要强制推送可以使用 --force 参数

​			`origin --delete`	删除主机的分支可以使用 --delete 参数

### 分支管理

**git branch**

​		`git branch`		列出本地分支

​		`git branch <branchname>`	创建分支

​		`git branch -d <branchname>`	删除本地分支

​			`-d -r <branchname>`	删除远程仓库分支（非主分支）

​		`git merge <branchname>`	将指定分支合并到当前分支

**git checkout**

​		`git checkout <branch-name>`	从当前分支切换到指定分支<branch-name>，若为master则是切换到主分支

​				`checkout -`	则是切回前一个分支

​		`git checkout -b <new-branch-name>`	创建新分支并切换

​		`git checkout -- <file>`	将指定文件恢复到最新的提交状态，丢弃所有未提交的更改

​		`git checkout <commit-hash>`	切换到特定提交，这将使你进入"分离头指针"状态，只能查看历史记录，而不能进行分支操作。		通常情况下，不建议在分离头指针状态下工作，因为更改可能会丢失

### 基本操作

**创建仓库命令**

​	`git init`	//在当前目录下使用该命令即可初始化创建一个新的本地仓库

​	`git clone [url]`	//克隆url对应远程git仓库到本地

**提交与修改**

​	**git diff**	

​		//比较文件的不同，即比较文件在暂存区和工作区的差异

​		`git diff [file]`	尚未缓存的改动

​		`git diff --cached(staged) [file]`	查看已缓存的改动，括号表示另一种语法

​		`git diff [first-branch]...[second-branch]`	显示两次提交之间的差异

​		`git diff HEAD`	查看已缓存的与未缓存的改动

​		`git diff --stat`	显示摘要而非整个diff

​	**git commit**

​		`git gommit -m “注释信息”`	提交暂存区到本地仓库

​		`git commit [file1]... -m "注释信息"`	提交暂存区的指定文件到仓库

​		`git commit -a`	设置修改文件后不需要执行`git add`命令，直接提交





### 一些问题

**Recv failure Connection was reset**

​	说明：不能进入git仓库，连接被重设

​	解决一：删除代理，若没有开代理，就不配置代理信息

​		1、查看git配置：`git config --global -l`

​		2、删除代理

```
git config --global --unset.http.proxy
git config --global --unset.https.proxy
```

​	解决二：手动配置代理及端口

​		1、查看git配置

​		2、配置代理

​				`git config --global http.proxy http://代理IP：端口号`

​				//代理IP和端口号在设置-网络和Internet-代理-手动设置代理中查看



**删除文件在push后仍然存在**

​	原因：删除文件但git保留了历史版本信息，即使删除了文件，文件的历史记录仍然保存在远程仓库中。Git的这种设计意味着你可以从				以前的版本中恢复文件，保留了许多有用的历史信息。

​	解决方案：彻底删除文件

​			1、`git filter-branch --tree-filter ‘删除命令’ HEAD`	//将删除文件的操作应用于每个提交

​			2、`git push origin --force`	//将更改强推到远程仓库

​	**这个操作会改变代码库的历史记录，可能会影响到其他开发者的工作，故而在此操作之前优先与团队其他成员进行沟通**



**删除文件后没有commit而直接push导致status中有delete红字错误**

​	解决方案：根据提示重新`git add 删除文件名`后再提交修改和上传到远程仓库