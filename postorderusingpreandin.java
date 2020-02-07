import java.util.*; 
  
public class PrintPost {  
    static int preIndex = 0;  
    void printPost(int[] in, int[] pre, int inStrt, 
               int inEnd, HashMap<Integer, Integer> hm)  
    {  
        if (inStrt > inEnd)  
            return;   
        int inIndex = hm.get(pre[preIndex++]);   
        printPost(in, pre, inStrt, inIndex - 1, hm);   
        printPost(in, pre, inIndex + 1, inEnd, hm);   
        System.out.print(in[inIndex] + " ");  
    }  
  
    void printPostMain(int[] in, int[] pre)  
    { 
        int n = pre.length; 
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>(); 
        for (int i=0; i<n; i++) 
           hm.put(in[i], i); 
             
        printPost(in, pre, 0, n-1, hm); 
    } 
  
    // Driver code  
    public static void main(String ars[])  
    {  
        int in[] = { 4, 2, 5, 1, 3, 6 };  
        int pre[] = { 1, 2, 4, 5, 3, 6 };  
        PrintPost tree = new PrintPost();  
        tree.printPostMain(in, pre);  
    }  
}  