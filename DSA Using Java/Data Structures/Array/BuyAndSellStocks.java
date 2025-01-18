public class BuyAndSellStocks {
    /*
        You are given an array prices where prices[i] is the price of a given stock on its day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
     */

    public static int getMaxProfit(int[] prices){
        int buyPrice = Integer.MAX_VALUE;
        int sellPrice = 0;
        int maxProfit = 0;

        for (int i = 0; i < prices.length; i++){
            if(buyPrice < prices[i]){
                int profit = prices[i] - buyPrice;
                sellPrice = Math.max(sellPrice, prices[i]);
                maxProfit = Math.max(profit, maxProfit);
            } else {
                buyPrice = prices[i];
            }
        }

        System.out.println("Buying price = "+buyPrice);
        System.out.println("Shelling price = "+sellPrice);

        return maxProfit;
    }

    public static void main(String[] args) {
        int[] prices = {7, 2, 5, 3, 7, 12};
        System.out.println("Maximum Profit = "+getMaxProfit(prices));
    }
}
