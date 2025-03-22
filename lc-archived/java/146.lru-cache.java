import java.util.Map;

/*
 * @lc app=leetcode id=146 lang=java
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRU<K, V> {

    private class Node {
        K key;
        V value;
        Node prev;
        Node next;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
            this.prev = null;
            this.next = null;
        }
    }

    Map<K, Node> map;
    Node head;
    Node tail;
    Integer capcity;

    public LRU(Integer capacity) {
        this.capcity = capacity;
        map = new HashMap<>();
        head = new Node(null, null);
        tail = new Node(null, null);
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
        return node.value;
    }

    public void put(K key, V value) {
        Node node = null;
        if (map.containsKey(key)) {
            node = map.get(key);
            node.value = value;
            unlink(node);
        } else {
            node = new Node(key,value);
        }
        map.put(key,node);
        appendHead(node);
        if (this.map.size() > this.capcity) {
            removeTail();
        }
    }

    private void unlink(Node node){
        Node next = node.next;
        Node prev = node.prev;
        next.prev=prev;
        prev.next=next;
        node.prev=null;
        node.next=null;
    }

    private void appendHead(Node node){
        node.next=head.next;
        head.next=node;
        node.next.prev=node;
        node.prev=head;
    }

    private void removeTail(){
        if(head.next != tail){
            Node eldest = tail.prev;
            this.map.remove(eldest.key);
            unlink(eldest);
        }
    }
}

public class LRUCache {

    LRU<Integer, Integer> cache;

    public LRUCache(int capacity) {
        this.cache = new LRU<>(capacity);
    }

    public int get(int key) {
        Integer res = cache.get(key);
        return res == null ? -1 : res;
    }

    public void put(int key, int value) {
        cache.put(key, value);
    }

    public static void main(String[] args) {
        LRUCache cache = new LRUCache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println(cache.get(1));
        cache.put(3, 3);
        //-1
        System.out.println(cache.get(2));
        cache.put(4, 4);
        //-1
        System.out.println(cache.get(1));
        System.out.println(cache.get(3));
        System.out.println(cache.get(4));
    }
}


/**
 * Your LRUCache object will be instantiated and called as such: LRUCache obj =
 * new LRUCache(capacity); int param_1 = obj.get(key); obj.put(key,value);
 */
// @lc code=end
