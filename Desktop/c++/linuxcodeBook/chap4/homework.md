[toc]

# homework

学后感
## 硬链接与软链接的区别

硬链接是根据inode来查找文件，软连接根据文件名查找，这构成了基本区别。

当创建一个文件时，实际上是创建了inode，然后在父目录下，创建一个`名字-inode`对(硬链接)，指向该inode。硬链接文件类型和文件一致，只是inode cnt+1.

而软连接的文件类型是l.

硬链接不支持链接文件夹，也不支持链接文件系统。
链接文件夹会导致`ls -R`无线循环，而链接文件系统则是因为不同文件系统，inode可能是一样的。这样会导致问题。

而软链接可以链接文件夹和文件系统，因为软连接是根据文件路径来查找，如果不存在会返回空。

## 4.4

linux文件系统使用inode位图和逻辑块位图来管理inode和逻辑块。

超级块中会存储位图所占用的数据块。通过检查inode位图，可以知道空闲inode的信息。我的电脑是使用位图。

## 4.5

不会

## 4.6

不会

## 4.7

slink实际上是目录inode节点中的一个映射对，每个目录文件的父亲目录的inode中会有一个slink指向他，然后它自己的inode里也有一个slink `.->它`

## 4.8

如果一个目录的下层出现一个硬连接并指向它本身，ls -R会不断死循环。

## 4.9

如果mount目标文件夹为空，则不予执行。

如果mount目标文件夹中有其他文件存在，挂载能够成功。

挂载之后，该文件夹的inode号会改变。

1182814->2

为此，我写了一段代码验证，发现读取父目录的dirent之后，被mount的文件夹inode并没有改变。但是如果使用`ls -ail`，会发现inode已经替换成目标文件系统的根节点inode。
