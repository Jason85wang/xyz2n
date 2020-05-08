2020.5.8 在虚拟机安装Qt

2019.4.4 学习程序打包方法,发布方法
1.打包关键词　windeployqt Enigma Virtual Box
运行成功后，如果勾选了 “shadow build” 将源码路径和构建路径分开，那么将在 build-cleanRobot-Desktop_Qt_5_9_7_MinGW_32bit-Release 文件夹下生成 exe 文件，
将 cleanRobot.exe 可执行文件复制到别的文件夹下，这里我复制到 F:\cleanRobot 下，然后在 “开始菜单Qt5.9.7” 下找到 “Qt 5.9.7 for Desktop cmd” 运行文件，打开运行
执行 cd \d F:\cleanRobot 命令进入exe 文件所在目录下, 再执行 dir 命令查看目录，
最后执行 windeployqt cleanRobot.exe 命令，Qt 就会自动把该程序所需要的所有 dll 拷贝过来。
当然有可能有些 dll 不是我们需要的，例如下面的 D3Dcompiler_47.dll，为了使发布程序尽可能的小，可以把这些 dll 一个一个删掉，再打开 exe 程序，看哪些 dll 是删掉后就打开不了程序的，保留下来，剩下的删除即可。其实到这一步，就可以将整个文件夹发布出去了，但如果想打包成一个 exe 安装包，使用Enigma Virtual Box将本目录打包为一个exe文件,即可。
试用了,在win32　debug,release,win64 debug都正常,win64 release不成功,后期再修改

2.试用github对程序代码版本管理
主要参考
https://blog.csdn.net/hebbely/article/details/52495073
备用
http://blog.leanote.com/post/paprikaxiong/Qt%E4%B8%AD%E9%85%8D%E7%BD%AEGit%E5%B9%B6%E4%B8%8A%E4%BC%A0%E8%87%B3Github-%E5%AE%8C%E5%85%A8%E6%96%B0%E6%89%8B%E5%90%91

2019.4.1 重写xyz2dat
1.学习视频教程后,即开始进行旧的WIN程序的重写与打包

# xyz2n
convert xyz file to others and convert others to xyz