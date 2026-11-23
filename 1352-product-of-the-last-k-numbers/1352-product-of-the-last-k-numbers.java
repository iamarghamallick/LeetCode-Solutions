class ProductOfNumbers {

    private ArrayList<Integer> arr;

    public ProductOfNumbers() {
        arr = new ArrayList<>();
    }

    public void add(int num) {
        if (num == 0) {
            arr = new ArrayList<>();
            return;
        }

        int n = arr.size();

        if (n > 0) {
            arr.add(arr.get(n - 1) * num);
        } else {
            arr.add(num);
        }
    }

    public int getProduct(int k) {
        int n = arr.size();

        if (k > n) {
            return 0;
        }

        if (k == n) {
            return arr.get(n - 1);
        }

        return arr.get(n - 1) / arr.get(n - k - 1);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */