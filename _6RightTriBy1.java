package core_java_assignment;

public class _6RightTriBy1 {
public static void main(String[] args) {
	
	int a = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i; j++) {
			System.out.print(a);
			a++;
		}
		System.out.println();
	}
}
}