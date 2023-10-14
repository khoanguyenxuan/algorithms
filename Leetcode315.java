import java.util.ArrayList;
import java.util.List;

class Leetcode315 {
    static int[] bits = new int[20005];

    public static void main(String[] args) {
        countSmaller(new int[] { 5, 2, 6, 1 });
    }

    public static List<Integer> countSmaller(int[] nums) {
        List<Integer> result = new ArrayList<>();

        for (int i = nums.length - 1; i >= 0; i--) {
            update(nums[i] + 10001);
            result.add(0, query(nums[i] + 10000));
        }

        return result;
    }

    private static void update(int idx) {
        while (idx < bits.length) {
            bits[idx]++;
            idx += idx & (-idx);
        }
    }

    private static int query(int idx) {
        int total = 0;
        while (idx > 0) {
            total += bits[idx];
            idx -= idx & (-idx);
        }
        return total;
    }
}