
import java.util.Stack;
import javafx.util.Pair;

class StockSpanner {
    private Stack<Pair<Integer,Integer>> priceStack;
    
    public StockSpanner() {
        priceStack = new Stack<Pair<Integer,Integer>>();
    }
    
    public int next(int price) {
        if ( priceStack.empty() ) {
            priceStack.add(new Pair<Integer, Integer>(price, 1));
            return 1;
        }
        else {
            int res = 1;
            while ( !priceStack.empty() ) {
                Pair<Integer, Integer> last = priceStack.peek();
                if ( last.getKey() > price )  {
                    break;
                }
                else {
                    priceStack.pop();
                    res += last.getValue();
                }
            }
            priceStack.push(new Pair<Integer, Integer>(price, res));
            return res;
        }
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */