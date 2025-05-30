class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int top=0;
        int left=0;
        int right = matrix[0].length-1;
        int bottom = matrix.length-1;
        while(left<=right && top<=bottom){
            for(int i=left; i<=right;i++){
                res.add(matrix[top][i]);
            }
            top+=1;
            for(int i=top; i<=bottom; i++){
                res.add(matrix[i][right]);
            }
            right-=1;
            if(!(left<=right && top<=bottom)){
                break;
            }
            for(int i=right;i>=left;i--){
                res.add(matrix[bottom][i]);
            }
            bottom-=1;
            for(int i=bottom; i>=top; i--){
                res.add(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
}