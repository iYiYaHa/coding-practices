//Design a data structure that follows the constraints of a Least Recently Used 
//(LRU) cache. 
//
// Implement the LRUCache class: 
//
// 
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity. 
//
// int get(int key) Return the value of the key if the key exists, otherwise 
//return -1. 
// void put(int key, int value) Update the value of the key if the key exists. 
//Otherwise, add the key-value pair to the cache. If the number of keys exceeds 
//the capacity from this operation, evict the least recently used key. 
// 
//
// The functions get and put must each run in O(1) average time complexity. 
//
// 
// Example 1: 
//
// 
//Input
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//Explanation
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // cache is {1=1}
//lRUCache.put(2, 2); // cache is {1=1, 2=2}
//lRUCache.get(1);    // return 1
//lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//lRUCache.get(2);    // returns -1 (not found)
//lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//lRUCache.get(1);    // return -1 (not found)
//lRUCache.get(3);    // return 3
//lRUCache.get(4);    // return 4
// 
//
// 
// Constraints: 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 10⁴ 
// 0 <= value <= 10⁵ 
// At most 2 * 10⁵ calls will be made to get and put. 
// 
//
// Related Topics Hash Table Linked List Design Doubly-Linked List 👍 20965 👎 1
//061


import java.util.HashMap;
import java.util.Map;

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {

    class LRUCacheCore<K, V> {
        private int capacity;
        private Map<K, Node> map;
        private Node head;
        private Node tail;

        LRUCacheCore(int capacity) {
            this.capacity = capacity;
            map = new HashMap<>();
            head = new Node();
            tail = new Node();
            head.next = tail;
            tail.prev = head;
        }

        public V get(K key) {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                unlink(node);
                appendHead(node);
                return node.value;
            }
            return null;
        }

        public void put(K key, V value) {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                node.value = value;
                unlink(node);
                appendHead(node);
            } else {
                Node node = new Node();
                node.key = key;
                node.value = value;
                appendHead(node);
                map.put(key, node);
            }
            if (map.size() > capacity) {
                removeEldest();
            }

        }

        private void unlink(Node node) {
            Node prev = node.prev;
            Node next = node.next;
            prev.next = next;
            next.prev = prev;
            node.prev = null;
            node.next = null;
        }

        private void appendHead(Node node) {
            Node next = head.next;
            head.next = node;
            node.prev = head;
            node.next = next;
            next.prev = node;
        }

        private void removeEldest() {
            if (head.next != tail){
                Node node = tail.prev;
                unlink(node);
                map.remove(node.key);
            }
        }

        class Node {
            private K key;
            private V value;
            private Node prev;
            private Node next;
        }


    }

    private LRUCacheCore<Integer, Integer> cache;
    public LRUCache(int capacity) {
        this.cache = new LRUCacheCore<>(capacity);
    }
    
    public int get(int key) {
        Integer value = cache.get(key);
        return value == null ? -1 : value;
    }
    
    public void put(int key, int value) {
        cache.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
