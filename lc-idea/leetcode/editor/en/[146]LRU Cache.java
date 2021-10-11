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
// Related Topics Hash Table Linked List Design Doubly-Linked List 👍 10278 👎 4
//05


//leetcode submit region begin(Prohibit modification and deletion)
class LRUCacheCore<K, V> {
    private static final int DEFAULT_CAPACITY = 8;
    private final int capacity;
    private int size;
    private final Map<K, Node<K, V>> cacheMap;
    private final Node<K, V> head;
    private final Node<K, V> tail;

    static public class Node<K, V> {
        private Node<K, V> prev;
        private Node<K, V> next;
        private K key;
        private V value;

        public Node() {
        }

        public Node(K key, V value) {
            this(key, value, null, null);
        }

        public Node(K key, V value, Node<K, V> prev, Node<K, V> next) {
            this.key = key;
            this.value = value;
            this.prev = prev;
            this.next = next;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V newValue) {
            V oldVal = this.value;
            this.value = newValue;
            return oldVal;
        }

        public Node<K, V> getPrev() {
            return prev;
        }

        public Node<K, V> getNext() {
            return next;
        }

        public void setPrev(Node<K, V> prev) {
            this.prev = prev;
        }

        public void setNext(Node<K, V> next) {
            this.next = next;
        }
    }

    public LRUCacheCore() {
        this(DEFAULT_CAPACITY);
    }

    public LRUCacheCore(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.cacheMap = new HashMap<>(this.capacity);
        head = new Node<>();
        tail = new Node<>();
        head.setNext(tail);
        tail.setPrev(head);
    }

    public void put(K key, V value) {
        Node<K, V> node = null;
        // Update the k-v pair if already existed.
        if (cacheMap.containsKey(key)) {
            node = cacheMap.get(key);
            node.setValue(value);
            unlink(node);
        } else {
            // Put the k-v pair into the map if not existed.
            node = new Node<K, V>(key, value);
            ++size;
            cacheMap.put(key, node);
        }

        // Put the node into the foremost
        appendHead(node);

        if (ifRemoveEldestEntry()) {
            removeEldest();
        }
    }

    private void unlink(Node<K, V> node) {
        Node<K, V> prev = node.prev;
        Node<K, V> next = node.next;
        prev.next = next;
        next.prev = prev;
        node.prev = null;
        node.next = null;
    }

    private void appendHead(Node<K, V> node) {
        node.next = head.next;
        head.next.prev = node;
        node.prev = head;
        head.next = node;
    }

    private void removeEldest() {
        if (head.next != tail) {
            --size;
            Node<K, V> node = tail.prev;
            this.cacheMap.remove(node.getKey());
            unlink(node);
        }
    }

    public V get(K key) {
        if (!cacheMap.containsKey(key)) {
            return null;
        }
        Node<K, V> node = cacheMap.get(key);
        unlink(node);
        appendHead(node);
        return node.getValue();
    }

    public int size() {
        return size;
    }

    private boolean ifRemoveEldestEntry() {
        return this.size() > this.capacity;
    }
}
class LRUCache {

    private final LRUCacheCore<Integer, Integer> cache;
    public LRUCache(int capacity) {
        this.cache = new LRUCacheCore<>(capacity);
    }
    
    public int get(int key) {
        Integer val = this.cache.get(key);
        return val == null ? -1 : val;
    }
    
    public void put(int key, int value) {
        this.cache.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
