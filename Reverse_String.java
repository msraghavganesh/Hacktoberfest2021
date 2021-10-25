import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the word to be reversed: ");
        String ostr=sc.nextLine();
        String rstr="";
        char ch;
        for (int i=ostr.length()-1;i>=0;i--){
            ch=ostr.charAt(i);
            rstr=rstr+ch;
        }
        System.out.println("Original String was "+ostr+" and Reversed String is "+rstr);
    }
}
