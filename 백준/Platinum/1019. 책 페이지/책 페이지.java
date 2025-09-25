import java.util.Scanner;

public class Main {
	public static void start_end(int _start,int _end, int[] arr,int _add) {
		
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		
		int[] number_count = new int[10];
		number_count[0] = 0;
		for(int i=1;i<10;i++) {
			number_count[i] = 0;
		}
		int add_number = 1;
		
		while(n !=0) {
			int end = n;
			boolean _go = false;
			while(true) {
				if(n%10 == 9||n < 1) {
					break;
				}
				n--;	
				_go = true;
			}
			if(_go) {
				for(int i= n+1;i<=end;i++) {
					int b = i;
					while(b != 0) {
						number_count[b%10] += add_number;
						b /= 10;
					}
				}
			}
			if(n < 9)
				break;
			
			n /= 10;
			for(int i=0;i<10;i++) {
				if(i==0) {
					number_count[i] += n*add_number;
				}
				else {
					number_count[i] += (n+1)*add_number;
				}
			}
			add_number *= 10;
		}
		
		for(int i=0;i<10;i++) {
			System.out.print(number_count[i] + " ");
		}
	}
}
