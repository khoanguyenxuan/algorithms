

public class Leetcode1409 {
    private static int[] positions = null;

    public static void main(String[] args) {
        processQueries(new int[] { 7, 5, 5, 8, 3 }, 8);
    }

    public static int[] processQueries(int[] queries, int m) {
        int n = queries.length;
        int[] result = new int[n];

        positions = new int[n + m];
        int[] reverserIndexes = new int[m];

        for (int i = 0; i < m; i++) {
            reverserIndexes[i] = n + i;
            update(n + i, 1);
        }

        int k = n - 1;
        for (int i = 0; i < n; i++) {
            int j = reverserIndexes[queries[i] - 1];

            result[i] = query(j) - 1;
            if (result[i] > 0) {
                update(j, -1);
                reverserIndexes[queries[i] - 1] = k;
                update(k--, 1);
            }
        }

        return result;
    }

    private static void update(int idx, int value) {
        while (idx < positions.length && idx > 0) {
            positions[idx] += value;
            idx += idx & (-idx);
        }
    }

    private static int query(int idx) {
        int total = 0;
        while (idx > 0) {
            total += positions[idx];
            idx -= idx & (-idx);
        }

        return total;
    }
}
