/*
 * @lc app=leetcode id=460 lang=java
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {

    private LFUCacheCore<Integer, Integer> core;

    public LFUCache(int capacity) {
        core = new LFUCacheCore<>(capacity);
    }
    
    public int get(int key) {
        Integer val = core.get(key);
        return val == null ? -1 : val;
    }
    
    public void put(int key, int value) {
        core.put(key, value);
    }

    class LFUCacheCore<K, V> {
        private int capacity;

        private Map<K, Node> map;

        private Map<Long, DoubleLinkedList> freqMap;

        private long minFreq;

        LFUCacheCore(int capacity) {
            this.capacity = capacity;
            map = new HashMap<>();
            freqMap = new HashMap<>();
            minFreq = 0L;
        }

        public V get(K key) {
            if (!map.containsKey(key)) {
                return null;
            }
            Node node = map.get(key);
            increNodeFreq(node);
            return node.value;
        }

        private void increNodeFreq(Node node) {
            // 1. node freq increment
            long oldFreq = node.freq;
            node.freq += 1l;

            // 2. unlink from current list
            node.unlink();

            // 3. if current list is empty after unlinking, remove.
            DoubleLinkedList oldFreqList = freqMap.getOrDefault(oldFreq, new DoubleLinkedList());
            if (minFreq == oldFreq && (oldFreqList.isEmpty())) {
                minFreq += 1;
            }

            // 4. put node to new freq list
            DoubleLinkedList list = freqMap.getOrDefault(node.freq, new DoubleLinkedList());
            list.appendHead(node);
            freqMap.put(node.freq, list);
        }

        public void put(K key, V value) {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                node.value = value;
                increNodeFreq(node);
            } else {
                if (map.size() >= this.capacity) {
                    removeLeastFreq();
                }
                Node node = new Node(key, value);
                minFreq = 0L;
                increNodeFreq(node);
                map.put(key, node);
            }

        }

        private void removeLeastFreq() {
            DoubleLinkedList list = freqMap.get(minFreq);
            if (list == null || list.isEmpty()) {
                return;
            }
            Node node = list.getLast();
            node.unlink();
            if (list.isEmpty()) {
                freqMap.remove(node.freq);
            }
            map.remove(node.key);
        }

        class Node {
            private K key;

            private V value;

            private long freq;

            private Node next;

            private Node prev;

            Node() {}

            Node(K key, V value) {
                this.key = key;
                this.value = value;
                this.freq = 0L;
            }

            public void unlink() {
                if (this.next == null && this.prev == null) {
                    return;
                }
                
                Node next = this.next;
                Node prev = this.prev;
                next.prev = prev;
                prev.next = next;
                this.next = null;
                this.prev = null;
            }
        }

        class DoubleLinkedList {
            private Node head;

            private Node tail;

            DoubleLinkedList() {
                head = new Node();
                tail = new Node();
                head.next = tail;
                tail.prev = head;
            }

            public boolean isEmpty() {
                return head.next == tail;
            }

            public void appendHead(Node node) {
                node.next = head.next;
                node.prev = head;
                head.next = node;
                node.next.prev = node;
            }

            public Node getLast() {
                if (head.next == tail) {
                    return null;
                }
                return tail.prev;
            }
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end

