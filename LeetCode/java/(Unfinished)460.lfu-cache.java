/*
 * @lc app=leetcode id=460 lang=java
 *
 * [460] LFU Cache
 */

// @lc code=start
public class xLFUCache<K, V> {

    private class Node {
        K key;
        V value;
        int cnt;
        Long time;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
            this.time = System.currentTimeMillis();
        }
    }

    Map<K, Node> map;
    PriorityQueue<Node> queue;
    int capacity;

    public xLFUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        this.queue = new PriorityQueue<>((a, b) -> {
            if (a.cnt == b.cnt) {
                return (int) (a.time - b.time);
            }
            return a.cnt - b.cnt;
        });

    }

    public V get(int key) {
        if (!map.containsKey(key)) {
            return null;
        }
        Node node = map.get(key);
        this.queue.remove(node);
        node.cnt += 1;
        node.time = System.currentTimeMillis();
        this.queue.add(node);
        return node.value;
    }

    public void put(K key, V value) {
        if (this.capacity > 0) {
            if (map.containsKey(key)) {
                Node node = map.get(key);
                this.queue.remove(node);
                node.value = value;
                node.cnt += 1;
                node.time = System.currentTimeMillis();
                this.queue.add(node);
            } else {
                if (this.map.size() >= this.capacity) {
                    removeLeastFrequent();
                }
                Node node = new Node(key, value);
                this.queue.add(node);
                this.map.put(key, node);
            }
        }
    }

    private void removeLeastFrequent() {
        if (!this.map.isEmpty()) {
            Node node = this.queue.remove();
            this.map.remove(node.key);
        }
    }
}

class LFUCache {

    xLFUCache<Integer, Integer> cache;

    public LFUCache(int capacity) {
        this.cache = new xLFUCache(capacity);
    }

    public int get(int key) {
        return cache.get(key) == null ? -1 : cache.get(key);
    }

    public void put(int key, int value) {
        cache.put(key, value);
    }
}

//---------------------------------------------------------
class LFUCacheA {
    class LFUCacheCore<K, V> {
        class Node {
            K key;
            V value;
            Integer freq;
            Integer time;

            Node(K key, V value) {
                this.key = key;
                this.value = value;
                freq = time = 0;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) {
                    return true;
                }
                if (o == null || getClass() != o.getClass()) {
                    return false;
                }
                Node node = (Node) o;
                return freq == node.freq &&
                        time == node.time &&
                        Objects.equals(key, node.key) &&
                        Objects.equals(value, node.value);
            }

            @Override
            public int hashCode() {
                return Objects.hash(key, value, freq, time);
            }
        }

        Integer capacity;
        Integer globalTime;
        Map<K, Node> map;
        TreeSet<Node> set;

        public LFUCacheCore(int capacity) {
            this.capacity = capacity;
            this.globalTime = 0;
            this.map = new HashMap<>(capacity);
            this.set = new TreeSet<>((a, b) -> {
                if (a.freq > b.freq) {
                    return 1;
                } else if (a.freq < b.freq) {
                    return -1;
                } else {
                    return a.time.compareTo(b.time);
                }
            });
        }

        public void put(K key, V value) {
            if (this.capacity == 0) return;
            if (map.containsKey(key)) {
                Node node = map.get(key);
                set.remove(node);
                node.value = value;
                ++node.freq;
                node.time = globalTime++;
                set.add(node);
            } else {
                if (map.size() >= this.capacity) {
                    removeLeastFrequent();
                }
                Node node = new Node(key, value);
                node.freq = 1;
                node.time = globalTime++;
                map.put(key, node);
                set.add(node);
            }
        }

        private void removeLeastFrequent() {
            if (map.size() > 0) {
                Node node = set.first();
                map.remove(node.key);
                set.remove(node);
            }
        }

