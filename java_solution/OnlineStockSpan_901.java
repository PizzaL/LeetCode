import java.util.Vector;

class StockSpanner {
    private Vector<Integer> prices;
    private Vector<Integer> spans;
    
    public StockSpanner() {
        prices = new Vector<Integer>();
        spans = new Vector<Integer>();
    }
    
    public int next(int price) {
        prices.add(price);
        if (spans.isEmpty()) {
            spans.add(1);
        }
        else {
            int index = prices.size()-2;
            while (index >= 0 && price >= prices.get(index)) {
                index = index - spans.get(index);
            }
            spans.add(prices.size()-1-index);
        }
        return spans.get(spans.size()-1);
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */