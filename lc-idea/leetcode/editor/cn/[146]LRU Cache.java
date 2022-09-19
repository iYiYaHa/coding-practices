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
// Related Topics 设计 哈希表 链表 双向链表 👍 2392 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class LRUCacheCore<K, V> {

    private Map<K, Node> map;
    private Integer capacity;
    private Node head;
    private Node tail;

    public LRUCacheCore(int capacity) {
        map = new HashMap<>(capacity);
        this.capacity = capacity;
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
    }

    public V get(K key) {
        if (!map.containsKey(key)) {
            return null;
        }
        Node node = map.get(key);
        unlink(node);
        appendHead(node);
        return node.val;
    }

    public void put(K key, V value) {
        Node node = null;
        if (!map.containsKey(key)) {
            node = new Node(key, value);
        } else {
            node = map.get(key);
            node.val = value;
            unlink(node);
        }
        map.put(key, node);
        appendHead(node);
        if (map.size() > this.capacity) {
            removeEldest();
        }
    }

    private void removeEldest() {
        if(head.next != tail) {
            Node eldest = tail.prev;
            map.remove(eldest.key);
            unlink(eldest);
        }
    }

    private void unlink(Node node) {
        if (node == null) {
            return;
        }
        Node prev = node.prev;
        Node next = node.next;
        prev.next = next;
        next.prev = prev;
        node.next = null;
        node.prev = null;
    }

    private void appendHead(Node node) {
        if (node == null) {
            return;
        }
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }

    private class Node {

        private Node prev;
        private Node next;
        private K key;
        private V val;

        Node() {
            key = null;
            val = null;
            next = prev = null;
        }

        Node(K key, V val) {
            this.key = key;
            this.val = val;
            this.prev = this.next = null;
        }
    }
}

class LRUCache {

    private LRUCacheCore<Integer, Integer> cache;

    public LRUCache(int capacity) {
        cache = new LRUCacheCore<Integer, Integer>(capacity);

    }

    public int get(int key) {
        Integer result = cache.get(key);
        return result == null ? -1 : result;

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