        public V get(K key) {
            if (!map.containsKey(key)) {
                return null;
            }
            Node node = map.get(key);
            set.remove(node);
            ++node.freq;
            node.time = globalTime++;
            set.add(node);
            return node.value;
        }

    }

    LFUCacheCore<Integer, Integer> cache;

    public LFUCacheA(int capacity) {
        cache = new LFUCacheCore(capacity);
    }

    public int get(int key) {
        Integer value = cache.get(key);
        return value == null ? -1 : value;
    }

    public void put(int key, int value) {
        cache.put(key, value);
    }
}
//---------------------------------------------------------

public class LFUCacheB<K, V> {
    class Node {
        K key;
        V value;
        Integer freq;
        Node prev;
        Node next;

        Node(K key, V value) {
            this.key = key;
            this.value = value;
            this.freq = 0;
        }

        void unlink() {
            prev.next = next;
            next.prev = prev;
            prev = null;
            next = null;
        }
    }

    class DoubleLinkedList {
        Node head;
        Node tail;

        DoubleLinkedList() {
            head = new Node(null, null);
            tail = new Node(null, null);
            head.next = tail;
            tail.prev = head;
        }

        void appendHead(Node node) {
            node.next = head.next;
            head.next = node;
            node.prev = head;
            node.next.prev = node;
        }

        boolean isEmpty() {
            return head.next == tail;
        }
    }

    Integer capacity;
    Integer minFreq;
    HashMap<K, Node> cache;
    HashMap<Integer, DoubleLinkedList> freqTable;

    public LFUCacheB(Integer capacity) {
        this.capacity = capacity;
        minFreq = 0;
        cache = new HashMap<>();
        freqTable = new HashMap<>();
    }

    public void put(K key, V value) {
        if (capacity == 0) {
            return;
        }
        // 如果当前已经包含该 key，则更新 value。
        if (cache.containsKey(key)) {
            Node node = cache.get(key);
            node.value = value;
            this.get(key);
        } else {
            // 否则，加入
            if(cache.size()>=capacity){
                removeLeastFrequent();
            }
            Node node = new Node(key, value);
            node.freq = 1;
            cache.put(key, node);
            if (minFreq == 0) {
                ++minFreq;
            }
            DoubleLinkedList list = freqTable.getOrDefault(node.freq, new DoubleLinkedList());
            list.appendHead(node);
            freqTable.put(node.freq, list);
        }

    }

    private void removeLeastFrequent() {
        if(this.cache.isEmpty()) {
            return;
        }
        DoubleLinkedList list = this.freqTable.get(minFreq);
        Node node = list.tail.prev;
        node.unlink();
        cache.remove(node.key);
    }

    public V get(K key) {
        if (!cache.containsKey(key)) {
            return null;
        }
        // 从 cache 中取出 node
        Node node = cache.get(key);

        // 将 node 从对应的链表上取下来
        node.unlink();

        // 如果取下来后链表为空并且 node.freq == minFreq ++minFreq;
        if (freqTable.get(node.freq).isEmpty() && minFreq.equals(node.freq)) {
            ++minFreq;
        }

        // 将 node 加入到新的 freq 对应的链表中。
        ++node.freq;
        DoubleLinkedList list = freqTable.getOrDefault(node.freq, new DoubleLinkedList());
        list.appendHead(node);
        freqTable.put(node.freq, list);
        return node.value;
    }

    public static void main(String[] args) {
        LFUCacheB<Integer, Integer> cache = new LFUCacheB<Integer, Integer>(2);
        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println(cache.get(1));       // 返回 1
        cache.put(3, 3);    // 去除 key 2
        System.out.println(cache.get(2));       // 返回 -1 (未找到key 2)
        System.out.println(cache.get(3));       // 返回 3
        cache.put(4, 4);    // 去除 key 1
        System.out.println(cache.get(1));       // 返回 -1 (未找到 key 1)
        System.out.println(cache.get(3));       // 返回 3
        System.out.println(cache.get(4));       // 返回 4
    }

}

/**
 * Your LFUCache object will be instantiated and called as such: LFUCache obj =
 * new LFUCache(capacity); int param_1 = obj.get(key); obj.put(key,value);
 */
// @lc code=end
