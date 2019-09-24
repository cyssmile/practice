### 关联容器的特点及接口
>* 每个关联容器都有一个键(key),可以高效的进行查找
>* 接口 
. 插入 insert
. 删除 erase
. 查找 find
.定界 lower_bound ,upper_bound,equal_range
. 计数count
### 四种关联容器
1. 单重关联容器(map和set)
> 键值唯一的,一个键值对应唯一的元素
2. 多重关联容器(multiset和multimap)
> 键值不唯一,一个键值可以对应多个元素
3. 简单的关联容器(set和multiset)
> 容器只有一个类型参数  ,如set<key>,multiset<key>,表示键的类型
> 容器元素就是键的本身
4. 二元关联容器(map 和multimap)
容器有两个类型参数,如map<K,V> ,multimap<K,V>
分别表示键和附加的数据类型
    容器的元素类型是pair<K,V>,即由键类型和元素类型复合而成的二元组

