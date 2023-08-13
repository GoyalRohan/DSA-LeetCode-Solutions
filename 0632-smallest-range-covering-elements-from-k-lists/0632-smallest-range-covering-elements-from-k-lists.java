class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
         int k = nums.size();
        PriorityQueue<int[]> pq = new PriorityQueue( new Comparator<int[]> () {
            @Override
            public int compare(int[] a, int [] b){
                return a[0]-b[0];
            }
        });
       
       int h = Integer.MIN_VALUE;
        for(int i = 0 ; i < k ; i++){
            pq.add(new int[]{nums.get(i).get(0),i,1});
             h = Math.max(h, nums.get(i).get(0));
        }
        int l = pq.peek()[0];
        int ans = l, len = h-l+1;
        while(!pq.isEmpty()){
            int[] temp = pq.poll();
            if(nums.get(temp[1]).size() <= temp[2]){
                break;
            }
            int a = nums.get(temp[1]).get(temp[2]);
            h = Math.max(a,h);
            pq.add(new int[]{a,temp[1],temp[2]+1});
            l = Math.max(l, pq.peek()[0]);
           
            if(h-l+1<len){
                len = h-l+1;
                ans = l;
            }

        }
        return new int[]{ans, ans+len-1};
    }
}