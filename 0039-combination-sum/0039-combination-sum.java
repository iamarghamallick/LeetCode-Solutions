class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(0, new ArrayList<>(), ans, 0, candidates, target);
        return ans;
    }

    private void solve(int i, List<Integer> list, List<List<Integer>> ans, int sum, int[] candidates, int target) {
        if (sum == target) {
            ans.add(new ArrayList<>(list));
            return;
        }

        if (i == candidates.length || sum > target) {
            return;
        }

        solve(i + 1, list, ans, sum, candidates, target);

        list.add(candidates[i]);
        sum += candidates[i];

        solve(i, list, ans, sum, candidates, target);

        list.remove(list.get(list.size() - 1));
        sum -= candidates[i];
    }
}