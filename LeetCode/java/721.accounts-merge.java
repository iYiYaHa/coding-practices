/*
 * @lc app=leetcode id=721 lang=java
 *
 * [721] Accounts Merge
 *
 * https://leetcode.com/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (48.23%)
 * Likes:    1987
 * Dislikes: 368
 * Total Accepted:    117.5K
 * Total Submissions: 229.7K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * Given a list accounts, each element accounts[i] is a list of strings, where
 * the first element accounts[i][0] is a name, and the rest of the elements are
 * emails representing emails of the account.
 * 
 * Now, we would like to merge these accounts.  Two accounts definitely belong
 * to the same person if there is some email that is common to both accounts.
 * Note that even if two accounts have the same name, they may belong to
 * different people as people could have the same name.  A person can have any
 * number of accounts initially, but all of their accounts definitely have the
 * same name.
 * 
 * After merging the accounts, return the accounts in the following format: the
 * first element of each account is the name, and the rest of the elements are
 * emails in sorted order.  The accounts themselves can be returned in any
 * order.
 * 
 * Example 1:
 * 
 * Input: 
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 * "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 * "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com',
 * 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
 * "mary@mail.com"]]
 * Explanation: 
 * The first and third John's are the same person as they have the common email
 * "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email
 * addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary',
 * 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
 * would still be accepted.
 * 
 * 
 * 
 * Note:
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 * 
 */

// @lc code=start
class Solution {

    class UnionFind {
        HashMap<String, String> parent;
        HashMap<String, Integer> size;

        UnionFind() {
            parent = new HashMap<>();
            size = new HashMap<>();
        }

        public void union(String a, String b) {
            createIfNotExist(a);
            createIfNotExist(b);
            String rootA = getRoot(a);
            String rootB = getRoot(b);
            if (rootA.equals(rootB)) {
                return;
            }
            int sizeA = size.get(a);
            int sizeB = size.get(b);
            if (sizeA <= sizeB) {
                parent.put(rootA, rootB);
                size.put(rootB, sizeA + sizeB);
            } else {
                parent.put(rootB, rootA);
                size.put(rootA, sizeA + sizeB);
            }
        }

        public String getRoot(String i) {
            if (!parent.containsKey(i))
                return null;

            if (i.equals(parent.get(i))) {
                return i;
            } else {
                parent.put(i, getRoot(parent.get(i)));
                return parent.get(i);
            }
        }

        public boolean containsKey(String i) {
            return parent.containsKey(i);
        }

        public void createIfNotExist(String i) {
            if (!parent.containsKey(i)) {
                parent.put(i, i);
                size.put(i, 1);
            }
        }

        public HashMap<String, List<String>> getComponents() {
            HashMap<String, List<String>> res = new HashMap<>();
            for (String ele : parent.keySet()) {
                String root = getRoot(ele);
                List<String> lst = res.getOrDefault(root, new LinkedList<>());
                lst.add(ele);
                res.put(root, lst);
            }
            return res;
        }
    }

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        if (accounts == null || accounts.isEmpty())
            return new LinkedList<>();

        UnionFind uf = new UnionFind();
        HashMap<String, String> nameTable = new HashMap<>();
        for (List<String> nameAndEmails : accounts) {
            String name = nameAndEmails.get(0);
            String firstEmail = nameAndEmails.get(1);

            for (int i = 1; i < nameAndEmails.size(); ++i) {
                String email = nameAndEmails.get(i);
                uf.union(firstEmail, email);
                nameTable.put(email, name);
            }
        }
        HashMap<String, List<String>> rootAndEmails = uf.getComponents();
        List<List<String>> res = new LinkedList<>();
        for (Map.Entry<String, List<String>> entry : rootAndEmails.entrySet()) {
            LinkedList<String> account = new LinkedList<>();

            String root = entry.getKey();
            List<String> mails = entry.getValue();

            for (String mail : mails) {
                account.add(mail);
            }
            Collections.sort(account);

            account.addFirst(nameTable.get(root));
            res.add(account);
        }
        return res;
    }
}
// @lc code=end
