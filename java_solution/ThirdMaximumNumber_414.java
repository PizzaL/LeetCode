import java.util.*;

class ThirdMaximumNumber_414 {
    public int findThird(Integer[] uniqueNums, int startp, int endp)
    {
        return 0;
    }

    public int thirdMax(int[] nums) {
        Set<Integer> numSet = new HashSet<Integer>();
        for (int num:nums)
        {
            numSet.add(num);
        }
        Integer[] uniqueNums = numSet.toArray(new Integer[numSet.size()]);
        return findThird(uniqueNums, 0, numSet.size()-1);
    }

    public static void main(String[] args)
    {

    }

}