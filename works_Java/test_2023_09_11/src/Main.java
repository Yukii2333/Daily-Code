import java.util.Random;
import java.util.Scanner;

// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        //二维数组存储n*n的数
        int[][] arr =new int[n][n];
        Random r = new Random();

        //记录最大最小值
        int max = 0;
        int min = 999;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                arr[i][j] = r.nextInt(900)+100;
                if(arr[i][j] > max){
                    max = arr[i][j];
                }
                if(arr[i][j]<min){
                    min = arr[i][j];
                }
                System.out.print(arr[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
        System.out.print("最大值：");
        System.out.println(max);
        System.out.print("最小值");
        System.out.println(min);
        }
    }