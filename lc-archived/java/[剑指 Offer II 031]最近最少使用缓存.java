//English description is not available for the problem. Please switch to 
//Chinese. 
//
// Related Topics 设计 哈希表 链表 双向链表 👍 68 👎 0

//leetcode submit region begin(Prohibit modification and deletion)

class LRUCacheCore<K, V> {

    private int capacity;
    private Map<K, Node> map;
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

    public V get(V key) {
        if (!map.containsKey(key)) {
            return null;
        }
        Node node = map.get(key);
        unlink(node);
        appendHead(node);
        return node.value;
    }

    private void appendHead(Node node) {
        if (node == null) {
            return;
        }
        node.next = head.next;
        head.next.prev = node;
        node.prev = head;
        head.next = node;
    }

    private void unlink(Node node) {
        if (node == null) {
            return;
        }
        Node prev = node.prev;
        Node next = node.next;
        prev.next = next;
        next.prev = prev;
        node.prev = null;
        node.next = null;
    }

    public void put(K key, V value) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value = value;
            unlink(node);
            appendHead(node);
        } else {
            Node node = new Node(key, value);
            map.put(key, node);
            appendHead(node);
        }
        if (map.size() > this.capacity) {
            removeEldestEntry();
        }
    }

    private void removeEldestEntry() {
        if (head.next != tail) {
            Node node = tail.prev;
            unlink(node);
            map.remove(node.key);
        }
    }

    class Node {

        K key;
        V value;
        Node prev;
        Node next;

        public Node() {
        }

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
}

class LRUCache {

    private LRUCacheCore<Integer, Integer> cache;

    public LRUCache(int capacity) {
        cache = new LRUCacheCore<Integer, Integer>(capacity);
    }

    public int get(int key) {
        Integer value = cache.get(key);
        return value != null ? value : -1;
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
