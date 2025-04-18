import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int A = sc.nextInt();
		int Y = sc.nextInt();

		if (d <= A && Y < d) {
			System.out.println("Winner");
		} else if (d <= Y && A < d) {
			System.out.println("Loser");
		} else {
			System.out.println("Draw");
		}

		sc.close();
	}
}
