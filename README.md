# sumoverSTL
personal STL test
sumover的STL的简单实现~
目前更新：
  list

1.list功能实现:
  1.1 空初始化
  1.2 拷贝构造函数
  1.3 size() 当前大小
  1.4 begin() 链表begin位置的值
  1.5 end() 链表end位置的值
  1.6 add_begin()向头部添加值
  1.7 add_end()向尾部增加值
  1.7 insert（pos,value) 在pos后插入一个值
  1.8 delete_begin,delete_end 删头删尾
  1.9 deleteAt 指定位置删除
  1.10 map（__func）用__func对所有值进行处理，#attention！__func参数列表有且仅有一个引用值
  1.11 filter（__func）用__func对所有值进行遍历，返回值为0或false时删除当前节点（提取器）#attention！__func参数列表有且仅有一个值，且返回值仅为int或bool
  1.12 ranger：
    1.12.1 rangr（__func,end）从0遍历至end位置，用__func对范围值进行处理，方法同1.10
    1.12.2 ranger(__func,begin,end) 从begin，遍历至end，同1.12.1
    1.12.3 ranger（__func,begin,end,step）从begin位置遍历至end，每次间隔为step
  1.13 下标访问值 [] list[2],与数组差不多的用法，，
