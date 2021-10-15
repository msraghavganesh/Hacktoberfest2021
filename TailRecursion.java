public class TailRecursion {

    public static void main(String[] args) {
        function(5);
        return;
    }

    public static int function(int n){
        if(n==0)
            return 0;
        else
            System.out.printf("%d ",n);
            return function(n-1);
    }


}
