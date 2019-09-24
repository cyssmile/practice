## 顺序容器
STL 中的容器有
vector deque list forward_list array
* 元素线性排列,可以随时在指定位置插入和删除元素
* 必须符合Assignable 这一个概念(即具有共有的复制构造函数,可以用"="进行赋值)
* array对象的大小固定,forward_list 有特殊的插入和删除操作
### 顺序容器的接口(不包括array和forward_list)
* 构造函数
* 赋值函数
    assign
* 插入函数
    insert  push_front,push_back,emplace,emplace_front
* 删除函数
    erase ,clear    ,pop_front pop_back,emplace_back
* 首尾元素直接访问
front back
* 改变大小
resize