/*
 * @lc app=leetcode id=146 lang=java
 *
 * [146] LRU Cache
 */

// @lc code=start
import java.util.Map;
import java.util.HashMap;

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

        public void put(K key, V value) {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                node.value = value;
                unlink(node);
                appendHead(node);
                map.put(key, node);
            } else {
                Node node = new Node(key, value);
                appendHead(node);
                map.put(key, node);
            }
            if (map.size() > this.capacity) {
                removeOldest();
            }
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

        private void unlink(Node node) {
            Node next = node.next;
            Node prev = node.prev;
            next.prev = prev;
            prev.next = next;
            node.next = null;
            node.prev = null;
        }

        private void appendHead(Node node) {
            node.next = head.next;
            node.prev = head;
            head.next = node;
            node.next.prev = node;
        }

        private void removeOldest() {
            if (head.next == tail) {
                return;
            }
            Node oldest = tail.prev;
            unlink(oldest);
            map.remove(oldest.key);
        }



        private class Node {

            private K key;

            private V value;

            private Node next;

            private Node prev;

            Node() {

            }

            Node(K key, V value) {
                this.key = key;
                this.value = value;
                this.next = null;
                this.prev = null;
            }
        }
    }

    private LRUCacheCore<Integer, Integer> lru;

    public LRUCache(int capacity) {
        lru = new LRUCacheCore<>(capacity);
    }
    
    public int get(int key) {
        Integer val = lru.get(key);
        return val == null ? -1 : val;
    }
    
    public void put(int key, int value) {
        lru.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end

