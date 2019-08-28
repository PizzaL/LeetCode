class DivisorGame_1025 {
    public boolean divisorGame(int N) {
        boolean[] res = new boolean[N+1];
        for (int i = 1; i <= N; ++i) {
            res[i] = false;
            for (int j = 1; j < Math.sqrt(i); ++j) {
                if (i % j == 0) {
                    res[i] = res[i] || !res[i-j] 
                          || (j!=1 && !res[i-i/j]); 
                }
            }
        }
        return res[N];
    }
    public static void main(String[] args) {}
}