### 顺序容器的插入迭代器
用于向 容器的前,后,中间等位置插入元素的迭代器
>* 前插迭代器 front_inserter ,后插迭代器 back_inserter
>* 任意位置插入的迭代器 inserter
例如
```
 list<int> s;
 //back_inserter iter(s);
 *(back_inserter(s)++)=5;//将5插入,然后指针向后移动
```