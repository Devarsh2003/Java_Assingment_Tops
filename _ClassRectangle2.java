package core_java_assignment;

class Rectangle{
	int length;
	int breadth;
	
	public Rectangle(int l ,int b) {
		length = l;
		breadth = b;	
	}
	
	public void Area() {
		System.out.println("Area of rectangle : "+length*breadth);
	}
	
	public void Perimeter() {
		System.out.println(2*(length+breadth));
	}
	
	class Square extends Rectangle{
		
	}
}

public class _ClassRectangle2 {
public static void main(String[] args) {
	
}
}
