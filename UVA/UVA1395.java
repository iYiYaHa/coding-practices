public class SlimSpan {
    static class Edge {
        Integer from;
        Integer to;
        Long weight;

        Edge(Integer from, Integer to, Long weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        Integer getFrom() {
            return from;
        }

        Integer getTo() {
            return to;
        }

        Long getWeight() {
            return weight;
        }
    }

    static Integer findLabel(Map<Integer, Integer> labels, Integer node) {
        if (labels.get(node).equals(node)) {
            return node;
        }
        labels.put(node, findLabel(labels, labels.get(node)));
        return labels.get(node);
    }

    static Long solveCore(int n, ArrayList<Edge> edges, int start) {
        Map<Integer, Integer> labels = new HashMap<>(n);
        for (int node = 0; node <= n; ++node) {
            labels.put(node, node);
        }
        Long maxWeight = Long.MIN_VALUE;
        Long minWeight = Long.MAX_VALUE;
        int cnt = 0;
        for (int i = start; i < edges.size(); ++i) {
            Edge edge = edges.get(i);
            Integer fromNode = edge.getFrom();
            Integer toNode = edge.getTo();
            Long weight = edge.getWeight();
            int fromLabel = findLabel(labels, fromNode);
            int toLabel = findLabel(labels, toNode);
            if (fromLabel == toLabel) {
                continue;
            }
            ++cnt;
            labels.put(fromLabel, toLabel);
            maxWeight = Math.max(maxWeight, weight);
            minWeight = Math.min(minWeight, weight);
            if(cnt == n-1) {
                break;
            }
        }
        if (cnt == n - 1) {
            return maxWeight - minWeight;
        }
        return -1L;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            long ans = Long.MAX_VALUE;
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            if (n == 0) {
                break;
            }
            ArrayList<Edge> edges = new ArrayList<>(m);
            for (int i = 0; i < m; ++i) {
                int from = scanner.nextInt();
                int to = scanner.nextInt();
                Long weight = scanner.nextLong();
                edges.add(new Edge(from, to, weight));
            }
            edges.sort(Comparator.comparingLong(edge -> edge.weight));
            for (int i = 0; i < m; ++i) {
                Long tmp = solveCore(n, edges, i);
                if (tmp != -1) {
                    ans = Math.min(ans, tmp);
                }
            }
            System.out.println(ans == Long.MAX_VALUE ? -1 : ans);
        }
    }
}