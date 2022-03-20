//You are given two jugs with capacities jug1Capacity and jug2Capacity liters. 
//There is an infinite amount of water supply available. Determine whether it is 
//possible to measure exactly targetCapacity liters using these two jugs. 
//
// If targetCapacity liters of water are measurable, you must have 
//targetCapacity liters of water contained within one or both buckets by the end. 
//
// Operations allowed: 
//
// 
// Fill any of the jugs with water. 
// Empty any of the jugs. 
// Pour water from one jug into another till the other jug is completely full, 
//or the first jug itself is empty. 
// 
//
// 
// Example 1: 
//
// 
//Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
//Output: true
//Explanation: The famous Die Hard example 
// 
//
// Example 2: 
//
// 
//Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
//Output: false
// 
//
// Example 3: 
//
// 
//Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
//Output: true
// 
//
// 
// Constraints: 
//
// 
// 1 <= jug1Capacity, jug2Capacity, targetCapacity <= 10⁶ 
// 
// Related Topics Math Depth-First Search Breadth-First Search 👍 725 👎 1085


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity == targetCapacity) {
            return true;
        }
        if ((jug1Capacity & 1) == 0 && (jug2Capacity & 1) == 0 && (targetCapacity & 1) != 0) {
            return false;
        }
        Queue<State> queue = new LinkedList<>();
        queue.offer(new State(0, 0));
        Set<State> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            State cur = queue.poll();
            if (cur.jug1Volume + cur.jug2Volume == targetCapacity || cur.jug1Volume == targetCapacity || cur.jug2Volume == targetCapacity) {
                return true;
            }
            if (visited.contains(cur)) {
                continue;
            }
            visited.add(cur);
            if (cur.jug1Volume > 0) {
                queue.offer(new State(0, cur.jug2Volume));
            }

            if (cur.jug2Volume > 0) {
                queue.offer(new State(cur.jug1Volume, 0));
            }

            queue.offer(new State(jug1Capacity, cur.jug2Volume));
            queue.offer(new State(cur.jug1Volume, jug2Capacity));

            if (cur.jug1Volume > 0 && cur.jug2Volume < jug2Capacity) {
                queue.offer(new State(cur.jug1Volume - Math.min(cur.jug1Volume, jug2Capacity - cur.jug2Volume),
                        cur.jug2Volume + Math.min(cur.jug1Volume, jug2Capacity - cur.jug2Volume)));
            }

            if (cur.jug2Volume > 0 && cur.jug1Volume < jug1Capacity) {
                queue.offer(new State(cur.jug1Volume + Math.min(cur.jug2Volume, jug1Capacity - cur.jug1Volume),
                        cur.jug2Volume - Math.min(cur.jug2Volume, jug1Capacity - cur.jug1Volume)));
            }
        }
        return false;
    }

    private class State{
        private int jug1Volume;
        private int jug2Volume;

        State(int jug1Volume, int jug2Volume){
            this.jug1Volume = jug1Volume;
            this.jug2Volume = jug2Volume;
        }

        @Override
        public int hashCode(){
            return Objects.hash(jug1Volume, jug2Volume);
        }

        @Override
        public boolean equals(Object other) {
            if (this == other) {
                return true;
            }
            if (!(other instanceof State)) {
                return false;
            }
            State otherState = (State) other;
            return this.jug1Volume == otherState.jug1Volume && this.jug2Volume == otherState.jug2Volume;
        }
    }
}

// Pouring from a to b is like (0, (n * a) % b)
// Pouring from b to a is like ((n * b) % a, 0)
// Empty a is -a
// Empty b is -b
// Fill a is +a
// Fill b is -b
class SolutionB {
    public boolean canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity + jug2Capacity < targetCapacity){
            return false;
        }
        return (targetCapacity % gcd(jug1Capacity, jug2Capacity)) == 0;
    }

    private int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
