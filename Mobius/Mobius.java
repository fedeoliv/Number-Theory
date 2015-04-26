import java.io.*;

/* 
 	mu(n) = 1 	if n is square-free, 	even number of prime factors
	mu(n) = -1 	if ...               odd  ...
	mu(n) = 0 	if n has a squared prime factor.
	
	mu(p^k) =  1 	if k = 0
 	mu(p^k) =  -1	if k = 1
	mu(p^k) =  0 	if k > 1.
	
	Input: 10
	
	Output:
	Prime Fator is 2
	Prime Fator is 5
	N is square-free (even number of prime factors) = 1
 */
class Mobius {
	static BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
	int n, a, p, c, q;

	public MobiusFn() {
		a = 2;
		p = 0;
		c = 0;
	}

	public int primefac(int x) {
		if (x == 1)
			return 1;
		while (x > 1) {
			c = 0;
			while (x % a == 0) {
				c++;
				p++;
				System.out.println("Prime Fator is " + a);
				x = x / a;
			}
			
			if (c > 1) return 0;
			a++;
		}
		
		q = (int) Math.pow(-1, p);
		return q;
	}

	public void display() {
		int r = primefac(n);
		if (r == 0) System.out.println("N has a squared prime factor = " + r);
		else if(r == -1) System.out.println("N is square-free (odd number of prime factors) = " + r);
		else if(r == 1) System.out.println("N is square-free (even number of prime factors) = " + r);
	}

	public static void main(String arg[]) throws IOException {
		MobiusFn obj = new MobiusFn();
		obj.n = Integer.parseInt(ob.readLine());
		obj.display();
	}
}
