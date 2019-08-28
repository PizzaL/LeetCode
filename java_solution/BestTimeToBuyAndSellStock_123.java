


class BestTimeToBuyAndSellStock_121 {
    public int maxProfit(int[] prices) {
        int size = prices.length;
        if ( size <= 0 ) {
            return 0;
        }
        int[] profile = new int[size];
        int res = 0;
        profile[0] = 0;
        for (int i = 1; i < size; ++i) {            
            profile[i] = Math.max(0, profile[i-1]+prices[i]-prices[i-1]);
            res = Math.max(res, profile[i]);
        }
        return res;
    }

    public static void main(String[] args) {

    }
}