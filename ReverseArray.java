public class ReverseArray {

    public static void main(String[] args) {
        int a[] = {10,20,30,40};
        reverse(a,0,3);

        System.out.println("Reverse array : ");
        for(int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }

    static void reverse (int a[], int s, int e){
        if(s>=e){
            return;
        }

        int temp;
        temp=a[s];
        a[s]=a[e];
        a[e]=temp;

        reverse(a,s+1,e-1);
    }
}
