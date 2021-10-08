import java.util.*;

public class toeplitz 
{
//toeplitz matrix- whose diagonals are same
/*
2   1   5
3   2   5
9   3   2
*/
    public static  boolean isToeplitzMatrix(int[][] matrix) 
    {
        
        for(int i=0;i<matrix.length-1;i++)  //matrix.length-1 hoga kyuki pehla element aur last element to weise bhi same rahenge
        {
            for(int j=0;j<matrix[0].length-1;j++)
            {
                    if(matrix[i][j]!=matrix[i-1][j-1])
                    {
                        return false;
                    }
            }
        }
        return true;
    }

    public static void main(String [] args)
    {
        Scanner scn =new Scanner(System.in);
        int m=scn.nextInt();
        int n=scn.nextInt();
        int [][]arr=new int[m][n];
        System.out.println("enter-\n");
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[0].length;j++)
            {
                arr[i][j]=scn.nextInt();
            }
        }
         System.out.println(isToeplitzMatrix(arr));   

    }
}



