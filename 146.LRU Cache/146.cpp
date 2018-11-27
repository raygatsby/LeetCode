//
// Created by 许雷 on 2018/11/27.
//

//146.LRU缓存机制
//12.53
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
class LRUCache {
public:
    LRUCache(int capacity) {

        _capacity = capacity;
    }

    int get(int key) {

        auto item = hash.find(key);

        if(item == hash.end())
            return -1;  // hash表中没有这条记录

        // 把这个双向链表的结点移到链表的头部 表示最近访问过
        list1.splice(list1.begin(),list1,item->second);
        return item->second->second;
    }


    void put(int key, int value) {

        auto item = hash.find(key);

        // 如果要放入的键值对不在缓冲区内
        if(item == hash.end()){

            if(hash.size() == _capacity){
                // 缓冲区满了需要删除最尾端的元素
                int del = list1.back().first;
                hash.erase(del);
                list1.pop_back();
            }
            // 在缓冲区头部插入这个键值对
            list1.push_front({key,value});
            hash[key] = list1.begin();
            return;
        }

        // 当这个键值对在缓冲区时
        // 先更新值 在插入到链表头部
        item->second->second = value;
        list1.splice(list1.begin(),list1,item->second);

        return;
    }

private:
    unordered_map<int,list<pair<int,int>>::iterator> hash;  // 哈希表
    list<pair<int,int>> list1;  // 双向链表  list是缓冲区
    int _capacity; // 缓冲区大小
};
