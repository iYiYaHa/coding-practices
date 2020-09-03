import java.util.*;

/**
 * @author: MingSha
 * @mail: mingsha.zyj@alibaba-inc.com
 * @date: Created in 8:57 PM 2020/8/8
 * @desc:
 */
public class MST {
    static class Edge{
        int from;
        int to;
        int weight;

        Edge(int from, int to, int weight){
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        int getFrom(){
            return from;
        }

        int getTo(){
            return to;
        }

        int getWeight(){
            return weight;
        }
    }

    static Integer getParent(Map<Integer, Integer> parents, Integer node){
        if(parents.get(node).equals(node)) {
            return node;
        }
        parents.put(node, getParent(parents,parents.get(node)));
        return parents.get(node);
    }
    static long kruskal(int n, ArrayList<Edge> edges){
        if(edges == null || edges.size() == 0) {
            return 0L;
        }
        edges.sort(Comparator.comparingLong(edge->edge.weight));
        Map<Integer, Integer> parents = new HashMap<>();
        for(int i = 0;i <= n;++i){
            parents.put(i,i);
        }
        int cnt = 0;
        long weightSum = 0;
        for(int i = 0;i < edges.size();++i){
            Edge edge = edges.get(i);
            int fromNode = edge.from;
            int toNode = edge.to;
            int weight = edge.weight;
            int fromParent = getParent(parents, fromNode);
            int toParent = getParent(parents, toNode);
            if(fromParent == toParent) {
                continue;
            }
            parents.put(fromParent, toParent);
            ++cnt;
            weightSum += weight;
            if(cnt == n-1) {
                break;
            }
        }
        return cnt == n-1?weightSum:-1L;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Edge> edges = new ArrayList<>();
        for(int i = 0;i < m;++i){
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int weight = scanner.nextInt();
            edges.add(new Edge(from, to, weight));
        }
        long result = kruskal(n, edges);
        System.out.println(result != -1?result:"orz");
    }
}
